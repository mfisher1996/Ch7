//
//  decToBin.cpp
//  Wk9
//
//  Created by Mason Fisher on 10/30/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#include "ch7.h"
#include "Validation.h"

using namespace std;

int main(){
    stackType<int> binary;
    Validation check;
    check.out("Input a number to be converted into binary.");
    int num = check.numb(num), num2= num;
    while(num != 0){
        binary.push(num%2);
        num = num/2;
    }
    check.out(to_string(num2)+" converted to binary is: ", 'x');
    while(!binary.isEmptyStack()){
        cout << binary.top();
        binary.pop();
    }
    
    return 0;
}
