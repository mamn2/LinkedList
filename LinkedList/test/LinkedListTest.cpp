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
        std::vector<int> exampleVector { 4, 7, 9 };
        LinkedList<int> linkedList(exampleVector);
        
        SECTION("Start node is correct") {
            CHECK(linkedList.front() == 4);
        }
        SECTION("End node is correct") {
            CHECK(linkedList.back() == 9);
        }
        SECTION("Middle node is correct") {
            auto itr = linkedList.begin();
            CHECK(*(++itr) == 7);
        }
    }
    
    SECTION("Copy Constructor") {
        
        std::vector<double> exampleVec { 2.0, 3.0, 4.0 };
        LinkedList<double> exampleList(exampleVec);
        LinkedList<double> copiedList = LinkedList<double>(exampleList);
        
        SECTION("Changing value in original doesn't change copy") {
            exampleList.push_front(4.0);
            CHECK(exampleList != copiedList);
            exampleList.pop_front(); //removed for safety of other tests
        }
        
        SECTION("Changing value in copy doesn't change original") {
            copiedList.push_front(5);
            CHECK(exampleList != copiedList);
        }
        
    }
    
    SECTION("Move constructor") {
        
        std::vector<float> exampleVec { 3.2f, 4.6f, 8.3f, 9.2f };
        LinkedList<float> exampleList(exampleVec);
        LinkedList<float> movedList = std::move(exampleList);
        
        SECTION("Deletes example list") {
            CHECK(exampleList.size() == 0);
        }
        
        SECTION("Moves to moveList") {
            CHECK(movedList.back() == 9.2f);
        }
        
    }
    
}

TEST_CASE("Destructor") {
  
    std::vector<int> exampleVector { 1, 3, 8 };
    LinkedList<int>* linkedList = new LinkedList<int>(exampleVector);
    delete linkedList;
    
    CHECK(linkedList->empty());

}

TEST_CASE("LinkedList Operators") {
    
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

TEST_CASE("Push functions") {
    
    std::vector<short> newVec { 23, 18, 64 };
    LinkedList<short> myList(newVec);
    
    SECTION("Push front") {
        myList.push_front(4);
        CHECK(myList.front() == 4);
    }
    
    SECTION("Push back") {
        myList.push_back(8);
        CHECK(myList.back() == 8);
    }
    
}

TEST_CASE("Pop/remove functions") {
    
    std::vector<bool> newVec { true, false, true };
    LinkedList<bool> myList(newVec);
    
    SECTION("Pop front") {
        myList.pop_front();
        CHECK(myList.front() == false);
        //Brings back value for safety of other tests
        myList.push_front(true);
        
        SECTION("Handles empty list") {
            for (int i = 0; i <= myList.size(); i++) {
                myList.pop_front();
            }
        }
    }
    
    SECTION("Pop back") {
        myList.pop_back();
        CHECK(myList.back() == false);
        //Brings back value for safety of other tests
        myList.push_back(true);
        
        SECTION("Handles empty list") {
            for (int i = 0; i <= myList.size(); i++) {
                myList.pop_front();
            }
        }
    }
    
    SECTION("Remove Nth") {
        myList.RemoveNth(1);
        CHECK(myList.size() == 2);
        
        SECTION("Handles bad n") {
            myList.RemoveNth(9);
        }
    }
    
    SECTION("Removes odd indices") {
        std::vector<int> myVec { 0, 1, 2, 3, 4 };
        LinkedList<int> myList(myVec);
        
        myList.RemoveOdd();
        SECTION("Front value is correct") {
            CHECK(myList.front() == 0);
        }
        
        SECTION("Back value is correct") {
            CHECK(myList.back() == 4);
        }
        
        SECTION("Size updated") {
            CHECK(myList.size() == 3);
        }
    }
    
}

