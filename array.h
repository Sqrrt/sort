
#ifndef LAB2ND_ARRAY_H
#define LAB2ND_ARRAY_H
#include "../lab4/empty.h"
#include <iostream>
#include "myexception.h"
#include"iteratorarray.h"
using namespace std;

template <typename T>
class DynamicArray {
private:
    T *data;
    int size;
    int capacity;
public:
    typedef IteratorArray<T> myiterator;
    DynamicArray(){
        data =  nullptr;
        size = 0;
        capacity = 0;

    }
    explicit DynamicArray(int siz) {
        if (siz < 0){
            throw my(1,(char*) "Size must be positive");
        }
        size = siz;
        capacity = siz;
        data = new T[siz];
        for (int i = 0; i < siz; i++) {
            data[i] = T();
        }
    }
    DynamicArray(DynamicArray<T> &dynamicArray) {
        size = dynamicArray.size;
        capacity = size;
        data = new T[size];
        for (int j = 0; j < size; j++) {
            data[j] = dynamicArray.data[j];
        }
    }
    DynamicArray(DynamicArray<T> &dynamicArray, int l, int r) {
        if(r < 0 || l < 0){
            throw my(1,(char*) "Size must be positive");
        }
        capacity = r - l;
        data = new T[r - l];
        for (int j = 0; j < r - l; j++) {
            data[j] = dynamicArray.data[l + j];
        }
    }
    ~DynamicArray() {
        delete[] data;
    }
    int GetSize() const{
        return size;
    };
    T Get(int index) const{
        if (index < -1){
            throw my(1,(char*) "Size must be positive");
        }
        if (index > size + 1){
            throw my(2,(char*) "Index out of range");
        }
        return data[index];
    };
    void Set(int index, T value) {
        if (index > size + 1){
            throw my(2,(char*) "Index out of range2");
        }
        if (index < 0){
            throw my(1,(char*) "Index must be positive");
        }
        else {
            data[index] = value;
        }
    }
    DynamicArray(T *items, int count2) {
        int count = count2;
        if (count < 0){
            throw my(1,(char*) "Size must be positive");
        }
        int i = 0;
        size = count;
        capacity = count;
        data = new T[size];
        while( i != count) {
            data[i] = items[i];
            i++;
        }
    }
    void setter(int index, T value){
        if (index < 0){
            my(1,(char*) "Size must be positive");
            throw exception();
        }
        if (index > size){
            throw my(2,(char*) "Index out of range3");
        }
        data[size] = data[size - 1];
        for(int i = size - 1; i > index - 1; i--){
            data[i] = data[i-1];
        }
        data[index] = value;
    }
    void myswap(int index1, int index2){
        T item = this->Get(index1);
        this->Set(index1, Get(index2));
        this->Set(index2, item);
    }
    void Resize(int newSize) {
        if (newSize > capacity) {
            int newCapacity = max(newSize, size * 2);
            T *newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            data = newData;
            capacity = newCapacity;
            size = newSize;
        }
        if (newSize <= capacity) {
            T* newData = new T[capacity];
            for (int i = 0; i < newSize; i++) {
                newData[i] = data[i];
            }
            data = newData;
            size = newSize;
        }
    }
    IteratorArray<T> begin(){
        return IteratorArray<T>(data);
    }
    IteratorArray<T> end(){
        return IteratorArray<T>(data + size - 1);
    }
    //MERGESORT
    int real_index(IteratorArray<T> iter){
        int count = 0;
        for(myiterator it = begin(); it <= end(); ++it){
            if(it == iter){
                return count - 1;
            }
            ++count;
        }
        return -1;
    }
    void merge(myiterator begin, myiterator middle, myiterator end, bool(*cmp)(const T&,const T&)){
        myiterator middle2 = middle;
        ++middle2;
        myiterator length1 = middle;
        myiterator length2 = end;
        myiterator index1 = begin;
        myiterator index2 = middle2;
        //DynamicArray<T>* merged_arr(real_index(end)+1);
        //iterator merged_index = merged_arr.begin();
        T* merged_vec = new T[real_index(end) + 1];
        int merged_index = 0;
        while((index1 <= length1) && (index2 <= length2)){
            if(cmp(*index2, *index1)){
                merged_vec[merged_index] = *index2;
                ++index2;
            }
            else{
                merged_vec[merged_index] = *index1;
                ++index1;
            }
            merged_index++;
        }
        while(index1 <= length1){
            merged_vec[merged_index] = *index1;
            ++index1;
            merged_index++;
        }
        while(index2 <= length2){
            merged_vec[merged_index] = *index2;
            ++index2;
            merged_index++;
        }
        int count = 0;
        for(myiterator it = begin; it <= end; ++it){
            *(it.current) = (merged_vec[count]);
            ++count;
        }
    }
    myiterator mymiddle(myiterator begin, myiterator end){
        if(begin == end){
            return begin;
        }
        myiterator first = begin, last = end;
        while(first < last){
            ++first;
            --last;
        }
        myiterator result = last;
        return result;
    }
    void merge_sort(myiterator begin, myiterator end, bool(*cmp)(const T&, const T&)) {
        if (begin < end) {
            myiterator middle = mymiddle(begin, end);
            myiterator temp = middle;
            ++temp;
            merge_sort(begin, middle, cmp);
            merge_sort(temp, end, cmp);
            merge(begin, middle, end, cmp);
        }
    }
    void merge_sorter(bool(*cmp)(const T&, const T&)){
        merge_sort(begin(), end(), cmp);
    }
    //MERGESORT
    void merge2(myiterator begin, myiterator middle, myiterator end, bool(*cmp)(const T&, const T&)){
        //myiterator middle = mymiddle(begin,end);
        T* mergedarray = new T[real_index(begin)+1];
        myiterator iter1 = begin;
        myiterator iter2 = middle;
        int current, current2;
        iter2++;
        myiterator iter3 = iter2;
        myiterator iter4 = begin;
        myiterator iter6 = end;
        iter6++;
        while(iter1 <= middle && iter2 <= end){
            if(cmp(*iter1, *iter2)){
                mergedarray[current] = *iter2;
                iter2++;
            }
            else{
                mergedarray[current] = *iter1;
                iter1++;
            }
            current++;
        }
        while(iter1 == iter3 && iter2 != iter6){
            mergedarray[current] = *iter2;
            current++;
            iter2++;
        }
        while(iter2 == end && iter1 < iter3){
            mergedarray[current] = *iter1;
            current++;
            iter1++;
        }
        *iter4 =mergedarray[current2];
        myiterator iter5 = iter4;
        iter5++;
        current2++;
        while( iter5 != iter6){
            *iter5 = mergedarray[current2];
            current2++;
            iter5++;
        }
        begin = iter4;
        end = --iter5;
    }
    void merge_sort2(myiterator begin, myiterator end, bool(*cmp)(const T&, const T&)){
        if(begin < end){
            myiterator middle = mymiddle(begin, end);
            myiterator next = middle;
            ++next;
            merge_sort2(begin, middle, cmp);
            merge_sort2(next, end, cmp);
            merge2(begin, middle, end, cmp);
        }
    }
    //BUBBLESORT
    void bubble_sort(myiterator begin, myiterator end, bool(*cmp)(const T&, const T&)){
        for(myiterator it = end; it >=begin; it--){
            for(myiterator it2 = begin; it2 < it; ++it2){
                myiterator temp = it2;
                temp++;
                if(!cmp(*it2,*temp)){
                    //iterator iter = it;
                    //*iter = *it;
                    //*(--it2) = it.operator*();
                    //*it = iter.operator*();
                    swap(*it2, *(temp));
                }
            }
        }
    }
    void bubble_sorter(bool(*cmp)(const T&, const T&)){
        bubble_sort(begin(), end(), cmp);

    }
    //QUICKSORT
    myiterator partition (myiterator begin, myiterator end, bool(*cmp)(const T&, const T&)){
        T pivot = *end;
        myiterator index = begin;
        for(myiterator it = begin; it < end; it++){
            if(cmp(*it, pivot)){
                swap(*it, *index);
                index++;
            }
        }
        swap(*index, *end);
        return index;
    }
    void quick_sort(myiterator begin, myiterator end, bool(*cmp)(const T&, const T&)){
        if(begin > end){
            return;
        }
        myiterator pivot = partition(begin, end, cmp);
        myiterator it1 = pivot;
        myiterator it2 = pivot;
        it1--;
        it2++;
        quick_sort(begin, it1, cmp);
        quick_sort(it2, end, cmp);
    }
    void quick_sorter(bool(*cmp)(const T&, const T&)){
        quick_sort(begin(), end(), cmp);
    }
};

#endif //LAB2ND_ARRAY_H