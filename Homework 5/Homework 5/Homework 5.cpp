
#include <fstream>
#include <iostream>
#include <string>
#include "BigInt.hpp"
#include <iomanip>


bool Rerun();
void CheerfulMessage();

using namespace std;

int main()
{
    int UserInput = 0;
    BigInt var;
    cout << "Press enter to start the program" << endl;

    
    do
    {
     //The loop is just generic code that checks userinput to ensure that its in range and that
    //The value is an int

        while (1)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter a number:";

            if (!(cin >> UserInput)) continue;
            if (UserInput < 0 || UserInput >500) continue;
            break;

        }
      

        if (UserInput == 0) {
            cout << 1 << endl;
            // This is not printing to file whatever

        }
        else
        {
            for (int i = UserInput; i > 0; i--) {
                var.multiply(i);
            }

            try {
                cout << var;
            }
            catch (const char * e)
            {
                cout << e << endl;
            }
            catch (...)
            {
                cout << "Something bad happened" << endl;
            }

            var.Reset();

        }

    } while ( Rerun() == true);

    CheerfulMessage();

    return 0;
}

bool Rerun()
{
    bool sentinel = false;
    int choice = 0; 

    cout << "Enter -1 to leave the program" << endl;
    cin >> choice;

    if (choice == -1) return false;

    return true;

}

void CheerfulMessage()
{
    cout << "Have a great day, Devyn is taking my job im cooked" << endl;
}
