#pragma once
#include "search.h"

template <typename KeyType>
class KBBS_Search : public Search<KeyType> {
public:
  uint64_t search(const std::vector<Row<KeyType>>& data,
                  const KeyType lookup_key,
                  size_t* num_qualifying, size_t start, size_t end) const {
    
     // left is inclusive, right is exclusive
    uint64_t k = 3;
    uint64_t left = start, right = end;
    while (left < right)
    {
        //COUNT_ITERATION();
        // divide [left, right) in k segments
        uint64_t segmentLeft = left;
        uint64_t segmentRight = left + (right - left) / k;
        for (uint64_t i = 2; i <= k; ++i)
        {
            if (lookup_key <= data[segmentRight].key) break;
            // advance to the next segment
            segmentLeft = segmentRight + 1;
            segmentRight = left + (i * (right - left)) / k;
        }
        left = segmentLeft;
        right = segmentRight;
    }

    uint64_t result = data[left].data[0];
    // ++(*num_qualifying);

    // while (++it != data.end() && it->key == lookup_key) {
    //   result += it->data[0];
    //   ++(*num_qualifying);
    // }
    return result;
  }

  void createLayout(const std::vector<Row<KeyType>>& A, std::vector<Row<KeyType>>& B, uint64_t i, uint64_t n){}

  std::string name() const {
    return "kbbs";
  }

};
