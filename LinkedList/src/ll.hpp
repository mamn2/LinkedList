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
    start_ = source.front();
    last_ = source.back();

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
    
    LinkedListNode* oldStart = start_;
    start_ = new LinkedListNode(value);
    start_->next_ = oldStart;

}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
    
    LinkedListNode* oldLast = last_;
    last_ = new LinkedListNode(value);
    oldLast->next_ = last_;

}

template<typename ElementType>
ElementType LinkedList<ElementType>::front() const{
    
    return start_->value_;

}

template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {
    
    return last_->value_;

}

template<typename ElementType>
void LinkedList<ElementType>::pop_front() {

}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {

}

template<typename ElementType>
int LinkedList<ElementType>::size() const {

}

template<typename ElementType>
bool LinkedList<ElementType>::empty() const {

}

template<typename ElementType>
void LinkedList<ElementType>::clear() {

}

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {

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
