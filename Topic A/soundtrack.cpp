//
//  soundtrack.cpp
//  Topic A
//
//  Created by user on 9/1/15.
//  Copyright (c) 2015 Ben Dahl. All rights reserved.
//

#include "soundtrack.h"

istream& operator>>(istream& input, soundtrack & arg)
{
    input >> arg.composer;
    input >> arg.title;
    input >> arg.label;
    input >> arg.catalogNum;
    input >> arg.dateRec;
    input >> arg.dateRel;
    
    return input;
}

ostream& operator<<(ostream& output, const soundtrack & arg)
{
    output << arg.composer << "  ";
    output << arg.title << "  ";
    output << arg.label << "  ";
    output << arg.catalogNum << "  ";
    output << arg.dateRec << "  ";
    output << arg.dateRel << "  ";
    return output;
}

soundtrack::soundtrack(string title, string composer, string label, string catalogNum, string dateRec, string dateRel) : composer(composer), title(title), label(label), catalogNum(catalogNum), dateRec(dateRec), dateRel(dateRel)
{
    
}

bool soundtrack::operator==(const soundtrack& track)
{
    if (track.title == this->title) {
        return true;
    } else if (track.dateRec == this->dateRec) {
        return true;
    } else {
        return false;
    }
    
}