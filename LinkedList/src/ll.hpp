#include <utility>
#include <cassert>
#include "ll.h"
#include <memory>

using namespace cs126linkedlist;

template<typename ElementType>
LinkedList<ElementType>::LinkedListNode::LinkedListNode(const ElementType &value, LinkedList* parentList) : value_(value), parentList(parentList) {}

template<typename ElementType>
LinkedList<ElementType>::LinkedList() : listSize_(0) {}

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
    
    listSize_ = values.size();
    
    if (listSize_ >= 1) {
        start_ = new LinkedListNode(values[0], this);
    }
    
    LinkedListNode* current = start_;

    for (int i = 1; i < listSize_; i++) {
        current->next_ = new LinkedListNode(values[i], this);
        if (i == listSize_ - 1) {
            last_ = current->next_;
        }
        current = current->next_;
    }

}

//// Copy constructor
//template<typename ElementType>
//LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
//
//    listSize_ = source.size();
//    start_->value_ = source.front();
//
//    LinkedListNode currentMyNode = start_;
//    LinkedListNode* currentSourceNode = source.front();
//    for (int i = 1; i < source.size(); i++) {
//        *(currentMyNode->next_) = *(currentSourceNode->next_);
//        *(currentMyNode->value_) = *(currentSourceNode->value_);
//
//    }
//
//    *last_ = *(source.back());
//
//}

// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {
    
    clear();

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
        start_ = new LinkedListNode(value, this);
        last_ = new LinkedListNode(value, this);
    } else {
        LinkedListNode* oldStart = start_;
        start_ = new LinkedListNode(value, this);
        start_->next_ = oldStart;
    }
    
    listSize_++;

}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
    
    if (empty()) {
        start_ = new LinkedListNode(value, this);
        last_ = new LinkedListNode(value, this);
    } else {
        LinkedListNode* oldLast = last_;
        last_ = new LinkedListNode(value, this);
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
        LinkedListNode* oldStart = start_;
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

template<typename ElementType>
void LinkedList<ElementType>::clear() {

    LinkedListNode* currentNode = start_;
    for (int i = 0; i < listSize_; i++) {
        LinkedListNode* nextNode = currentNode->next_;
        delete currentNode;
        currentNode = nextNode;
    }
    
    listSize_ = 0;

}

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
    
    current_ = current_->next_;
    return *this;

}

template<typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {
    
    return current_->value_;

}

template<typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator& other) const {
    return current_->value_ != other.current_->value_;
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
    return iterator(start_);
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
    return iterator(last_);
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator& LinkedList<ElementType>::const_iterator::operator++() {
    current_ = current_->next_;
    return *this;
}

template<typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
    return current_->value_;
}

template<typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator& other) const {
    return current_->value_ != other.current_->value_;
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
    return const_iterator(start_);
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
    return const_iterator(last_);
}
