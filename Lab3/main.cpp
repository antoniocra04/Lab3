#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"
#include "StackQueue.h"
#include "ValidInput.h"

using namespace std;

template<typename Type>
char MainController()
{
    Type item;
    return item.MenuController();
}

int main() {
    char mode = '\0';
    char wrongInput = false;
    const char* MENU_MESSAGE = "Choose structure: \n1 - Stack \n2 - Ring buffer \n3 - Ring Queue \n4 - Stack Queue \nq - Quit \nYour choice: ";
    cout << MENU_MESSAGE;
    while (mode != 'q')
    {
        wrongInput = ValidInput(mode, wrongInput);
        system("cls");
        switch (mode)
        {
        case '1':
            mode = MainController<Stack>();
            break;
        case '2':
            mode = MainController<RingBuffer>();
            break;
        case '3':
            mode = MainController<RingBufferQueue>();
            break;
        case '4':
            mode = MainController<StackQueue>();
            break;
        default:
            wrongInput = true;
            break;
        }
        cout << MENU_MESSAGE;
    }
    system("cls");
    return 0;
}