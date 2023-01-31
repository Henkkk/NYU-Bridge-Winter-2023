#include <iostream>
using namespace std;

int main() {

    int number_of_line;
    char user_input;
    cout << "Please enter a lower-case letter" << endl;
    cin >> user_input;

    number_of_line = ((int) user_input) - 96;

    for (int i = 0; i < number_of_line; i++)
    {
        for (int v = number_of_line -1 ; v > i; v--)
        {
            cout << " ";
        }

        for (int k = 0; k < i * 2 + 1; k++)
        {
            if (i % 2 == 0)
            {
                cout << (char) (97 + i); //ASCII 97 is a
            }
            else
            {
                cout << (char) (97 + i - 32); //ASCII 65 is A
            }
        }
        cout << endl;
    }
    
    return 0;
}