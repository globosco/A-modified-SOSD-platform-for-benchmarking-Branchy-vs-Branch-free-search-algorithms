#include "benchmarks/benchmark_rmi.h"

#include <string>

#include "benchmark.h"
#include "benchmarks/common.h"
#include "competitors/rmi_search.h"

#define NAME2(a, b) NAME2_HIDDEN(a, b)
#define NAME2_HIDDEN(a, b) a##b

#define NAME3(a, b, c) NAME3_HIDDEN(a, b, c)
#define NAME3_HIDDEN(a, b, c) a##b##c

#define NAME5(a, b, c, d, e) NAME5_HIDDEN(a, b, c, d, e)
#define NAME5_HIDDEN(a, b, c, d, e) a##b##c##d##e

#define run_rmi_binary(dtype, name, suffix, variant)                         \
  if (filename.find("/" #name "_" #dtype) != std::string::npos) {            \
    benchmark                                                                \
        .template Run<RMI_B<NAME2(dtype, _t), variant,                       \
                            NAME5(name, _, dtype, _, suffix)::BUILD_TIME_NS, \
                            NAME5(name, _, dtype, _, suffix)::RMI_SIZE,      \
                            NAME5(name, _, dtype, _, suffix)::NAME,          \
                            NAME5(name, _, dtype, _, suffix)::lookup,        \
                            NAME5(name, _, dtype, _, suffix)::load,          \
                            NAME5(name, _, dtype, _, suffix)::cleanup>>();   \
  }

#define run_rmi_binary_pareto_1(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
}

#define run_rmi_binary_pareto_2(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
}

#define run_rmi_binary_pareto_3(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
}

  #define run_rmi_binary_pareto_4(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
  run_rmi_binary(dtype, name, 3, 3);    \
}

#define run_rmi_binary_pareto_5(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);     \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
  run_rmi_binary(dtype, name, 3, 3);    \
  run_rmi_binary(dtype, name, 4, 4);    \
}

#define run_rmi_binary_pareto_6(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
  run_rmi_binary(dtype, name, 3, 3);    \
  run_rmi_binary(dtype, name, 4, 4);    \
  run_rmi_binary(dtype, name, 5, 5);  \
}

#define run_rmi_binary_pareto_7(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
  run_rmi_binary(dtype, name, 3, 3);    \
  run_rmi_binary(dtype, name, 4, 4);    \
  run_rmi_binary(dtype, name, 5, 5);  \
  run_rmi_binary(dtype, name, 6, 6);  \
}

#define run_rmi_binary_pareto_8(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
  run_rmi_binary(dtype, name, 3, 3);    \
  run_rmi_binary(dtype, name, 4, 4);    \
  run_rmi_binary(dtype, name, 5, 5);  \
  run_rmi_binary(dtype, name, 6, 6);  \
  run_rmi_binary(dtype, name, 7, 7);  \
}

#define run_rmi_binary_pareto_9(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
  run_rmi_binary(dtype, name, 3, 3);    \
  run_rmi_binary(dtype, name, 4, 4);    \
  run_rmi_binary(dtype, name, 5, 5);  \
  run_rmi_binary(dtype, name, 6, 6);  \
  run_rmi_binary(dtype, name, 7, 7);  \
  run_rmi_binary(dtype, name, 8, 8);  \
}
#define run_rmi_binary_pareto_10(dtype, name)  \
{                                         \
  run_rmi_binary(dtype, name, 0, 0);      \
  run_rmi_binary(dtype, name, 1, 1);    \
  run_rmi_binary(dtype, name, 2, 2);    \
  run_rmi_binary(dtype, name, 3, 3);    \
  run_rmi_binary(dtype, name, 4, 4);    \
  run_rmi_binary(dtype, name, 5, 5);  \
  run_rmi_binary(dtype, name, 6, 6);  \
  run_rmi_binary(dtype, name, 7, 7);  \
  run_rmi_binary(dtype, name, 8, 8);  \
  run_rmi_binary(dtype, name, 9, 9);  \
}

