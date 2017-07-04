/* Written by RedFantom to practice C++ skills
 * Copyright (C) RedFantom 2017
 * See docstring under includes for more information
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

/* Exercise to create program that counts amount of lines in a file and prints
 * the result.
 *
 * Task found here: http://www.cprogramming.com/challenges/count.html
*/


string get_filename(){
    cout << "Please enter the filename: ";
    string value;
    cin >> value;
    if(cin.fail()){
        cout << "That is not a valid `string` value. Please try again." << endl;
        value = get_filename();
    }else if(cin.eof()){
        cout << "End of file in input stream. Choosing an empty string." << endl;
        return "";
    }
    return value;
}


int count_lines(string file_name){
    int amount = 0;
    cout << "Opening file to count lines in file." << endl;
    string line;
    ifstream file(file_name.c_str());
    while(getline(file, line)){
        amount++;
    }
    return amount;
}



int main(){
    string file_name;
    file_name = get_filename();
    cout << "Amount of lines in this file: " << count_lines(file_name) << endl;
    return 0;
}
