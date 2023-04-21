#include <iostream>
#include "Vector.cpp"

using namespace std;

template<typename T>
class Stack
{
public:
    Stack() {}
    void Push(const T element);
    void Pop();
    T Top() const;
    size_t Size() const;
    bool Empty() const;
private:
    Vector<T> vec;
};

template<typename T>
void Stack<T>::Push(const T element)
{
    try
    {
        vec.push_back(element);
    }
    catch (exception& e) { cout << e.what() << endl; }
    cout << element << " added successfully" << endl;
}

template<typename T>
void Stack<T>::Pop()
{
    if (!vec.empty()) { 
        vec.pop_back(); 
        cout << "Last element deleted successfully" << endl;
    }
    else cout << "Stack is empty!" << endl;
}

template<typename T>
T Stack<T>::Top() const
{
    //return vec[vec.size() - 1];
    if (!vec.empty()) return vec[vec.size() - 1];
    else {
        cout << "Stack is empty!" << endl;
        T tmp{};
        return tmp;
    }
}

template<typename T>
size_t Stack<T>::Size() const
{
    return vec.size();
}

template<typename T>
bool Stack<T>::Empty() const
{
    return vec.empty();
}

int main()
{
    Stack <int> steckInt;
    cout << "Check int" << endl;
    steckInt.Push(232);
    cout << steckInt.Empty() << endl;
    steckInt.Push(43);
    cout << steckInt.Top() << endl;
    steckInt.Pop();
    cout << steckInt.Size() << endl;
    
    Stack <double> steckDouble;
    cout << "Check double" << endl;
    steckDouble.Push(232.332);
    cout << steckDouble.Empty() << endl;
    steckDouble.Push(43.1212);
    cout << steckDouble.Top() << endl;
    steckDouble.Pop();
    cout << steckDouble.Size() << endl;

    Stack <string> steckString;
    cout << "Check string" << endl;
    steckString.Push("aa");
    cout << steckString.Empty() << endl;
    steckString.Push("bb");
    cout << steckString.Top() << endl;
    steckString.Pop();
    cout << steckString.Size() << endl;
    
    std::cout << "Hello World!\n";
}