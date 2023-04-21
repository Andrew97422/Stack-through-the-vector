template<typename T>
class Vector
{
public:
    Vector();
    ~Vector();
    bool empty() const;
    size_t size() const;
    void addMemory();
    void push_back(const T& value);
    void pop_back();
    const T& operator[](size_t index) const {
        return arr_[index];
    }
private:
    T* arr_;
    size_t size_;
    size_t capacity_;
};

template<typename T>
Vector<T>::Vector() {
    arr_ = new T[1];
    capacity_ = 1;
    size_ = 0;
}

template<typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template<typename T>
size_t Vector<T>::size() const {
    return size_;
}

template<typename T>
void Vector<T>::addMemory() {
    capacity_ *= 2;
    T* tmp = arr_;
    arr_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
    delete[] tmp;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size_ == capacity_) addMemory();
    arr_[size_++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    for (size_t i = 1; i < size_; ++i) {
        arr_[i - 1] = arr_[i];
    }
    --size_;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] arr_;
}