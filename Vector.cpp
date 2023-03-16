template<typename T>
class Vector
{
public:
    Vector();
    ~Vector();
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void addMemory();
    void push_back(const T& value);
    void pop_back();
    const T& operator[](size_t index) const {
        return arr_[index];
    }
private:
    T* arr_;
    size_t size_{};
    size_t capacity_{};
};

template<typename T>
Vector<T>::Vector() {
    this->arr_ = new T[1];
    this->capacity_ = 1;
}

template<typename T>
bool Vector<T>::empty() const {
    return this->size_ == 0;
}

template<typename T>
size_t Vector<T>::size() const {
    return this->size_;
}

template<typename T>
size_t Vector<T>::capacity() const {
    return this->capacity_;
}

template<typename T>
void Vector<T>::addMemory() {
    this->capacity_ *= 2;
    T* tmp = this->arr_;
    this->arr_ = new T[this->capacity_];
    for (size_t i = 0; i < size_; ++i) this->arr_[i] = tmp[i];
    delete[] tmp;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (this->size_ >= this->capacity_) this->addMemory();
    this->arr_[this->size_++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    for (size_t i = 1; i < this->size_; ++i) {
        this->arr_[i - 1] = this->arr_[i];
    }
    --this->size_;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] this->arr_;
}