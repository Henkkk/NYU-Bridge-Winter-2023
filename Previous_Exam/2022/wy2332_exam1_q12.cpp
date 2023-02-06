#include <iostream>
using namespace std;

int main() {

    int user_input;
    cout << "Please enter a postive integer: " << endl;
    cin >> user_input;

    for (int i = 0; i < user_input * 2 ; i++)
    {
        cout << "*";
    }

    cout << endl;

    for (int n = 0; n < user_input; n++)
    {
        for (int a = 0; a < n + 1; a++)
        {
            cout << "*";
        }

        for (int b = user_input * 2 - 2; b > n * 2; b --)
        {
            cout << " ";
        }

        for (int a = 0; a < n + 1; a++)
        {
            cout << "*";
        }

        cout << endl;
    }

    for (int n = 1; n < user_input; n++)
    {
        for (int a = user_input; a > n; a--)
        {
            cout << "*";
        }

        for (int b = 0; b < n * 2; b++)
        {
            cout << " ";
        }

        for (int a = user_input; a > n; a--)
        {
            cout << "*";
        }


        cout << endl;
    }

    for (int i = 0; i < user_input * 2; i++)
    {
        cout << "*";
    }


    return 0;
}

