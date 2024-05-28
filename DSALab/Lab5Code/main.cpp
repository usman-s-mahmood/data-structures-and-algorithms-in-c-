#include "ExpressionConverter.h"

int main() 
{
    ExpressionConverter converter;

    int choice;
    string infix, result;
    
    do {
        cout << "1. Convert infix expression to prefix" << endl;
        cout << "2. Convert infix expression to postfix" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                result = converter.convertToPrefix(infix);
                cout << "Prefix expression: " << result << endl;
                break;
            case 2:
                cout << "Enter infix expression: ";
                cin >> infix;
                result = converter.convertToPostfix(infix);
                cout << "Postfix expression: " << result << endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}