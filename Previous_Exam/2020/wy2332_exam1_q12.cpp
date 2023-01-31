#include <iostream>
#include <string>
using namespace std;

int main() {

    int user_input, more_even_number = 0;
    string str_input;
    cout << "Please enter a sequence of positive integers, each one on a separate line. End your sequence by typing -1 " << endl;

    do
    {
        int even_count = 0, odd_count = 0;

        cin >> user_input;
        
        if (user_input == -1)
        {
            break; //immediate break the while loop when user input -1
        }

        str_input = to_string(user_input);

        for (int i = 0; i < str_input.size(); i++)
        {
            if ((int)str_input[i] % 2 == 0)
            {
                even_count++;
            }
            else
            {
                odd_count++;
            }
        }

        if (even_count > odd_count)
        {
            more_even_number++;
        }

    } while (user_input != -1);

    cout << "You entered " << more_even_number << " more-even numbers";
    
    return 0;
}