#pragma once


// NOTE:   This file is *** incomplete *** 


// example taken from 'A Tour of C++', by Bjarne Stroustrup
// I renamed the class to MyVector

template<typename T>        // identical to template<class T>
class MyVector {
private:
    T* elem;  // elem points to an array of sz elements of type T 
    int sz;

public:
    explicit MyVector(int s);              
    ~MyVector() { delete[] elem; }         
    
    MyVector(initializer_list<T>);                    // initializer-list constructor

    template<typename Iter>
    MyVector(Iter b, Iter e);                       // [b:e) iterator-pair constructor

    // struct iterator { using value_type = T; /* ... */ };
    // iterator begin();

    T& operator[](int i);                           // for non-const Vectors 
    const T& operator[](int i) const;               // for const Vectors
    int size() const { return sz; }
};

// this is a deduction guide which says a pair of values of the same type should be iterators.
template<typename Iter>
MyVector(Iter, Iter) -> MyVector<typename Iter::value_type>;


template<typename T>
MyVector<T>::MyVector(int s)
{
    if (s < 0)
        throw length_error{ "Vector constructor: negative size" };
    elem = new T[s];
    sz = s;
}

template<typename T>
inline MyVector<T>::MyVector(initializer_list<T>)
{
    // to do
}

template<typename T>
const T& MyVector<T>::operator[](int i) const
{
    if (i < 0 || size() <= i)
        throw out_of_range{ "Vector::operator[]" };
    return elem[i];
}


template<typename T>
T& MyVector<T>::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw out_of_range{ "Vector::operator[]" };
    return elem[i];
}


// below are to allow use of begin and end, for use with 'foreach' loops 
template<typename T>
T* begin(MyVector<T>& x)
{
    return &x[0];     // pointer to first element or to one-past-the-last element
}

template<typename T>
T* end(MyVector<T>& x)
{
    return &x[0] + x.size();                 // pointer to one-past-the-last element
}

template<typename T>
template<typename Iter>
inline MyVector<T>::MyVector(Iter b, Iter e)
{
    // to do
}
