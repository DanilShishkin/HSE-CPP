#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
    int top = -1;
    std::vector<T> stack;
public:
    void push(T);
    T pop();
};


template <typename T>
void Stack<T>::push(const T value)
{
    stack.push_back(value);
    top++;
}

template <typename T>
T Stack<T>::pop()
{
    try {
        if (top < 0)
        {
            throw "Stack is empty";
        }
        T ret = stack[top--];
        stack.pop_back();
        return ret;
    }
    catch (const char* exception) {
        std::cerr << "Stack is empty" << std::endl;
    }
}


int main()
{
    Stack<int> s;
    s.push(5);
    std::cout << s.pop() << std::endl;
    s.pop();
    s.push(3);
    std::cout << s.pop()<<std::endl;
    return 0;
}