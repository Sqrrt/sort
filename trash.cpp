
//Мусор. Сортировки не на итераторах для всего



/*void qsort(iterator begin, iterator end, bool(*cmp)(const T&, const T&)){
        iterator index1 = begin;
        iterator index2 = end;
        index2--;
        T  pivot = *index2;
        cout<<pivot<<"\n";
        do{
            while (!cmp(pivot, *index2)){
                index2--;
            }
            while(!cmp(pivot, *index1)){
                index1++;
            }
            if (index1 <= index2) {
                cout<< *index1 <<" "<< *index2 <<"\n";
                swap(*index1 ,*index2);
                index1++;
                index2--;
            }
        }while (index1 < index2);
        if(index2 > begin) {
            qsort(begin, index2, cmp);
        }
        if(end > index1) {
            qsort(index1, end, cmp);
        }
    }*/




/*void quicksort(DynamicArray<T>& vec, int l, int r, int cmp(int a, int b)){
        int c = vec.Get(((r + l) / 2));
        int i = l;
        int j = r - 1;
        do{
            while (cmp(vec.Get(i), c) > 0) {
                i++;
            }
            while (cmp(vec.Get(j), c) < 0) {
                j--;
            }
            if (i <= j) {
                vec.myswap(i++ ,j--);
            }
        } while (i < j);
        if(j > l) {
            quicksort(vec, l, j+1, cmp);
        }
        if(r > i) {
            quicksort(vec, i-1, r, cmp);
        }
    }*/





/*
void merge(DynamicArray<int>& vec,int l, int middle, int  r, int cmp(int a,int b)){
    if(l == r){
        return;
    }
    DynamicArray<int> res(vec,l,r+1);
    if (l >= r || middle < l || middle > r){
        return;
    }
    if(r - l == 1){
        if(vec.Get(l) > vec.Get(r)){
            vec.myswap(l,r);
        }
        return;
    }
    int a1 = 0;
    int a2 = middle - l + 1;
    for(int i = l; i <= r; ++i){
        if(a1 > middle - l){
            vec.Set(i, res.Get(a2));
            a2++;
            //cout<< a1<< " "<< a2 << "|";
        }
        else if(a2 > r - l){
            vec.Set(i, res.Get(a2));
            a1++;
            //cout<< a1<< " "<< a2 << "||";
        }
        else if(res.Get(a1) < res.Get(a2)){
            vec.Set(i, res.Get(a1));
            a1++;
            //cout<< a1<< " "<< a2 << "|||";
        }
        else{
            vec.Set(i, res.Get(a1));
            a2++;
            //cout<< a1<< " "<< a2 << "||||";
        }
    }
}
void mergesort(DynamicArray<int>& vec,int l,int r, int cmp(int a, int b)){
    if(r <= l) return;
    int middle = l + (r - l)/2;
    mergesort(vec, l, middle, cmp);
    mergesort(vec, middle + 1, r, cmp);
    merge(vec, l, middle, r, cmp);
}*/



/*void merge(DynamicArray<T>& vec, int l, int middle, int  r, int cmp(int a, int b)){
        if(l == r){
            return;
        }
        DynamicArray<T>  res(vec, l, r + 1);
        if (l >= r || middle < l || middle > r){
            return;
        }
        if(r - l == 1){
            if(vec.Get(l) > vec.Get(r)){
                vec.myswap(l,r);
            }
            return;
        }
        int a1 = 0;
        int a2 = middle - l + 1;
        for(int i = l; i <= r; ++i){
            if(a1 > middle - l){
                vec.Set(i, res.Get(a2));
                a2++;
                //cout<< a1<< " "<< a2 << "|";
            }
            else if(a2 > r - l){
                vec.Set(i, res.Get(a1));
                a1++;
                //cout<< a1<< " "<< a2 << "||";
            }
            else if(res.Get(a1) < res.Get(a2)){
                vec.Set(i, res.Get(a1));
                a1++;
                //cout<< a1<< " "<< a2 << "|||";
            }
            else{
                vec.Set(i, res.Get(a2));
                a2++;
                //cout<< a1<< " "<< a2 << "||||";
            }
        }
    }
    void mergesort(DynamicArray<T>& vec, int l, int r, int cmp(int a, int b)){
        if(r <= l) return;
        int middle = l + (r - l)/2;
        mergesort(vec, l, middle, cmp);
        mergesort(vec, middle + 1, r, cmp);
        merge(vec, l, middle, r, cmp);
    }*/


