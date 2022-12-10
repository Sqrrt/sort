#include <gtest/gtest.h>
#include <iostream>
#include "array.h"
TEST (DynamicArray, input){
    int arrr[] = {11,21,543,42,5,6,7,8,9};
    DynamicArray<int>  arr(arrr, 9);
    DynamicArray<int>  arr2(3);
    arr2.Set(2,1);
    arr2.Set(1,1-87);
    arr2.Set(0, 0);
    DynamicArray<int>  arr3(arr);
    EXPECT_EQ(arr.Get(0),11);
    EXPECT_EQ(arr.Get(1),21);
    EXPECT_EQ(arr.Get(2),543);
    EXPECT_EQ(arr.Get(3),42);
    EXPECT_EQ(arr.Get(4),5);
    EXPECT_EQ(arr.Get(5),6);
    EXPECT_EQ(arr.Get(6),7);
    EXPECT_EQ(arr.Get(7),8);
    EXPECT_EQ(arr.Get(8),9);
    //EXPECT_EQ(arr2.GetSize(), 3);
    for(int i = 0; i < arr.GetSize(); i++) {
        EXPECT_EQ(arr.Get(i), arr3.Get(i));
    }
    EXPECT_EQ(arr2.Get(0),0);
    EXPECT_EQ(arr2.Get(1),-86);
    EXPECT_EQ(arr2.Get(2),1);
}

TEST(DynamicArray, get_getsize){
    int arrr[] = {11,21,543,42,5,6,7,8,9};
    DynamicArray<int>  arr(arrr, 9);
    int arrr2[] = {11,21,543};
    DynamicArray<int>  arr2(arrr2, 3);
    int K = arr2.Get(2);
    EXPECT_EQ(K, 543);
    EXPECT_EQ(arr2.GetSize(), 3);
    EXPECT_EQ(arr.GetSize(), 9);
//    EXPECT_EQ(L, "error2, Index out of range");
//    EXPECT_EQ(M, "error2, Index out of range");
}
TEST(DynamicArray, Resize_setter_GetSize){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    DynamicArray<int>  arr2(arr, 9);
    EXPECT_EQ(arr2.GetSize(), 9);
    arr2.Resize(7);
    EXPECT_EQ(arr2.GetSize(), 7);
    EXPECT_ANY_THROW(arr2.Get(9));
    arr2.Resize(11);
    EXPECT_EQ(arr2.GetSize(), 11);
    arr2.setter(2, 4);
    arr2.setter(6, 19);
    arr2.setter(9,8);
    arr2.setter(10,9);
    int arr3[] = {1,2,4,3,4,5,19,6,7,8,9};
    for(int i = 1; i < 12; i++){
            EXPECT_EQ(arr2.Get(i-1),arr3[i - 1]);
    }
}
TEST(DynamicArray,set){
    int arr[] = {11,21,543,42,5,6,7,8,9};
    DynamicArray<int>  arr2(arr, 9);
    arr2.Set(1,2);
    arr2.Set(0,1);
    arr2.Set(2,3);
    arr2.Set(3,5);
    arr2.Set(3, 4);
    for(int i = 0; i < arr2.GetSize(); i++) {
        EXPECT_EQ(arr2.Get(i), i+1);
    }
}