#include <iostream>
#include <type_traits>

template <typename T>
class Stack{
public:
    Stack(){
        max_size = 10;
        stack[max_size - 1];
    }
    Stack(int max_size_){
        max_size = max_size_;
    }

    template<typename T>
    push(T){

    }
private:
    int max_size = 0;
    int top = -1;
    T stack;
};

int main(){
    Stack<int> stack(10);
    return 0;
}