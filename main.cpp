#include <iostream>
//#include "sequence.h"
#include <gtest/gtest.h>
#include "linkedlist.h"
#include "array.h"
#include <random>
#include <fstream>
#include <chrono>
using namespace std;
template <typename T>
bool cmprtr(const T& first, const T& second){
    return (first < second);
}
 /*
int main(){
    int arrrr[] = {2,4,6,8,9,7,8,9,11,16,5,43,-34,5,5,7,9,8,2};
    const int size = 1000;
    int arr2[size];
    for(long int i = 0; i < 1000; i++) {
        arr2[i] = rand()% 10000;
        //cout<< " "<< arr2[i]<<" "<<i;
    }
    int arr[] = {24409, 22019, 14777, 9221};
    LinkedList<int> vec(arr2,1000);
    vec.quicksort(vec,0, 1000, cmp);
    for(int i = 0; i < list.GetLength(); i++){
        cout << " "<< list.Get(i);
    }
}*/
/*int main(){
    int A[] = {5,4,3,2,1,66,15,54,32,21,22,-87, 94,44,35,4};
    LinkedList<int> arr(A,16);
    for(int i = 0; i < arr.GetLength(); i++){
        cout<< arr.Get(i)<<" ";
    }
    cout<<"\n";
    //arr.merge_sorter(cmprtr);
    for(int i = 0; i < arr.GetLength(); i++){
        cout<< arr.Get(i)<<" ";
    }
}*/
/*int main(){
    int size = 10;
    ofstream fout;
    fout.open("file.txt",ios:: app);
    //bubble_sort_array
    fout<<"List.Qsort"<<endl;
    for(int i = 0; i < 4; i++) {
        int arr[size];
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 100000 + 1;
        }
        LinkedList<int> list(arr, size);
        auto start = chrono::steady_clock::now();
        list.bubble_sorter(cmprtr);
        auto end = chrono::steady_clock::now();
        if (!fout.is_open()) {
            cout << "error";
        }
        if (fout.is_open()) {
            fout << size << " " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
        }
        size *= 10;

    }
    fout.close();
}*/
void func(int n, int k, int l){
    int size = 10;
    ofstream fopen;
    cout<<1;
    //quick_sort_array
    fopen.open("file.txt",ios:: app);
    fopen<<"Array.Quick"<<endl;
    for(int i = 0; i < n; i++){
        int arr[size];
        for(int j = 0; j < size; j++){
            arr[j]= rand()%100000+1;
        }
        DynamicArray<int> array(arr, size);
        auto start = chrono::steady_clock::now();
        array.quick_sorter(cmprtr);
        auto end = chrono::steady_clock::now();
        if (!fopen.is_open()){
            cout<<"error";
        }
        if(fopen.is_open()){
            fopen<< size<<" "<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
        }
        size=max(size*l, size+k);
    }
    fopen.close();
    size = 10;
    cout<<2;
    //bubblesort
    fopen.open("file.txt",ios:: app);
    fopen<<"Array.Bubble"<<endl;
    for(int i = 0; i < n; i++){
        int arr[size];
        for(int j = 0; j < size; j++){
            arr[j]= rand()%100000+1;
        }
        DynamicArray<int> array(arr, size);
        auto start = chrono::steady_clock::now();
        array.bubble_sorter(cmprtr);
        auto end = chrono::steady_clock::now();
        if (!fopen.is_open()){
            cout<<"error";
        }
        if(fopen.is_open()){
            fopen<< size<<" "<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
        }
        size=max(size*l, size+k);
    }
    fopen.close();
    size = 10;
    cout<<3;
    //Mergesort
    fopen.open("file.txt",ios:: app);
    fopen<<"Array.Merge"<<endl;
    for(int i = 0; i < n; i++){
        int arr[size];
        for(int j = 0; j < size; j++){
            arr[j]= rand()%100000+1;
        }
        DynamicArray<int> array(arr, size);
        auto start = chrono::steady_clock::now();
        array.bubble_sorter(cmprtr);
        auto end = chrono::steady_clock::now();
        if (!fopen.is_open()){
            cout<<"error";
        }
        if(fopen.is_open()){
            fopen<< size<<" "<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
        }
        size=max(size*l, size+k);
    }
    fopen.close();
    size = 10;
    cout<<4;
    //bubblesort list
    fopen.open("file2.txt",ios:: app);
    fopen<<"List.Bubble"<<endl;
    for(int i = 0; i < n; i++){
        int arr[size];
        for(int j = 0; j < size; j++){
            arr[j]= rand()%100000+1;
        }
        LinkedList<int> list(arr, size);
        auto start = chrono::steady_clock::now();
        list.bubble_sorter(cmprtr);
        auto end = chrono::steady_clock::now();
        if (!fopen.is_open()){
            cout<<"error";
        }
        if(fopen.is_open()){
            fopen<< size<<" "<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
        }
        size=max(size*l, size+k);
    }
    fopen.close();
    size = 10;
    cout<<5;
    //quicksort list
    fopen.open("file2.txt",ios:: app);
    fopen<<"List.Quick"<<endl;
    for(int i = 0; i < n; i++){
        int arr[size];
        for(int j = 0; j < size; j++){
            arr[j]= rand()%100000+1;
        }
        LinkedList<int> list(arr, size);
        auto start = chrono::steady_clock::now();
        list.quick_sorter(cmprtr);
        auto end = chrono::steady_clock::now();
        if (!fopen.is_open()){
            cout<<"error";
        }
        if(fopen.is_open()){
            fopen<< size<<" "<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
        }
        size=max(size*l, size+k);
    }
    fopen.close();
    size = 10;
    cout<<6;
    //mergesort list
    fopen.open("file2.txt",ios:: app);
    fopen<<"List.Merge"<<endl;
    for(int i = 0; i < n; i++){
        int arr[size];
        for(int j = 0; j < size; j++){
            arr[j]= rand()%100000+1;
        }
        LinkedList<int> list(arr, size);
        auto start = chrono::steady_clock::now();
        list.merge_sorter(cmprtr);
        auto end = chrono::steady_clock::now();

        if (!fopen.is_open()){
            cout<<"error";
        }
        if(fopen.is_open()){
            fopen<< size<<" "<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
        }
        size=max(size*l, size+k);
    }
    fopen.close();
}
int main(int argc, char** argv) {
    func(10,60,1);
    testing::InitGoogleTest(&argc, argv);
    cout << "Hello, World!\n";

    return RUN_ALL_TESTS();
}
/*int main(){
    func(10,60,1);
    return 0;
}*/