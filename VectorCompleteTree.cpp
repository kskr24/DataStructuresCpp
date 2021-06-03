#include <bits/stdc++.h>

using namespace std;

template<typename E>
class VectorCompleteTree{
private:
    std::vector<E> V;
public:
    typedef typename std::vector<E>::iterator Position;
protected:
    Position pos(int i){
        return V.begin()+i;
    }
    int idx(const Position& p) const{
        return p-V.begin();
    }
public:
    VectorCompleteTree():V(1){}
    int size() const {return V.size()-1;}
    Position left(const Position& p){
        return pos(2*idx(p));
    }
    Position right(const Position& p){
        return pos(2*idx(p)+1);
    }
    Position parent(const Position& p){return pos(idx(p)/2);}
    bool hasLeft(const Position& p)const{return 2*idx(p)<=size();}
    bool hasRight(const Position& p)const { return 2*idx(p)+1<=size();}
    bool isRoot(const Position& p) const{ return idx(p)==1;}
    Position root(){
        return pos(1);
    }
    Position last(){
        return pos(size());
    }
    void addLast(const E& e){
        V.push_back(e);
    }
    void removeLast(){
        V.pop_back();
    }
    void swap(const Position& p, const Position& q){
        E e=*p;
        *p=*q;
        *q=e;
    }
    void Preorder(Position root){
        if(!size())
            return;
        if(hasLeft(root))
            Preorder(left(root));
        cout<<V[idx(root)]<<" ";
        if(hasRight(root))
            Preorder(right(root));
        return;
    }

};

int main()
{
    VectorCompleteTree<int> tree;
    tree.addLast(10);
    tree.addLast(15);
    tree.addLast(25);
    tree.addLast(30);
    tree.addLast(50);
    tree.addLast(8);
    tree.addLast(2);

    tree.Preorder(tree.root());
    return 0;
}
