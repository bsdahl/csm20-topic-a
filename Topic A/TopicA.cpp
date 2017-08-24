//
//  TopicA.cpp
//  Topic A
//
//  Created by user on 9/1/15.
//  Copyright (c) 2015 Ben Dahl. All rights reserved.
//
// STATUS: Working.
// Note: You will need to tell VS not to include LinkedList.cpp and Node.cpp
// Note: You will need to move Topic A Soundtrack List.txt into your executable directory

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "LinkedListValue.h"
#include "soundtrack.h"

using namespace std;

int main() {
    
    cout << "Create int LinkedListValue llv1 using default constructor\n" << endl;
    LinkedListValue<int> llv1;
    
    cout << "Insert items into llv1\n" << endl;
    llv1.insert(-34);
    llv1.insert(2);
    llv1.insert(17);
    llv1.insert(63);
    llv1.insert(225);
    llv1.insert(-2345);
    
    cout << "Display llv1:\n" << endl;
    llv1.display();
    
    
    cout << "Create Linked List ll1 which is a copy of llv1\n" << endl;
    LinkedList<int> ll1 = llv1;
    
    
    cout << "Display ll1:\n" << endl;
    ll1.display();
    
    
    cout << "Change the fifth value of ll1 to 2015\n" << endl;
    try {
        ll1.setEntry(5, 2015);
    }
    catch(PrecondViolatedExcep& error) {
        cerr << "ERROR: " << error.what() << endl;
    }
    
    
    cout << "Change the tenth value of ll1 to 2016" << endl;
    try {
        ll1.setEntry(10, 2016);
    }
    catch(PrecondViolatedExcep& error) {
        cerr << "ERROR: " << error.what() << endl;
    }
    
    
    cout << "\nCreate LinkedListValue llv2 which is a copy of llv1\n" << endl;
    LinkedListValue<int> llv2 = ll1;
    
    
    cout << "Display llv2:\n" << endl;
    llv2.display();
    
    cout << "Remove 63 from llv2\n" << endl;
    llv2.remove(63);
    
    
    cout << "Attempt to remove 63 from llv2 again\n" << endl;
    llv2.remove(63);
    
    
    cout << "Display llv2:\n" << endl;
    llv2.display();
    
    
    cout << "Create LinkedListValue llv3 from llv2\n" << endl;
    LinkedListValue<int> llv3 = llv2;
    
    
    cout << "Display llv3:\n" << endl;
    llv3.display();
    
    
    cout << "Assign llv3 the values from llv1\n" << endl;
    llv3 = llv1;
    
    cout << "Display llv3:\n" << endl;
    llv3.display();
    
    
    cout << "Create string LinkedListValue llv4 using default constructor\n" << endl;
    LinkedListValue<string> llv4;
    
    
    cout << "Insert items into llv4\n" << endl;
    llv4.insert("CS");
    llv4.insert("M");
    llv4.insert("20");
    llv4.insert("Data Structures");
    llv4.insert("Using");
    llv4.insert("C++");
    
    
    cout << "Display llv4:\n" << endl;
    llv4.display();
    
    
    cout << "Create llv5 from llv4\n" << endl;
    LinkedListValue<string> llv5 = llv4;
    
    cout << "Display llv5:\n" << endl;
    llv5.display();
    
    
    cout << "Delete \"Data\" from llv5\n" << endl;
    llv5.remove("Data");
    
    
    cout << "Delete \"Data Structures\" from llv5" << endl;
    llv5.remove("Data Structures");
    
    
    cout << "Display llv5:\n" << endl;
    llv5.display();
    
    
    cout << "Assign llv5 to llv4\n" << endl;
    llv4 = llv5;
    
    
    cout << "Display llv4:\n" << endl;
    llv4.display();
    
    
    cout << "Create soundtrack LinkedListValue llv6\n" << endl;
    cout << "Insert values from file\n" << endl;
    LinkedListValue<soundtrack> llv6;
    
    ifstream file("Topic A Soundtrack List.txt");
    while ( file.good() )
    {
        string composer;
        string title;
        string label;
        string catalogNum;
        string dateRec;
        string dateRel;
        
        getline ( file, composer, ',' );
        getline ( file, title, ',' );
        getline ( file, label, ',' );
        getline ( file, catalogNum, ',' );
        getline ( file, dateRec, ',' );
        getline ( file, dateRel, ',' );
        
        soundtrack* newTrack = new soundtrack(title, composer, label, catalogNum, dateRec, dateRel);
        llv6.insert(*newTrack);
    }
    
    file.close();
    
    
    cout << "Display llv6:\n" << endl;
    llv6.display();
    
    
    cout << "Create a new POINTER to a LinkedListValue pllv7, a copy of llv6\n" << endl;
    LinkedListValue<soundtrack>* pllv7 = new LinkedListValue<soundtrack>(llv6);
    
    
    cout << "Display llv7\n" << endl;
    pllv7->display();
    
    
    // I really wanted to do this with a conversion constructor, that would convert a string into a soundtrack object, so that I could write pllv7->remove("Henry V"), but I cannot find a way to do this. I tried explicitely creating the constructor, but the compiler wouldnt find it. I really wanted to maintain data independence and not tightly couple LinkedListValue to soundtrack.
    cout << "Delete \"Henry V\" from pllv7\n" << endl;
    soundtrack remove1("Henry V");
    pllv7->remove(remove1);
    
    
    cout << "Display llv7\n" << endl;
    pllv7->display();
    
    
    cout << "Delete \"Henry V\" AGAIN from pllv7\n" << endl;
    pllv7->remove(remove1);
    
    
    cout << "Display llv7\n" << endl;
    pllv7->display();
    
    
    cout << "Assign pllv7 to llv6\n" << endl;
    llv6 = (*pllv7);
    
    
    cout << "Display llv6:\n" << endl;
    llv6.display();
    
    cout << "Find the soundtrack recorded in 1947 in pllv7\n" << endl;
    soundtrack find1("","","","","1947");
    
    pllv7->find(find1);
    
    
    
    cout << endl << endl;
    
    // Press enter to end
    cout << "Press Enter to end --> ";
    cin.ignore();
    
    return 0;
}
