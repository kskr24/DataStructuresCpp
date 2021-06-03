#include <bits/stdc++.h>

using namespace std;

template<typename E>
class Comparator{
public:
    bool operator()(const E& e1, const E& e2){
        return e1<e2;
    }
};

template<typename E, typename C>
class ListPriorityQueue{
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min() const;
    void removeMin();
private:
    list<E> L;
    C isLess;
};

template<typename E, typename C>
int ListPriorityQueue<E,C>::size() const{
    return L.size();
}

template<typename E,typename C>
bool ListPriorityQueue<E,C>::empty() const{
    return L.empty();
}

template<typename E, typename C>
void ListPriorityQueue<E,C>::insert(const E& e){
    typename std::list<E>::iterator p;
    p=L.begin();
    while(p !=L.end() && isLess(*p,e))
        ++p;
    L.insert(p,e);
}

template<typename E, typename C>
const E& ListPriorityQueue<E,C>::min() const{
     return L.front();
}

template<typename E, typename C>
void ListPriorityQueue<E,C>::removeMin() {
    L.pop_front();
}
int main()
{
    ListPriorityQueue<int,Comparator<int>> pq;
    pq.insert(9);
    pq.insert(7);
    pq.insert(10);
    while(!pq.empty()){
        cout<<pq.min()<<" ";
        pq.removeMin();
    }
    if(pq.empty()){
        cout<<endl<<"yes the list is empty()";
    }
    return 0;
}
