#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

#include<vector>
class UnionFind{
    public:
    UnionFind(int);
    int find_set(int);
    void union_set(int, int);
    bool is_same_set(int,int);
    int count_of_sets();
    int set_size(int);

    private:
    int size_;
    int no_of_sets_;
    std::vector<int>rank_;
    std::vector<int>parent_;
    std::vector<int>set_size_;

};

#endif