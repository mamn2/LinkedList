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
#include <string>
#include <sstream>

using namespace cs126linkedlist;

TEST_CASE("Linked List Constructor") {
    
    SECTION("Initialize Empty List") {
        LinkedList<std::string> linkedList;
        CHECK(linkedList.empty());
    }
    
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
    
    SECTION("Copy Constructor") {
        
        
        
    }
    
}

TEST_CASE("Destructor") {
  
    std::vector<int> exampleVector;
    exampleVector.push_back(1);
    exampleVector.push_back(3);
    exampleVector.push_back(8);
    LinkedList<int>* linkedList = new LinkedList<int>(exampleVector);
    delete linkedList;
    
    CHECK(linkedList->empty());

}

TEST_CASE("Operators") {
    
    std::vector<char> exampleVector { 'c', 's', '1', '2', '6' };
    std::vector<char> otherVector { 'c', 's', '1', '2', '6' };
    
    LinkedList<char> exampleList(exampleVector);
    LinkedList<char> otherExampleList(exampleVector);
    
    SECTION("Equality Operator") {
        CHECK(exampleList == otherExampleList);
    }
    
    SECTION("Inequality Operator") {
        CHECK(!(exampleList != otherExampleList));
    }
    
    SECTION("ostream operator") {
        std::stringstream stringstream;
        stringstream << exampleList;
        std::string printStream = stringstream.str();
        CHECK(printStream == "c  s  1  2  6  ");
    }
    
}

TEST_CASE("Iterator") {
    
    SECTION("Non-const iterator") {
    
        std::vector<std::string> stringVec { "summer", "plz", "arrive", "faster" };
        LinkedList<std::string>* linkedList = new LinkedList<std::string>(stringVec);

        LinkedList<std::string>::iterator itr = linkedList->begin();

        SECTION("Returns first value") {
            CHECK(*itr == "summer");
        }

        SECTION("Iterates to middle values") {
            ++itr;
            ++itr;
            CHECK(*itr == "arrive");
        }

        SECTION("Not equals operator") {
            CHECK(linkedList->begin() != linkedList->end());
        }

        SECTION("Ability to change values") {
            *linkedList->begin() = "changed value";
            CHECK(*linkedList->begin() == "changed value");
        }
        
    }
    
    SECTION("Const iterator") {
        
        const std::vector<std::string> stringVec { "summer", "plz", "arrive", "faster" };
        const LinkedList<std::string>* linkedList = new LinkedList<std::string>(stringVec);
        
        LinkedList<std::string>::const_iterator itr = linkedList->begin();
        
        SECTION("Returns first value") {
            CHECK(*itr == "summer");
        }
        
        SECTION("Iterates to middle values") {
            ++itr;
            ++itr;
            CHECK(*itr == "arrive");
        }
        
        SECTION("Not equals operator") {
            CHECK(linkedList->begin() != linkedList->end());
        }
        
    }
    
}

