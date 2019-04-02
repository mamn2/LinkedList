//
//  LinkedListTest.cpp
//  LinkedList
//
//  Created by Mohamed Amn on 4/1/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ll.h"
#include <vector>

using namespace cs126linkedlist;

TEST_CASE("Linked List Constructor") {
    
    SECTION("Initialize with std::vector") {
        std::vector<int> exampleVector;
        exampleVector.push_back(4);
        exampleVector.push_back(7);
        exampleVector.push_back(9);
        LinkedList<int> linkedList(exampleVector);
        
        SECTION("Start node is correct") {
            CHECK(linkedList.front() == 4);
        }
        SECTION("End node is correct") {
            CHECK(linkedList.back() == 9);
        }
        SECTION("Middle node is correct") {
            
        }
    }
    
}

