#include <gtest/gtest.h>
#include <iostream>
#include "arraysequence.h"
TEST (DynamicArraySequence, input){
    int arrr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    ArraySequence<int> a(arrr, 10);
    ArraySequence<int> a2( 5);
    a2.Set(0,0);
    a2.Set(1,2);
    a2.Set(2,4);
    a2.Set(3,6);
    a2.Set(4,8);
    ArraySequence<int> a4;
    a4.Append(1);
    a4.Append(2);
    a4.Append(3);
    for(int i = 0; i < 9; i++){
        EXPECT_EQ(a.Get(i),i-5);
    };
    int j = 0;
    for(int i = 0; i < 5; i++){
        EXPECT_EQ(a2.Get(i),j);
        j = j+2;
    };
    for(int i = 0; i < 3; i++){
        EXPECT_EQ(a4.Get(i),i+1);
    };
    a.Set(0,5);
    a.Set(1,4);
    a.Set(2,3);
    a.Set(3,2);
    a.Set(4,1);
    ArraySequence<int> a3(a);
    EXPECT_EQ(a3.Get(0),5);
    EXPECT_EQ(a3.Get(1),4);
    EXPECT_EQ(a3.Get(2),3);
    EXPECT_EQ(a3.Get(3),2);
    EXPECT_EQ(a3.Get(4),1);
    for(int i = 0; i < 5; i++) {
        EXPECT_EQ(a3.Get(i), 5 - i);
    }
}
TEST (DynamicArraySequence, append_prepend_insert){
    int arrr[] = {2,3,4,6,7,8,9};
    ArraySequence<int> a(arrr, 7);
    a.Append(10);
    a.Prepend(1);
    a.InsertAt(5,4);
    for(int i = 0; i < 9; i++){
        EXPECT_EQ(a.Get(i),i+1);
    }
}
TEST (DynamicArraySequence, getsub_concat){
    int arrr[] = {1,2,3,4,5,6,7,8,9,10};
    ArraySequence<int> a(arrr, 10);
    ArraySequence<int>* a2;
    a2 = (ArraySequence<int>*)a.GetSubSequence(3, 5);
    EXPECT_EQ(a2->Get(0), 4);
    EXPECT_EQ(a2->Get(1), 5);
    EXPECT_EQ(a2->Get(2), 6);
    ArraySequence<int>* a3;
    a3 = (ArraySequence<int>*)a.Concat(a2);
    for(int i = 0; i < 10; i++){
        EXPECT_EQ(a3->Get(i),i+1);
    }
    EXPECT_EQ(a3->Get(10),4);
    EXPECT_EQ(a3->Get(11),5);
    EXPECT_EQ(a3->Get(12),6);
}
TEST (DynamicArraySequence, get){
    int arrr[] = {1,2,3,4,5,6,7,8,9,10};
    ArraySequence<int> a(arrr, 10);
    EXPECT_EQ(a.Get(3), 4);
    EXPECT_EQ(a.GetLength(), 10);
    EXPECT_EQ(a.GetFirst(), 1);
    EXPECT_EQ(a.GetLast(), 10);
}