#define run_rmi_binary_pareto(dtype, name)  \
  {                                         \
    run_rmi_binary(dtype, name, 0, 0);      \
    if (pareto) {                           \
      run_rmi_binary(dtype, name, 1, 1);    \
      run_rmi_binary(dtype, name, 2, 2);    \
      run_rmi_binary(dtype, name, 3, 3);    \
      run_rmi_binary(dtype, name, 4, 4);    \
      if (benchmark.uses_binary_search()) { \
        run_rmi_binary(dtype, name, 5, 5);  \
        run_rmi_binary(dtype, name, 6, 6);  \
        run_rmi_binary(dtype, name, 7, 7);  \
        run_rmi_binary(dtype, name, 8, 8);  \
        run_rmi_binary(dtype, name, 9, 9);  \
      }                                     \
    }                                       \
  }

#define run_rmi_binary_pareto_30(dtype, name)  \
  {                                         \
    run_rmi_binary(dtype, name, 0, 0);      \
    run_rmi_binary(dtype, name, 1, 1);    \
    run_rmi_binary(dtype, name, 2, 2);    \
    run_rmi_binary(dtype, name, 3, 3);    \
    run_rmi_binary(dtype, name, 4, 4);    \
    run_rmi_binary(dtype, name, 5, 5);  \
    run_rmi_binary(dtype, name, 6, 6);  \
    run_rmi_binary(dtype, name, 7, 7);  \
    run_rmi_binary(dtype, name, 8, 8);  \
    run_rmi_binary(dtype, name, 9, 9);  \
    run_rmi_binary(dtype, name, 10, 10);      \
    run_rmi_binary(dtype, name, 11, 11);    \
    run_rmi_binary(dtype, name, 12, 12);    \
    run_rmi_binary(dtype, name, 13, 13);    \
    run_rmi_binary(dtype, name, 14, 14);    \
    run_rmi_binary(dtype, name, 15, 15);  \
    run_rmi_binary(dtype, name, 16, 16);  \
    run_rmi_binary(dtype, name, 17, 17);  \
    run_rmi_binary(dtype, name, 18, 18);  \
    run_rmi_binary(dtype, name, 19, 19);  \
    run_rmi_binary(dtype, name, 20, 20);      \
    run_rmi_binary(dtype, name, 21, 21);    \
    run_rmi_binary(dtype, name, 22, 22);    \
    run_rmi_binary(dtype, name, 23, 23);    \
    run_rmi_binary(dtype, name, 24, 24);    \
    run_rmi_binary(dtype, name, 25, 25);  \
    run_rmi_binary(dtype, name, 26, 26);  \
    run_rmi_binary(dtype, name, 27, 27);  \
    run_rmi_binary(dtype, name, 28, 28);  \
    run_rmi_binary(dtype, name, 29, 29);  \
  }

template <template <typename> typename Searcher>
void benchmark_32_rmi(sosd::Benchmark<uint32_t, Searcher>& benchmark,
                      bool pareto, const std::string& filename) {

  // run_rmi_binary_pareto_1(uint32, L1_books_200M)
  // run_rmi_binary_pareto_1(uint32, L2_books_200M)
  // run_rmi_binary_pareto_1(uint32, L3_books_200M)
  // run_rmi_binary_pareto_1(uint32, L4_books_200M)

  //BEST MODELS
  // run_rmi_binary_pareto_3(uint32, L1_books_200M)
  // run_rmi_binary_pareto_9(uint32, L2_books_200M)
  // run_rmi_binary_pareto_10(uint32, L3_books_200M)
  // run_rmi_binary_pareto_10(uint32, L4_books_200M)

  // run_rmi_binary_pareto_30(uint32, L1_books_200M);
  // run_rmi_binary_pareto_30(uint32, L2_books_200M);
  // run_rmi_binary_pareto_30(uint32, L3_books_200M);
  // run_rmi_binary_pareto_30(uint32, L4_books_200M);
  // run_rmi_binary_pareto(uint32, books_200M);
  // run_rmi_binary_pareto(uint32, normal_200M);
  // run_rmi_binary_pareto(uint32, lognormal_200M);
  // run_rmi_binary_pareto(uint32, uniform_dense_200M);
  // run_rmi_binary_pareto(uint32, uniform_sparse_200M);
}

