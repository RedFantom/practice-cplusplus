#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/* Exercise to let the user choose a start, end, step and type value and 
 * print a list of all Fahrenheit/Celsius temperatures in range accordingly
 *
 * Task found here: http://www.cprogramming.com/challenges/celsius_converter_table.html
*/


int retrieve_value(string prompt){
	cout << prompt << ": ";
	int value;
	cin >> value;
	if (cin.fail()){
		value = retrieve_value(prompt);
	}
	return value;
}

char retrieve_type(string prompt){
	cout << prompt << ": ";
	char value;
	cin >> value;
	if (cin.fail()){
		value = retrieve_type(prompt);
	}
	return value;
}


float round(float f){
	return floor(f + 0.5);
}


int celsius_to_fahrenheit(int celcius){
	int fahrenheit;
	fahrenheit = round(celcius * 1.8 + 32);
	return fahrenheit;
}

int fahrenheit_to_celsius(int fahrenheit){
	int celsius;
	celsius = round((fahrenheit - 32) / 1.8);
	return celsius;
}

void print_temperatures(int celsius, int fahrenheit){
	cout << left << setw(15) << "Celsius: " << right << setw(5) << celsius << endl;
	cout << left << setw(15) << "Fahrenheit: " << right << setw(5) << fahrenheit << endl;
}


int main(){
	int fahrenheit;
	int celsius;
	int start;
	int end;
	int step;
	char type;
	start = retrieve_value("Please enter the start temperature");
	end = retrieve_value("Please enter the end temperature");
	step = retrieve_value("Please enter the step temperature");
	type = retrieve_type("Please enter the temperature type");
	if(type == 'f'){
		type = 'F';
	}else if(type == 'c'){
		type = 'C';
	}else if (type != 'F' && type != 'C'){
		cout << "Invalid type. Please enter C or F." << endl;
		return -1;
	}
	if(end < start){
		cout << "Start value is larger than end value" << endl;
		return -1;	
	}else if(step > (end - start)){
		cout << "Step value is larger than the difference between start and end" << endl;
		return -1;		
	}
	for (int i = start; i < end; i += step){
		if(type == 'F'){
			fahrenheit = i;
			celsius = fahrenheit_to_celsius(fahrenheit);
		}else{
			celsius = i;
			fahrenheit = celsius_to_fahrenheit(celsius);
		}
		cout << "Temperate in range found: " << endl;
		print_temperatures(celsius, fahrenheit);
	}
	return 0;
}
