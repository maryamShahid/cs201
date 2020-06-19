// Note: Reference taken from slides
#include <string>
using namespace std;
template <class Type>

class Stack {

public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    bool push(Type newItem);
    bool pop();
    Type getTop() const;

private:
    struct StackNode {
        Type item;
        StackNode    *next;
        };
        StackNode *topPtr;
};

template class Stack<char>;
template class Stack<double>;