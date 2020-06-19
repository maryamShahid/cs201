// Note: Reference taken from slides
#include "Stack.h"

template <class Type>
Stack<Type>::Stack() : topPtr(NULL) {
}

template <class Type>
Stack<Type>::~Stack() {
     while (!isEmpty())
         pop();
}

template <class Type>
bool Stack<Type>::isEmpty() const {
    return topPtr == NULL;
}

template <class Type>
bool Stack<Type>::push(Type newItem) {
    StackNode *newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    return true;
}

template <class Type>
bool Stack<Type>::pop() {
    if (isEmpty())
        return false;
    else {
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
         temp->next = NULL;
         delete temp;
         return true;
    }
}

template <class Type>
Type Stack<Type>::getTop() const {
    if (!isEmpty())
        return topPtr->item;
}