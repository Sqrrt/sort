#ifndef LAB2ND_ITERATORARRAY_H
#define LAB2ND_ITERATORARRAY_H
#include <iostream>
#include <iterator>
template<class T>
class IteratorArray{
public:
    T* current;
public:
    typedef T* pointer;
    typedef T& reference;
    explicit IteratorArray<T>(T* curr): current(curr){
    }
    IteratorArray& operator ++(){
        ++current;
        return *this;
    }
    bool operator ==(const IteratorArray& other){
        return current == other.current;
    }
    bool operator !=(const IteratorArray& other){
        return !(current == other.current);
    }
    bool operator <(const IteratorArray& other){
        return (current < other.current);
    }
    bool operator <=(const IteratorArray& other){
        return (current <= other.current);
    }
    bool operator >(const IteratorArray& other){
        return (current > other.current);
    }
    bool operator >=(const IteratorArray& other){
        return (current >= other.current);
    }
    IteratorArray<T> operator ++(int i){
        IteratorArray temp(current);
        ++current;
        return temp;
    }
    T& operator *(){
        return *current;
    }
    const T* operator ->(){
        return current;
    }
    IteratorArray& operator --(){
        --current;
        return(*this);
    }
    IteratorArray<T> operator --(int i){
        IteratorArray temp(current);
        --current;
        return temp;
    }
};
#endif //LAB2ND_ITERATORARRAY_H
