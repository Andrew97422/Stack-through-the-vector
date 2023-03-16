#include <iostream>
#include "Vector.cpp"

using namespace std;

template<typename T>
class Stack
{
public:
    Stack() {}
    ~Stack() {}
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
        this->vec.push_back(element);
    }
    catch (exception& e) { cout << e.what() << endl; }
    cout << element << " added successfully" << endl;
}

template<typename T>
void Stack<T>::Pop()
{
    try
    {
        this->vec.pop_back();
    }
    catch (exception& e) { cout << e.what() << endl; }
    cout << "Last element deleted successfully" << endl;
}

template<typename T>
T Stack<T>::Top() const
{
    try
    {
        int size = this->vec.size();
        return this->vec[size - 1];
    }
    catch (exception& e) { cout << e.what() << endl; }
}

template<typename T>
size_t Stack<T>::Size() const
{
    return this->vec.size();
}

template<typename T>
bool Stack<T>::Empty() const
{
    return this->vec.empty();
}

int main()
{
    Stack <int> steck;
    steck.Push(232);
    cout << steck.Empty() << endl;
    steck.Push(43);
    cout << steck.Top() << endl;
    steck.Pop();
    cout << steck.Size() << endl;

    std::cout << "Hello World!\n";
}