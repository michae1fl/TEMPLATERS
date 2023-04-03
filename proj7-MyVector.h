#ifndef PROJ7_PROJ7_MYVECTOR_H
#define PROJ7_PROJ7_MYVECTOR_H

#include "proj7-ContainerIfc.h"
#include <stdexcept>

const int DEFAULT = 10;

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector&);
    MyVector<T>& operator =(const MyVector&);
    MyVector<T>& pushFront(T);
    MyVector<T>& pushBack(T);
    MyVector<T>& popFront(T&);
    MyVector<T>& popBack(T&);
    T  front();
    T  back();
    T&  operator [](int);
    int getSize();
    bool isEmpty();
    void erase();

private:
    T  *data;
    int size;
    int capacity;
    void grow();
    void shiftRight();
    void shiftLeft();
};

template<class T>
void MyVector<T>::grow() {

    this->capacity *= 2;
    T *temp = new T[capacity];

    for (int i = 0; i < size; i ++) {
        temp[i] = data[i];
    }

    delete [] data;
    data = temp;

}

template<class T>
void MyVector<T>::shiftRight() {

    if (size == capacity) {
        grow();
    }

    for (int i = size; i > 0; i--) {
        data[i] = data[i-1];
    }

    size ++;

}

template<class T>
void MyVector<T>::shiftLeft() {

    for (int i = 0; i < size - 1; i ++) {
        data[i] = data[i+1];
    }

    size --;
}



template <class T>
MyVector<T>::MyVector() {

    size = 0;
    capacity = DEFAULT;
    data = new T[capacity];

}

template<class T>
MyVector<T>::~MyVector() {

    delete [] data;

}

template<class T>
MyVector<T>::MyVector(const MyVector &v) {

    size = v.size;
    capacity = v.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i ++) {
        data[i] = v.data[i];
    }

}

template<class T>
MyVector<T> &MyVector<T>::operator=(const MyVector &v) {

    if (this != &v) {

        delete [] data;
        size = v.size;
        capacity = v.capacity;
        data = new T[capacity];

        for (int i = 0; i < size; i ++) {
            data[i] = v.data[i];
        }
    }

    return *this;
}

template<class T>
MyVector<T> &MyVector<T>::pushFront(T e) {

    if (size == capacity) {
        grow();
    }

    shiftRight();
    data[0] = e;
    size ++;

    return *this;
}

template<class T>
MyVector<T> &MyVector<T>::pushBack(T e) {

    if (size == capacity) {
        grow();
    }

    data[size] = e;
    size ++;

    return *this;
}

template<class T>
MyVector<T> &MyVector<T>::popFront(T &e) {

    if (isEmpty()) {
        throw BADINDEX();
    }

    e = data[0];
    shiftLeft();
    size --;

    return *this;
}

template<class T>
MyVector<T> &MyVector<T>::popBack(T &e) {

    if (isEmpty()) {
        throw BADINDEX();
    }

    e = data[size - 1];
    size--;

    return *this;
}

template<class T>
T MyVector<T>::front() {

    if (isEmpty()) {
        throw BADINDEX();
    }

    return data[0];
}

template<class T>
T MyVector<T>::back() {

    if (isEmpty()) {
        throw BADINDEX();
    }

    return data[size-1];
}

template<class T>
T &MyVector<T>::operator[](int n) {

    if (n >= size or n < 0) {
        throw BADINDEX();
    }

    return data[n];
}

template<class T>
int MyVector<T>::getSize() {
    return size;
}

template<class T>
bool MyVector<T>::isEmpty() {
    return size == 0;
}

template<class T>
void MyVector<T>::erase() {

    size = 0;

}

#endif //PROJ7_PROJ7_MYVECTOR_H
