#include <iostream>
#include <type_traits>
using namespace std;
template<typename T>
struct Get {
  const static int Size = sizeof(T);
};
template<typename S>
struct Get<S*> {
  const static int Size = 0;
};

template<class T>//typename
T supermax(T first, T second){
  if(first > second)
    return first;
  else
    return second;
}
//array<int,5> a;
template<class T = double, int Size = 5>
class Bag {
 static_assert(is_default_constructible<T>::value,
  "Need default constructor!");

   T arr[Size];// = {};???
   public:
    T& operator[](int index);
};
class NoDefault{
  public:
  NoDefault() = delete;
};

template<class T, int Size>
T& Bag<T,Size>::operator[](int index){
    cout << "general" << endl;
    if(index < Size && index >= 0)
        return arr[index];
    else
        return arr[0];
}
template<int Size>
class Bag<char,Size> {
   char arr[Size] = {};
   public:
    char& operator[](int index){
      cout << "special" << endl;
      return arr[index];
    }
};

template<>
class Bag<char,5> {
   char arr[5] = {};
   public:
    char& operator[](int index){
      cout << "super special" << endl;
      return arr[index];
    }
};
