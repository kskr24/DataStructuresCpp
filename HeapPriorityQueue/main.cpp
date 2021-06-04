#include <iostream>
#include <vector>
#include "HeapPriorityQueue.h"
#include "HeapPriorityQueue.cpp"

using namespace std;

int main()
{
    HeapPriorityQueue<int,Comparator<int>> pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(30);
    pq.insert(40);
    pq.insert(50);
    pq.insert(45);
    pq.insert(35);
    pq.insert(25);
    pq.insert(60);

    //test<int,Comparator<int>>(pq);

    while(!pq.empty()){
        cout<<pq.min()<<" ";
        pq.removeMin();
    }



    return 0;
}
