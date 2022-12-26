#include "UnionFind.hpp"

UnionFind::UnionFind(int size) : size_(size), no_of_sets_(size) {
  parent_.resize(size + 1);
  rank_.assign(size + 1, 1);
  set_size_.assign(size + 1, 1);
  for (int i = 1; i <= size; i++) {
    parent_[i] = i;
  }
}

int UnionFind::find_set(int x) {
  return (parent_[x] == x) ? x : parent_[x] = find_set(parent_[x]);
}

bool UnionFind::is_same_set(int x, int y) { return find_set(x) == find_set(y); }

int UnionFind::set_size(int x) { return set_size_[find_set(x)]; }

int UnionFind::count_of_sets() { return no_of_sets_; }

void UnionFind::union_set(int x, int y) {
  if (is_same_set(x, y))
    return;

  int i = find_set(x);
  int j = find_set(y);
  no_of_sets_--;
  if (rank_[i] > rank_[j]) {
    set_size_[i] += set_size_[j];
    parent_[j] = i;
  } else {
    set_size_[j] += set_size_[i];
    parent_[i] = j;
    if (rank_[i] == rank_[j]) {
      rank_[j]++;
    }
  }
}
