#ifndef HEAPPRIORITYQUEUE_H_INCLUDED
#define HEAPPRIORITYQUEUE_H_INCLUDED

using namespace std;

template<typename E>
class VectorCompleteTree{
private:
    std::vector<E> V;
public:
    typedef typename std::vector<E>::iterator Position;
protected:
    Position pos(int i);
    int idx(const Position& p) const;
public:
    VectorCompleteTree();
    int size() const;
    Position left(const Position& p);
    Position right(const Position& p);
    Position parent(const Position& p);
    bool hasLeft(const Position& p)const;
    bool hasRight(const Position& p)const;
    bool isRoot(const Position& p) const;
    Position root();
    Position last();
    void addLast(const E& e);
    void removeLast();
    void swap(const Position& p, const Position& q);
    void Inorder(Position root);

};

template<typename E>
class Comparator{
public:
    bool operator()(const E& e1,const E& e2){
        return e1<e2;
    }
};

template<typename E, typename C>
class HeapPriorityQueue;

template<typename E,typename C>
void test(HeapPriorityQueue<E,C>&);

template<typename E, typename C>
class HeapPriorityQueue{
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min();
    void removeMin();

    friend void test<E,C>(HeapPriorityQueue<E,C>&);
private:
    VectorCompleteTree<E> T;
    C isLess;
    typedef typename VectorCompleteTree<E>::Position Position;


};




#endif // HEAPPRIORITYQUEUE_H_INCLUDED
