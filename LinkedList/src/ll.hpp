#include <utility>
#include <cassert>
#include "ll.h"
#include <memory>

using namespace cs126linkedlist;

template<typename ElementType>
LinkedList<ElementType>::LinkedListNode::LinkedListNode(const ElementType &value) : value_(value) {}

template<typename ElementType>
LinkedList<ElementType>::LinkedList() : listSize_(0) {}

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

    std::vector<ElementType> listAsVec;
    for (auto itr = source.begin(); itr != source.end(); ++itr) {
        listAsVec.push_back(*itr);
    }
    
    *this = LinkedList(listAsVec);

}

// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
    
    listSize_ = source.size();
    start_ = new LinkedListNode(source.front());
    last_ = new LinkedListNode(source.back());
    
    LinkedListNode* current = start_;
    for (auto itr = ++source.begin(); itr != source.end(); ++itr) {
        current->next_ = new LinkedListNode(*itr);
        current = current->next_;
        source.pop_front();
    }
    
    source.pop_front();

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
    
    listSize_ = source.size();
    start_ = new LinkedListNode(source.front());
    last_ = new LinkedListNode(source.back());
    
    LinkedListNode* current = start_;
    for (auto itr = ++source.begin(); itr != source.end(); ++itr) {
        current->next_ = new LinkedListNode(*itr);
        current = current->next_;
        source.pop_front();
    }
    
    return *this;

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
            last_ = current;
        }
        
        LinkedListNode* oldEnd = current->next_;
        current->next_ = nullptr;
        delete oldEnd;
        listSize_--;
        
    }

}

template<typename ElementType>
int LinkedList<ElementType>::size() const {
    
    return (int) listSize_;

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
    
    if (size() == 0) {
        return;
    }

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
    for (auto itr = list.begin(); itr != list.end(); ++itr) {
        os << *itr << "  ";
    }
    return os;
}

template<typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {
    
    if (n >= size()) {
        return;
    }
    
    LinkedListNode* current = start_;
    for (int i = 1; i < n; i++) {
        current = current->next_;
    }
    
    LinkedListNode* toRemove = current->next_;
    current->next_ = toRemove->next_;
    delete toRemove;
    listSize_--;

}

template<typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
    
    for (int i = 1; i < size(); i+=2) {
        RemoveNth(i);
    }

}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
    
    if (size() != rhs.size()) {
        return false;
    }
    
    auto lhsItr = begin();
    auto rhsItr = rhs.begin();
    
    //Iterates through both sides and checks if everything is equal
    while (lhsItr != end()) {
        if (lhsItr != rhsItr) {
            return false;
        }
        ++lhsItr;
        ++rhsItr;
    }
    
    return true;

}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {

    return !(lhs == rhs);
    
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
    
    if (current_ == nullptr) {
        if (other.current_ == nullptr) {
            return false;
        } else {
            return true;
        }
    } else if (other.current_ == nullptr) {
        return true;
    }
    
    //recursively checks if all values are equal
    return current_->value_ != other.current_->value_ && current_->next_ != other.current_->next_;
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
    return iterator(start_);
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
    return nullptr;
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
    if (current_ == nullptr) {
        if (other.current_ == nullptr) {
            return false;
        } else {
            return true;
        }
    } else if (other.current_ == nullptr) {
        return true;
    }
    
    //recursively checks if all values are equal
    return current_->value_ != other.current_->value_ && current_->next_ != other.current_->next_;
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
    return const_iterator(start_);
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
    return nullptr;
}
