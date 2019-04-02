#include <utility>
#include <cassert>
#include "ll.h"

using namespace cs126linkedlist;

template<typename ElementType>
LinkedList<ElementType>::LinkedListNode::LinkedListNode(const ElementType &value) : value_(value) {}

template<typename ElementType>
LinkedList<ElementType>::LinkedListNode::~LinkedListNode() {
    delete next_;
}

template<typename ElementType>
LinkedList<ElementType>::LinkedList() {}

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
    
    listSize_ = values.size();
    
    if (listSize_ >= 1) {
        start_ = new LinkedListNode(values[0]);
    }
    
    LinkedListNode* current = start_;

    for (int i = 1; i < listSize_; i++) {
        current->next_ = new LinkedListNode(values[i]);
        if (i == listSize_ - 1) {
            last_ = current->next_;
        }
        current = current->next_;
    }

}

// Copy constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
    
    listSize_ = source.size();
    *(start_) = *(source.front());
    
    LinkedListNode currentMyNode = start_;
    LinkedListNode* currentSourceNode = source.front();
    for (int i = 1; i < source.size(); i++) {
        *(currentMyNode->next_) = *(currentSourceNode->next_);
        *(currentMyNode->value_) = *(currentSourceNode->value_);
        
    }
    
    *(last_) = *(source.back());

}

// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {
    
    //Recursively deletes all Nodes
    delete start_;

}

// Copy assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (const LinkedList<ElementType>& source) {
    return LinkedList(source);
}

// Move assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (LinkedList<ElementType>&& source) noexcept {

}

template<typename ElementType>
void LinkedList<ElementType>::push_front(ElementType value) {
    
    if (empty()) {
        start_ = new LinkedListNode(value);
        last_ = new LinkedListNode(value);
    } else {
        LinkedListNode* oldStart = start_;
        start_ = new LinkedListNode(value);
        start_->next_ = oldStart;
    }
    
    listSize_++;

}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
    
    if (empty()) {
        start_ = new LinkedListNode(value);
        last_ = new LinkedListNode(value);
    } else {
        LinkedListNode* oldLast = last_;
        last_ = new LinkedListNode(value);
        oldLast->next_ = last_;
    }
    
    listSize_++;

}

template<typename ElementType>
ElementType LinkedList<ElementType>::front() const{
    
    if (!empty()) {
        return start_->value_;
    } else {
        std::string errorMessage("Can't retrieve front value because list is empty");
        throw std::out_of_range(errorMessage);
    }

}

template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {
    
    if (!empty()) {
        return last_->value_;
    } else {
        std::string errorMessage("Can't retrieve back value because list is empty");
        throw std::out_of_range(errorMessage);
    }

}

template<typename ElementType>
void LinkedList<ElementType>::pop_front() {
    
    if (!empty()) {
        LinkedListNode oldStart = start_;
        start_ = start_->next_;
        delete oldStart;
        listSize_--;
    }

}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {
    
    if (!empty()) {
        
        LinkedListNode* current = start_;
        for (int i = 1; i < listSize_ - 1; i++) {
            current = current->next_;
        }
        
        LinkedListNode* oldEnd = current->next_;
        current->next = nullptr;
        delete oldEnd;
        
    }

}

template<typename ElementType>
int LinkedList<ElementType>::size() const {
    
    return listSize_;

}

template<typename ElementType>
bool LinkedList<ElementType>::empty() const {
    
    if (listSize_ == 0) {
        return true;
    } else {
        return false;
    }

}

//template<typename ElementType>
//void LinkedList<ElementType>::clear() {
//
//    //recursively deletes everything?
//    delete start_;
//
//}

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {
//First make the iterator

}

template<typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {

}

template<typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {

}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {

}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {

}

template<typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::operator++() {

}

template<typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {

}

template<typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator& other) const {

}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {

}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {

}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator& LinkedList<ElementType>::const_iterator::operator++() {

}

template<typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {

}

template<typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator& other) const {

}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {

}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {

}
