#pragma once
#include "search.h"

template <typename KeyType>
class StandardBinarySearch : public Search<KeyType> {
 public:
  uint64_t search(const std::vector<Row<KeyType>>& data,
                  const KeyType lookup_key, size_t* num_qualifying,
                  size_t start, size_t end) const {


        int lo = start;
        int hi = end;
        long m = 0;
        while (lo <= hi) {
            m = (lo + hi) / 2;
            __builtin_prefetch(&(data[lo + m / 2]), 0, 0);
            __builtin_prefetch(&(data[m + m / 2]), 0, 0);
            if (lookup_key < data[m].key) {
                hi = m-1;
            } else if (lookup_key > data[m].key) {
                lo = m+1;
            } else {
                return m;
            }
        }
        return hi;

  }
  void createLayout(const std::vector<Row<KeyType>>& A, std::vector<Row<KeyType>>& B, uint64_t i, uint64_t n){}

  std::string name() const { return "StandardBinarySearch"; }
};
