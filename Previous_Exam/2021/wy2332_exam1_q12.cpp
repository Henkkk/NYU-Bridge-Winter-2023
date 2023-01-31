#include <iostream>
using namespace std;

int main() {

    double user_input = 0, day = 1, sum_travlled = 0;
    int sum_yard, sum_feet, sum_inche;

    while (user_input != -1)
    {
        cout << "Enter the number of inches the snail traveled in day #" << day << ", or type -1 if they reached their destination:" << endl;
        cin >> user_input;

        if (user_input != -1) //ONLY SUM THE USER INPUT WHEN IT IS NOT EQUAL -1
        {
            sum_travlled += user_input;
            day++;
        }

    }

    //DO CONVERSION
    sum_yard = (sum_travlled / 12) / 3;
    sum_feet = (sum_travlled - (sum_yard * 3 * 12)) /12 ;
    sum_inche = sum_travlled - (sum_yard * 3 * 12) - (sum_feet * 12);

    cout << "In " << day - 1  << " days, the snail traveled " << sum_yard << " yards, " << sum_feet << " feet and " << sum_inche << " inches.";


    return 0;
}