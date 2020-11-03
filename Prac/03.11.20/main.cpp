#include <iostream>
#include <vector>
#include <type_traits>

void empty(int top){
    if (top == -1){
        throw "Stack is empty";
    }
}

template <typename T>
void arithmetic(){
    if (not std::is_arithmetic_v<T>){
        throw "Typename should be arithmetic type";
}

template <typename T>
class Stack
{
private:
    int top = -1;
    int max_size;
    std::vector<T> stack;
public:
    Stack(int max_size){
        try{
            std::vector<T> stack(max_size);
            arithmetic<T>(T tmp);
        }
        catch (const char* exception) {
            std::cout << exception;
        }
    }
    void push(T);
    T pop();

    void overflow(){
        if (stack.top == max_size){
            throw "Stack is overflowed";
        }
    }
};


template <typename T>
void Stack<T>::push(const T value)
{
    try {
        stack.overflow();
        stack.push_back(value);
        top++;
    }
    catch (const char* exception) {
        std::cout << exception;
    }
}

template <typename T>
T Stack<T>::pop()
{
    try{
        empty(stack.pop);
        T ret = stack[top--];
        stack.pop_back();
        return ret;
    }
    catch (const char* exception) {
        std::cout << exception;
    }
}


int main()
{
    Stack<int> s(5);
    s.push(5);
    std::cout << s.pop() << std::endl;
    s.pop();
    s.push(3);
    std::cout << s.pop() << std::endl;

    return 0;
}