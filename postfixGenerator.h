#ifndef POSTFIXGENERATOR_H
#define POSTFIXGENERATOR_H

#include "myStack.h"
using namespace std;


class postfixGenerator
{
    public:
        postfixGenerator();
        void getInfix(string x);
        string showInfix();
        string showPostfix();
        ~postfixGenerator();

    private:
        void convertToPostfix();

        string infix;
        string postfix;
};

#endif // POSTFIXGENERATOR_H
