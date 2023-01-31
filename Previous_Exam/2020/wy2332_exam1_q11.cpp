#include <iostream>
using namespace std;

int main() {

    int user_input;
    cout << "Enter a integer: " << endl;
    cin >> user_input;

    for (int v = 1; v <= user_input * user_input; v++)
    {
        if (v % 2 != 0)
        {
            cout << "x";
        }
        else
        {
            cout << "o";
        }

        if (v % user_input == 0)
        {
            cout << endl;
        }
    

    return 0;
}