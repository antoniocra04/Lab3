#include <iostream>
using namespace std;

template <typename Type>
bool ValidInput(Type& var, bool wrongInput = false)
{
    if (wrongInput)
    {
        cout << "\nPlease enter the correct menu item: ";
    }

    cin >> var;
    if (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        var = '\0';
        return true;
    }
    else
    {
        return false;
    }
}
