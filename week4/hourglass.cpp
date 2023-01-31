//In-class coding exercise
#include <iostream>
using namespace std;

/*
example, n = 4, then size = 2n - 1

*******
 *****
  ***
   *
  ***
 *****
*******

*/

int main() {

    int user_input;
    cout << "Enter a integer: " << endl;
    cin >> user_input;

    //UPPER PART
    for (int i = 0; i < user_input; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int k = 2 * user_input - 1; k > 2 * i; k--)
        {
            cout << "*";
        }
        cout << endl;
    }

    //LOWER PART
    for (int v = 1; v < user_input; v++)
    {
        for (int a = user_input - 1; a > v; a--)
        {
            cout << " ";
        }

        for (int b = 0; b < 2 * v + 1; b++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