/*
void bubblesort(DynamicArray<T>* res){
    //DynamicArray* res(arr);
    for(int i = 0; i <  res->GetSize(); i++){
        for (int j = 0; j < res->GetSize() - i; j++){
            if(res->Get(j + 1) < res->Get(j)){
                res->myswap(j, j + 1);
            }
        }
    }
}

void bubblesort() {
        bool param = true;
        while (param) {
            param = false;
            Node *tmp = head;
            while (tmp->next) {
                if (tmp->data > tmp->next->data) {
                    T item = tmp->data;
                    tmp->data = tmp->next->data;
                    tmp->next->data = item;
                    param = true;
                }
                tmp = tmp->next;
            }
        }
    }

void listqsort(LinkedList<int>& list, bool cmp(const T a, const T b)){
        if (list.head == list.end){
            return;
        }
        Node* n = list.head;
        T first = list.GetFirst();
        LinkedList<int> leftlist;
        LinkedList<int> rightlist;
        for (int i = 1; i < list.GetLength(); i++){
            T item = n->next->data;
            if(item < first){
                leftlist.Prepend(item);
            }
            if(item >= first){
                rightlist.Prepend(item);
            }
            n = n->next;
        }
        listqsort(leftlist,cmp);
        leftlist.Append(list.GetFirst());
        listqsort(rightlist,cmp);
        list = *leftlist.Concat(&rightlist);
    }



Node* merges(Node* first, Node* second, int cmp(T a, T b)){
        Node* res;
        if(first == NULL && second == NULL){
            return res;
        }
        else if(first == NULL){
            res = second;
        }
        else if(second == NULL){
            res = first;
        }
        else{
            if (cmp(first->data, second->data) > 0) {
                res = first;
                res->next = merges(first->next, second, cmp);
            }
            if (cmp(first->data, second->data) <= 0) {
                res = second;
                res->next = merges(first, second->next, cmp);
            }
        }
        return res;
    }
    Node* mergevs (Node* header, int cmp(T a, T b)){
        Node* c = header;
        if(header == NULL || header->next == NULL){
            return c;
        }
        Node* a = header;
        Node* b = header->next;
        while((b!= NULL) && (b->next != NULL)){
            c = c->next;
            b = b->next->next;
        }
        b = c->next;
        c->next = NULL;
        return merges(mergevs(a, cmp), mergevs(b, cmp), cmp);
    }
    void mergesort(LinkedList<T>* list, int cmp(T a, T b)){
        Node* c = list->head;
        Node* d = mergevs(c, cmp);
        list->head = d;
        for(int i = 1; i < list->size; i++){
            d = d->next;
        }
        list->end = d;
    }



void bubble_sort2(myiterator first, bool(*cmp)(const T&,const T&)){
        bool param = true;
        while(param){
            param = false;
            myiterator tmp = first;
            myiterator tmp2 = first;
            tmp2++;
            while(tmp2 != nullptr){
                if(!cmp(*tmp, *tmp2)){
                    swap(*tmp, *tmp2);
                    param = true;
                }
                tmp++;
                tmp2++;
            }
        }
    }





myiterator merge__(myiterator first, bool(*cmp)(const T&,const T&)){
        myiterator c = first;
        myiterator temp = first;
        ++temp;
        if(c == nullptr || temp == nullptr){
            return first;
        }
        myiterator a = first;
        myiterator b = first;
        ++b;
        myiterator d = b;
        d++;
        while(a != nullptr && b!=nullptr){
            ++a;
            ++b;
            if(b != nullptr) {
                ++b;
            }
        }
        b = ++c;
        c = nullptr;
        return merge(merge_(a,cmp),merge_(b,cmp), cmp);
    }



if (head == end){
return;
}
Node* n = head;
T first = GetFirst();
LinkedList<T> leftlist;
LinkedList<T> rightlist;
for (int i = 1; i < GetLength(); i++){
T item = n->next->data;
if(!(cmp(item, first))){
leftlist.Prepend(item);
}
if(item >= first){
rightlist.Prepend(item);
}
n = n->next;
}
leftlist.quicksort(cmp);
leftlist.Append(GetFirst());
rightlist.quicksort(cmp);
list = *(leftlist.Concat(&rightlist));


#ifndef LAB2ND_SORT_H
#define LAB2ND_SORT_H
#include <iostream>
template <typename T, class K>
class Sort{
public:
    virtual void Quick_sort(K firstiterator, K seconditerator, bool(*cmp)(const T&,const T&)) = 0;
    virtual void Merge_sort(K firstiterator, K seconditerator, bool(*cmp)(const T&,const T&)) = 0;
    virtual void Bubble_sort(K firstiterator, K seconditerator, bool(*cmp)(const T&,const T&)) = 0;
};
#endif //LAB2ND_SORT_H

*/
//Мусор. Сортировки не на итераторах для списка.