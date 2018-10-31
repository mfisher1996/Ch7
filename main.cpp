//
//  main.cpp
//  Wk9
//
//  Created by Mason Fisher on 10/23/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#include <iostream>
#include "ch7.h"
using namespace std;

bool isGrouped();

int main(int argc, const char * argv[]) {
    if(isGrouped())
        cout << "This string is properly grouped."<<endl;
    else
        cout << "This string is not properly grouped."<<endl;
    return 0;
}

bool isGrouped(){
    stackType<char> stack;
    string str;
    cout << "Please input a string for testing.\n";
    cin >> str;
    int i=0;
    while(i!=str.size())
    {
        switch (str[i]){
    case'{':
        stack.push('}');
        i++;
        break;
    case'[':
          stack.push(']');
          i++;
          break;
          
    case'(':
          stack.push(')');
          i++;
          break;
    case'<':
          stack.push('>');
          i++;
          break;
          
    case'}':
    case']':
    case')':
    case'>':
        if (stack.top() != str[i])
            return false;
        else
            stack.pop();
        i++;
        break;
    default:
        i++;
        }
        
    }
        if(!stack.isEmptyStack())
            return false;
        return true;
}