template <template <typename> typename Searcher>
void benchmark_64_rmi(sosd::Benchmark<uint64_t, Searcher>& benchmark,
                      bool pareto, const std::string& filename) {

  // run_rmi_binary_pareto_1(uint64, L1_books_200M);
  // run_rmi_binary_pareto_1(uint64, L2_books_200M);
  // run_rmi_binary_pareto_1(uint64, L3_books_200M);
  // run_rmi_binary_pareto_1(uint64, L4_books_200M);
  //
  // run_rmi_binary_pareto_1(uint64, L1_fb_200M);
  // run_rmi_binary_pareto_1(uint64, L2_fb_200M);
  // run_rmi_binary_pareto_1(uint64, L3_fb_200M);
  // run_rmi_binary_pareto_1(uint64, L4_fb_200M);
  //
  // run_rmi_binary_pareto_1(uint64, L1_osm_cellids_200M);
  // run_rmi_binary_pareto_1(uint64, L2_osm_cellids_200M);
  // run_rmi_binary_pareto_1(uint64, L3_osm_cellids_200M);
  // run_rmi_binary_pareto_1(uint64, L4_osm_cellids_200M);
  //
  // run_rmi_binary_pareto_1(uint64, L1_wiki_ts_200M);
  // run_rmi_binary_pareto_1(uint64, L2_wiki_ts_200M);
  // run_rmi_binary_pareto_1(uint64, L3_wiki_ts_200M);
  // run_rmi_binary_pareto_1(uint64, L4_wiki_ts_200M);

  //UNIFORM MORIN
  // run_rmi_binary_pareto_6(uint64, uniform_4);
  // // run_rmi_binary_pareto_6(uint64, uniform_5);
  // run_rmi_binary_pareto_6(uint64, uniform_6);
  // // run_rmi_binary_pareto_8(uint64, uniform_7);
  // run_rmi_binary_pareto_10(uint64, uniform_8);
  // // run_rmi_binary_pareto_10(uint64, uniform_9);
  // run_rmi_binary_pareto_10(uint64, uniform_10);
  // // run_rmi_binary_pareto_10(uint64, uniform_11);
  // run_rmi_binary_pareto_10(uint64, uniform_12);
  // // run_rmi_binary_pareto_10(uint64, uniform_13);
  // run_rmi_binary_pareto_10(uint64, uniform_14);
  // // run_rmi_binary_pareto_10(uint64, uniform_15);
  // run_rmi_binary_pareto_10(uint64, uniform_16);
  // // run_rmi_binary_pareto_10(uint64, uniform_17);
  // run_rmi_binary_pareto_10(uint64, uniform_18);
  // // run_rmi_binary_pareto_10(uint64, uniform_19);
  // run_rmi_binary_pareto_10(uint64, uniform_20);
  // // run_rmi_binary_pareto_10(uint64, uniform_21);
  // run_rmi_binary_pareto_10(uint64, uniform_22);
  // // run_rmi_binary_pareto_10(uint64, uniform_23);
  // run_rmi_binary_pareto_10(uint64, uniform_24);
  // // run_rmi_binary_pareto_10(uint64, uniform_25);
  // run_rmi_binary_pareto_10(uint64, uniform_26);
  // // run_rmi_binary_pareto_10(uint64, uniform_27);
  // run_rmi_binary_pareto_10(uint64, uniform_28);
  // // run_rmi_binary_pareto_10(uint64, uniform_29);

  //BEST MODEL
  // run_rmi_binary_pareto_6(uint64, L1_books_200M);
  // run_rmi_binary_pareto_10(uint64, L2_books_200M);
  // run_rmi_binary_pareto_10(uint64, L3_books_200M);
  // run_rmi_binary_pareto_10(uint64, L4_books_200M);
  //
  // run_rmi_binary_pareto_8(uint64, L1_fb_200M);
  // run_rmi_binary_pareto_9(uint64, L2_fb_200M);
  // run_rmi_binary_pareto_10(uint64, L3_fb_200M);
  // run_rmi_binary_pareto_10(uint64, L4_fb_200M);
  // run_rmi_binary_pareto_10(uint64, L4_fb_200M_no_outlayers);
  //
  // run_rmi_binary_pareto_10(uint64, L1_osm_cellids_200M);
  // run_rmi_binary_pareto_10(uint64, L2_osm_cellids_200M);
  // run_rmi_binary_pareto_10(uint64, L3_osm_cellids_200M);
  // run_rmi_binary_pareto_10(uint64, L4_osm_cellids_200M);
  //
  // run_rmi_binary_pareto_8(uint64, L1_wiki_ts_200M);
  // run_rmi_binary_pareto_10(uint64, L2_wiki_ts_200M);
  // run_rmi_binary_pareto_10(uint64, L3_wiki_ts_200M);
  // run_rmi_binary_pareto_10(uint64, L4_wiki_ts_200M);

  //SY-RMI
  // run_rmi_binary_pareto_30(uint64, L1_books_200M);
  // run_rmi_binary_pareto_30(uint64, L2_books_200M);
  // run_rmi_binary_pareto_30(uint64, L3_books_200M);
  // run_rmi_binary_pareto_30(uint64, L4_books_200M);
  // run_rmi_binary_pareto_30(uint64, L1_fb_200M);
  // run_rmi_binary_pareto_30(uint64, L2_fb_200M);
  // run_rmi_binary_pareto_30(uint64, L3_fb_200M);
  // run_rmi_binary_pareto_30(uint64, L4_fb_200M);
  // run_rmi_binary_pareto_30(uint64, L1_osm_cellids_200M);
  // run_rmi_binary_pareto_30(uint64, L2_osm_cellids_200M);
  // run_rmi_binary_pareto_30(uint64, L3_osm_cellids_200M);
  // run_rmi_binary_pareto_30(uint64, L4_osm_cellids_200M);
  // run_rmi_binary_pareto_30(uint64, L1_wiki_ts_200M);
  // run_rmi_binary_pareto_30(uint64, L2_wiki_ts_200M);
  // run_rmi_binary_pareto_30(uint64, L3_wiki_ts_200M);
  // run_rmi_binary_pareto_30(uint64, L4_wiki_ts_200M);


  //Old Version
  // run_rmi_binary_pareto(uint64, fb_200M);
  // run_rmi_binary_pareto(uint64, osm_cellids_200M);
  // run_rmi_binary_pareto(uint64, wiki_ts_200M);
  // run_rmi_binary_pareto(uint64, books_200M);
  //
  // run_rmi_binary_pareto(uint64, osm_cellids_400M);
  // run_rmi_binary_pareto(uint64, osm_cellids_600M);
  // run_rmi_binary_pareto(uint64, osm_cellids_800M);
  //
  // run_rmi_binary_pareto(uint64, books_400M);
  // run_rmi_binary_pareto(uint64, books_600M);
  // run_rmi_binary_pareto(uint64, books_800M);
  //
  // run_rmi_binary_pareto(uint64, normal_200M);
  // run_rmi_binary_pareto(uint64, lognormal_200M);
  // run_rmi_binary_pareto(uint64, uniform_dense_200M);
  // run_rmi_binary_pareto(uint64, uniform_sparse_200M);
}

INSTANTIATE_TEMPLATES_RMI(benchmark_32_rmi, uint32_t);
INSTANTIATE_TEMPLATES_RMI(benchmark_64_rmi, uint64_t);
