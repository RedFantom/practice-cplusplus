/* Written by RedFantom to practice C++ skills
 * Copyright (C) RedFantom 2017
 * See docstring under includes for more information
*/
#include <iostream>
using namespace std;

/* Exercise to use command line arguments in C++ */


int main(int arg_count, char *args[]){
    cout << "The user passed this program " << arg_count << " arguments." << endl;
    for(int i = 0; i < arg_count; i++){
        cout << "Found the following argument: " << args[i] << endl;
    }
    return 0;
}

