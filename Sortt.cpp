#include <gtest/gtest.h>
#include <iostream>
#include "linkedlist.h"
#include "array.h"
template <typename T>
bool cmprtr(const T& first, const T& second){
    return (first < second);
}
/*
//WORKS

TEST(sorttests, quicksortlist){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    LinkedList<int> list(arr,11);
    list.listqsort(list, cmp);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(list.Get(i),i-5);
    }
}

//WORKS

TEST(sorttests, mergesortlist){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    LinkedList<int> list(arr,11);
    list.mergesort(&list, cmp2);
    for(int i = 0; i < 11; i++){
        cout<< list.Get(i)<<" ";
        ASSERT_EQ(list.Get(i),i-5);
    }
    cout<<"\n";
}

//WORKS

TEST(sorttests, quicksortarray){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    DynamicArray<int> array(arr,11);
    array.quicksort(array,0,11, cmp2);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(array.Get(i),i-5);
        cout<< array.Get(i)<<" ";
    }
    cout<<"\n";
}

TEST(sorttests, mergesortarray){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,-2};
    DynamicArray<int> array(arr,11);
    array.mergesort(array,0,11, cmp2);

    for(int i = 0; i < 11; i++){
        cout<< array.Get(i)<<" ";
        //ASSERT_EQ(array.Get(i),i-5);
    }
    cout<<"\n";
}

//WORKS

TEST(sorttests, bubblesortlist){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    LinkedList<int> list(arr,11);
    list.bubblesort();
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(list.Get(i),i-5);
    }
    cout<<"\n";
}

//WORKS

TEST(sorttests, bubblesortarray){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    DynamicArray<int> array(arr,11);
    array.bubblesort(&array);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(array.Get(i),i-5);
    }
    cout<<"\n";
}*/
TEST(sorttests, bubblesortarray){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    DynamicArray<int> array(arr,11);
    array.bubble_sorter(cmprtr);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(array.Get(i),i-5);
    }
}
TEST(sorttests, quicksortarray){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    DynamicArray<int> array(arr,11);
    array.quick_sorter(cmprtr);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(array.Get(i),i-5);
    }
}
TEST(sorttests, mergesortarray){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    DynamicArray<int> array(arr,11);
    array.merge_sorter(cmprtr);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(array.Get(i),i-5);
    }
}
TEST(sorttests, quicksortlist){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    LinkedList<int> list(arr,11);
    list.quick_sorter(cmprtr);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(list.Get(i),i-5);
    }
}
TEST(sorttests, mergesortlist){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    LinkedList<int> list(arr,11);
    list.merge_sorter(cmprtr);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(list.Get(i),i-5);
    }
}
TEST(sorttests, bubblesortlist){
    int arr[] = {-2,-5,-4,4,5,1,-1,0,3,-3,2};
    LinkedList<int> list(arr,11);
    list.bubble_sorter(cmprtr);
    for(int i = 0; i < 11; i++){
        ASSERT_EQ(list.Get(i),i-5);
    }
}