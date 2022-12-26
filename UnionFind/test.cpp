#include <iostream>
#include "UnionFind.hpp"

int main(){
    UnionFind uf(10);
    uf.union_set(2,3);
    std::cout << uf.count_of_sets()<<std::endl;
}