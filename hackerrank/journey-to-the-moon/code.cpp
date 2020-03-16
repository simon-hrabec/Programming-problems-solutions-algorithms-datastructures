#include <algorithm>
#include <vector>

class union_find{
 public:
  std::vector<int> roots;
  std::vector<int> sizes;
  int groups_count;
  union_find(const int maxCount) : roots(maxCount), sizes(maxCount), groups_count(maxCount){
    for(int i = 0; i < maxCount; i++) {
      roots[i] = i;
      sizes[i] = 1;
    }
  }
 
  int find(int idx) {
    //Find root index
    int rootIdx = idx;
    while(rootIdx != roots[rootIdx]) {
      rootIdx = roots[rootIdx];
    }
 
    //Reconnect all elements to root
    while (idx != rootIdx) {
      const int nextIdx = roots[idx];
      roots[idx] = rootIdx;
      idx = nextIdx;
    }
 
    return rootIdx;
  }
 
  void merge(int first, int second) {
    int firstIdx = find(first);
    int secondIdx = find(second);
      
    if (firstIdx == secondIdx) {
      return;
    }

    groups_count--;
 
    if(sizes[firstIdx] > sizes[secondIdx]){
      std::swap(firstIdx, secondIdx);
    }
 
    roots[firstIdx] = secondIdx;
    sizes[secondIdx] += sizes[firstIdx];
  }

  int get_groups_count() const {
    return groups_count;
  }
};

#include <iostream>
#include <unordered_map>
using namespace std;

uint64_t comb2(const uint64_t num){
  return (num*(num-1))/2;
}

uint64_t countPossiblePairs(const int N, const vector<pair<int,int>> &pairs) {
  union_find uf(N);
  for(const auto&[first, second] : pairs) {
    uf.merge(first, second);
  }
 
  unordered_map<int,int> countByCountry;
  for(int i = 0; i < N; i++) {
    countByCountry[uf.find(i)]++;
  }
 
  uint64_t totals = comb2(N);
  for(const auto&[country, count]: countByCountry){
    totals -= comb2(count);
  }
  return totals;
}
 
int main() {
  cout << countPossiblePairs(4, {{1,2}, {2,3}}) << endl;
  cout << countPossiblePairs(5, {{0,1}, {2,3}, {0,4}}) << endl;
}