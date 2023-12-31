#include <iostream>
using namespace std;

template <typename Type>
Type ValidInput()
{
    Type variable;
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter correct value: ";
        cin >> variable;
    }
    return variable;
}