//In-class coding exercise
#include <iostream>
#include <string>
using namespace std;

int main () {

    int input_number;
    string binString = "";

    cout << "Please enter a postive number" << endl;
    cin >> input_number;

    while (input_number != 0)
    {
        if (input_number%2 == 0)
        {
            binString = "0" + binString;
        }
        else
        {
            binString = "1" + binString;
        }

        input_number = input_number / 2;
    }
    
    cout << "Binary Form = " << binString << endl;

    return 0;
}
 
