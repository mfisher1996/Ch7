//
//  Library.cpp
//  Wk9
//
//  Created by Mason Fisher on 10/30/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//
#include "Validation.h"
#include "ch7.h"
using namespace std;

int main(){
    stackType<int> timeList;
    stackType<string> personList;
    Validation check;
    check.out("Welcome to the Library!");
    check.out("Please input the visitors to the library and input -99 to finish.");
    string visit;
    int time = 0;
    int i = 1;
    while(visit != "-99"){
        check.out("Visitor "+to_string(i)+":");
        visit = check.word();
        if(visit != "-99"){
            check.out("How long did they stay?");
            time = check.numb(time, 1, 99);
            personList.push(visit);
            timeList.push(time);
        }
        i++;
    }
    
    check.out("The visitors came to the library in this order:");
    personList.print();
    
    check.out("The average length of time spent in the library was: ",'x');
    cout << setprecision(4) << timeList.avg()<<endl;
    check.out("minutes.");
    check.out("The max length of time spent in the library was: "+to_string(timeList.max())+"minutes.");
    
    return 0;
}
