#include <iostream>
#include <cstring>
#include "postfixGenerator.h"
#include "myStack.h"

using namespace std;


postfixGenerator::postfixGenerator()
{
    //Setting infix and postfix strings to empty expressions.
    infix = "";
    postfix = "";
}

void postfixGenerator::getInfix(string x)
{
    //For class objects to work with multiple expressions,
    //every time we get a new infix expression we set postfix
    //back to an empty expression.
    infix = x;
    postfix = "";
}

string postfixGenerator::showInfix()
{
    return infix; //Returns our infix expression.
}

string postfixGenerator::showPostfix()
{
    convertToPostfix(); //To get a postfix string before returning it.

    return postfix;
}

void postfixGenerator::convertToPostfix()
{

    //NOTE: In the comments, there might be an "a.", or "b.",
    //or "b.1." or something to that effect. These are the points hit
    //for the programming challenge according to Prog. challenge # 9
    //of chapter 7 of the Data Structures Book, pg. 449


    //a. Initialize stack
    myStack<string> postfixStack; //Stack holding operators.
    bool onlyLeftParenth; //Used for 2 cases involving parenthesis

    string sym; //To hold the operator or operand we're currently looking at.


    for(int i = 0; i< infix.size(); i++)
    {
        //b. Get the symbol, sym from infix.

        sym = infix[i]; //sym will hold the ith character of
                        //the infix string.

        if(sym != "+" && sym != "-" && sym != "/"
           && sym != "*" && sym != "(" && sym != ")") //b.1. If sym is an operand.
        {
            postfix.append(sym); //Put operands in the postfix string.

        }
        if(sym == "(") // b.2. If sym is "("
        {
            postfixStack.push(sym); //push sym into the stack.
        }
        if( sym == ")") //b.3. If sym is ")"
        {
            onlyLeftParenth = false;
            if(!postfixStack.isEmptyStack())
            {
                //Pop and append all the symbols from the stack until the MOST
                //RECENT left parenthesis, "(". Meaning at the end of this, the stack could
                //still hold multiple "(" parentheses.
                while(!postfixStack.isEmptyStack() &&  onlyLeftParenth == false)
                {
                    if(postfixStack.top() != "(") //popping and appending until we hit a "("
                    {
                        postfix.append(postfixStack.top());
                        postfixStack.pop();
                    }
                    else //We've reahed a "("
                    {
                        postfixStack.pop(); //Pop the instance of "(" out.
                        onlyLeftParenth = true; //We've popped and appended everything
                                                //within a single "(  )" in the expression.
                    }
                }
            }

        }

        if(sym == "+" || sym == "-" || sym == "*" || sym == "/") //b.4. If sym is an operator
        {
            //b.4.1. pop and append all the operators that are above the most recent "(" AND have
            //precedence greater than or = to sym.
            onlyLeftParenth = false;
            if(!postfixStack.isEmptyStack()) //I'm not sure if I need this if statement.
            {
                //We pop until the stack is empty or until we've reached a "("
                while(!postfixStack.isEmptyStack() && onlyLeftParenth == false)
                {

                    if( postfixStack.top()!= "(")
                    {
                        //+ and - are the lowest end precedence
                        if(sym == "+" || sym ==  "-")
                        {
                            postfix.append(postfixStack.top());
                            postfixStack.pop();

                        }
                        else if(sym == "*" || sym == "/")
                        {
                            //If the next thing in the stack has greater or equal precedence to sym.
                            if(postfixStack.top() == "*" || postfixStack.top() == "/" )
                            {
                                postfix.append(postfixStack.top());
                                postfixStack.pop();
                            }
                            else
                            {
                                //This variable name might be misleading. What's actually happening
                                //is if we have a + or - at the top of the stack, then that is
                                //lower precedence than sym's * or /. SO, since we're only supposed
                                //to pop and append things that have GREATER or EQUAL precedence to
                                //sym until the left parenthesis, we're done here.
                                onlyLeftParenth = true;
                            }
                        }

                    }
                    else
                    {
                        //We've hit an instance of "('
                        onlyLeftParenth = true;
                    }
                }
            }
            //b.4.2.
            //Since we've popped and appended everything we need to,
            //we can now push whatever operator sym is into the stack.
            postfixStack.push(sym); //push sym into the stack.
        }
    }

    //c.
    //After processing infix, some operators might be left in the stack.
    //Pop and append to postfix string everything from the stack.
    while(!postfixStack.isEmptyStack())
    {
        postfix.append(postfixStack.top());
        postfixStack.pop();
    }


}
postfixGenerator::~postfixGenerator()
{
    //dtor
}
