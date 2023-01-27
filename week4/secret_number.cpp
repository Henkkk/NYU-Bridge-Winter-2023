#include <iostream>
#include <time.h>
using namespace std;

int main () {

    int secretNumber;
    srand (time(NULL));
    secretNumber = rand() % 20 + 1;

    int userGuess;

    cout << "Guess a number" << endl;
    cin >> userGuess;

    while (userGuess != secretNumber)
    {
        if (userGuess > secretNumber)
        {
            cout << "Your guessed number is greater than secret number" << endl;
        }
        else if (userGuess < secretNumber)
        {
            cout << "Your guessed number is smaller than secret number" << endl;
        }

        cout << "Guess a number" << endl;
        cin >> userGuess;
    }

    cout << "Congrats!" <<endl;

    return 0;
}
 