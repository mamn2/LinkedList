//
//  main.cpp
//  LinkedList
//
//  Created by Mohamed Amn on 3/31/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include <iostream>
#include "ll.h"

int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(8);
    
    cs126linkedlist::LinkedList<int> list(vec);
    int x = 3;
    
    return 0;
}
