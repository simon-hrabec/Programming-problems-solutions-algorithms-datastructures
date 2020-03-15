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
