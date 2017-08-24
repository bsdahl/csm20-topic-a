//
//  soundtrack.h
//  Topic A
//
//  Created by user on 9/1/15.
//  Copyright (c) 2015 Ben Dahl. All rights reserved.
//

#ifndef __Topic_A__soundtrack__
#define __Topic_A__soundtrack__

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class soundtrack {
    friend std::istream& operator>>(std::istream &, soundtrack &);
    friend std::ostream& operator<<(std::ostream &, const soundtrack &);
    
private:
    string composer;
    string title;
    string label;
    string catalogNum;
    string dateRec;
    string dateRel;
    
public:
    soundtrack(string title = "", string composer = "", string label = "", string catalogNum = "", string dateRec = "", string dateRel = "");
    bool operator==(const soundtrack& track);

};

#endif /* defined(__Topic_A__soundtrack__) */
