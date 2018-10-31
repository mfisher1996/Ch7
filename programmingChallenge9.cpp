#include <iostream>
#include "postfixGenerator.h"
#include "postfixGenerator.cpp"
using namespace std;

int main()
{
    postfixGenerator postfixConvert;

    string infix = "A+B-C";
    postfixConvert.getInfix(infix);
    cout<< "Infix Expression: " << postfixConvert.showInfix();
    cout<< endl;
    cout<< "Postfix Expression: " << postfixConvert.showPostfix();

    cout << endl << endl;

    infix = "(A + B) * C";
    postfixConvert.getInfix(infix);
    cout<< "Infix Expression: " << postfixConvert.showInfix();
    cout<< endl;
    cout<< "Postfix Expression: " << postfixConvert.showPostfix();


    cout << endl << endl;

    infix = "(A + B) * (C - D)";
    postfixConvert.getInfix(infix);
    cout<< "Infix Expression: " << postfixConvert.showInfix();
    cout<< endl;
    cout<< "Postfix Expression: " << postfixConvert.showPostfix();



    cout << endl << endl;

    infix = "A + ((B + C) * (E - F) - G) / (H - I)";
    postfixConvert.getInfix(infix);
    cout<< "Infix Expression: " << postfixConvert.showInfix();
    cout<< endl;
    cout<< "Postfix Expression: " << postfixConvert.showPostfix();


    cout << endl << endl;

    infix = "A + B * (C + D ) - E / F * G + H";
    postfixConvert.getInfix(infix);
    cout<< "Infix Expression: " << postfixConvert.showInfix();
    cout<< endl;
    cout<< "Postfix Expression: " << postfixConvert.showPostfix() << endl << endl << endl;


    return 0;
}
