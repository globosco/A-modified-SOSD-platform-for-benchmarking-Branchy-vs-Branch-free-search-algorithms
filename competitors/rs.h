#pragma once

#include "../util.h"
#include "base.h"
#include "rs/builder.h"
#include "rs/radix_spline.h"

template <class KeyType, int size_scale>
class RS : public Competitor {
 public:
  uint64_t Build(const std::vector<KeyValue<KeyType>>& data) {
    if (!parameters_set_) util::fail("RS parameters not set.");

    return util::timing([&] {
      auto min = std::numeric_limits<KeyType>::min();
      auto max = std::numeric_limits<KeyType>::max();
      if (data.size() > 0) {
        min = data.front().key;
        max = data.back().key;
      }
      rs::Builder<KeyType> rsb(min, max, num_radix_bits_, max_error_);
      for (const auto& key_and_value : data) rsb.AddKey(key_and_value.key);
      rs_ = rsb.Finalize();
    });
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    const rs::SearchBound sb = rs_.GetSearchBound(lookup_key);
    return {sb.begin, sb.end};
  }

  std::string name() const { return "RS"; }

  std::size_t size() const { return rs_.GetSize(); }

  bool applicable(bool _unique, const std::string& data_filename) {
    // Remove prefix from filename.
    static constexpr const char* prefix = "data/";
    std::string dataset = data_filename.data();
    dataset.erase(dataset.begin(),
                  dataset.begin() + dataset.find(prefix) + strlen(prefix));

    // Set parameters based on the dataset.
    SetParameters(dataset);

    return true;
  }

  int variant() const { return size_scale; }

 private:
  // Returns <num_radix_bits, max_error>.
  std::pair<size_t, size_t> GetConfig(const std::string& dataset) {
    // TODO books32

    using Configs = const std::vector<std::pair<size_t, size_t>>;

    if ((dataset == "L4_books_200M_uint64")||(dataset == "L3_books_200M_uint64")||(dataset == "L2_books_200M_uint64")||(dataset == "L1_books_200M_uint64"))
	{
      Configs configs = {{26, 3},
                         {22, 3},
                         {20, 5},
                         {23, 15},
                         {22, 25},
                         {20, 30},
                         {16, 40},
                         {19, 95},
                         {15, 95},
                         {9, 135}};
      return configs[size_scale - 1];
    }


    // Books (or amazon in the paper)
    else if ((dataset == "L4_books_200M_uint32")||(dataset == "L3_books_200M_uint32")||(dataset == "L2_books_200M_uint32")||(dataset == "L1_books_200M_uint32"))
	{
      Configs configs = {{26, 3},
                         {22, 3},
                         {20, 5},
                         {23, 15},
                         {22, 25},
                         {20, 30},
                         {16, 40},
                         {19, 95},
                         {15, 95},
                         {9, 135}};
      return configs[size_scale - 1];
    }

    else if (dataset == "books_200M_uint64")
	{
      Configs configs = {{25, 2},
                         {22, 4},
                         {23, 8},
                         {24, 20},
                         {22, 20},
                         {22, 45},
                         {15, 40},
                         {20, 95},
                         {16, 95},
                         {12, 135}};
      return configs[size_scale - 1];
    }

    else if (dataset == "books_400M_uint64") {
      Configs configs = {{19, 4},
                         {24, 10},
                         {25, 25},
                         {24, 35},
                         {22, 40},
                         {22, 85},
                         {18, 85},
                         {20, 190},
                         {13, 185},
                         {4, 270}};
      return configs[size_scale - 1];
    }

    else if (dataset == "books_600M_uint64") {
      Configs configs = {{19, 6},
                         {24, 15},
                         {22, 25},
                         {24, 55},
                         {22, 60},
                         {22, 125},
                         {21, 190},
                         {14, 185},
                         {17, 300},
                         {17, 300}};
      return configs[size_scale - 1];
    }

    else if (dataset == "books_800M_uint64") {
      Configs configs = {{21, 8},
                         {24, 20},
                         {25, 50},
                         {24, 70},
                         {22, 80},
                         {21, 125},
                         {21, 255},
                         {20, 380},
                         {15, 375},
                         {15, 375}};
      return configs[size_scale - 1];
    }

    // Facebook
    else if ((dataset == "L4_fb_200M_no_outlayers_uint64")||(dataset == "L4_fb_200M_uint64")||(dataset == "L3_fb_200M_uint64")|| (dataset == "L2_fb_200M_uint64")|| (dataset == "L1_fb_200M_uint64"))
	{
      Configs configs = {{20, 2},
                         {25, 9},
                         {22, 10},
                         {23, 35},
                         {21, 45},
                         {18, 70},
                         {20, 265},
                         {15, 260},
                         {15, 260},
                         {15, 260}};
      return configs[size_scale - 1];
    }

    // OSM
    else if ((dataset == "L4_osm_cellids_200M_uint64")||(dataset == "L3_osm_cellids_200M_uint64")||(dataset == "L2_osm_cellids_200M_uint64")||(dataset == "L1_osm_cellids_200M_uint64"))
	{
      Configs configs = {{27, 7},
                         {24, 4},
                         {25, 25},
                         {24, 50},
                         {23, 95},
                         {22, 185},
                         {21, 365},
                         {15, 165},
                         {13, 325},
                         {13, 325}};
      return configs[size_scale - 1];
    }

    // Wiki
    else if ((dataset == "L4_wiki_ts_200M_uint64")||(dataset == "L3_wiki_ts_200M_uint64")||(dataset == "L2_wiki_ts_200M_uint64")||(dataset == "L1_wiki_ts_200M_uint64"))
	{
      Configs configs = {{27, 8},
                         {26, 15},
                         {25, 20},
                         {24, 25},
                         {23, 40},
                         {22, 70},
                         {21, 125},
                         {20, 250},
                         {11, 45},
                         {17, 135}};
      return configs[size_scale - 1];
    }
    else{
      Configs configs = {{27, 8},
                         {26, 15},
                         {25, 20},
                         {24, 25},
                         {23, 40},
                         {22, 70},
                         {21, 125},
                         {20, 250},
                         {11, 45},
                         {17, 135}};
      return configs[size_scale - 1];
    }

    std::cerr << "No tuning config for this file and size_scale" << std::endl;
    throw;
  }

  void SetParameters(const std::string& dataset) {
    const std::pair<size_t, size_t> config = GetConfig(dataset);
    num_radix_bits_ = config.first;
    max_error_ = config.second;
    parameters_set_ = true;
  }

  rs::RadixSpline<KeyType> rs_;
  size_t num_radix_bits_;
  size_t max_error_;
  bool parameters_set_ = false;
};
