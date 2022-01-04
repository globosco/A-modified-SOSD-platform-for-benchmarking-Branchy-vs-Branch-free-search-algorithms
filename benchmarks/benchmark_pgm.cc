#include "benchmarks/benchmark_pgm.h"

#include "benchmark.h"
#include "benchmarks/common.h"
#include "competitors/pgm_index.h"

template <template <typename> typename Searcher>
void benchmark_32_pgm(sosd::Benchmark<uint32_t, Searcher>& benchmark,
                      bool pareto) {
       // benchmark.template Run<PGM<uint32_t, 3750>>();
       // benchmark.template Run<PGM<uint32_t, 15>>();
       // benchmark.template Run<PGM<uint32_t, 12>>();
       // benchmark.template Run<PGM<uint32_t, 4>>();
       // benchmark.template Run<PGM<uint32_t, 31500>>();
       // benchmark.template Run<PGM<uint32_t, 16>>();
       // benchmark.template Run<PGM<uint32_t, 114>>();
       // benchmark.template Run<PGM<uint32_t, 119>>();
       // benchmark.template Run<PGM<uint32_t, 121>>();
       // benchmark.template Run<PGM<uint32_t, 27>>();
       // benchmark.template Run<PGM<uint32_t, 8>>();
    // benchmark.template Run<PGM<uint32_t, 27>>();
    // benchmark.template Run<PGM<uint32_t, 3750>>();
    // benchmark.template Run<PGM<uint32_t, 31500>>();
    // benchmark.template Run<PGM<uint32_t, 121>>();
  // benchmark.template Run<PGM<uint32_t, 1875>>();
  // benchmark.template Run<PGM<uint32_t, 60>>();
  // benchmark.template Run<PGM<uint32_t, 15750>>();
  // benchmark.template Run<PGM<uint32_t, 1271>>();
  // benchmark.template Run<PGM<uint32_t, 203>>();
  // benchmark.template Run<PGM<uint32_t, 1271>>();
  // benchmark.template Run<PGM<uint32_t, 16>>();
  // benchmark.template Run<PGM<uint32_t, 48>>();
  // benchmark.template Run<PGM<uint32_t, 158>>();
  // benchmark.template Run<PGM<uint32_t, 68>>();

  //SOSD Classic
  benchmark.template Run<PGM<uint32_t, 16>>();
  if (pareto) {
    benchmark.template Run<PGM<uint32_t, 4>>();
    benchmark.template Run<PGM<uint32_t, 8>>();
    benchmark.template Run<PGM<uint32_t, 32>>();
    benchmark.template Run<PGM<uint32_t, 64>>();
    benchmark.template Run<PGM<uint32_t, 256>>();
    benchmark.template Run<PGM<uint32_t, 1024>>();
    benchmark.template Run<PGM<uint32_t, 2048>>();
    //if (benchmark.uses_binary_search()) {
      benchmark.template Run<PGM<uint32_t, 4096>>();
      benchmark.template Run<PGM<uint32_t, 8192>>();
    //}
  }
}

template <template <typename> typename Searcher>
void benchmark_64_pgm(sosd::Benchmark<uint64_t, Searcher>& benchmark,
                      bool pareto) {
  // benchmark.template Run<PGM<uint64_t, 1875>>();
  // benchmark.template Run<PGM<uint64_t, 15>>();
  // benchmark.template Run<PGM<uint64_t, 12>>();
  // benchmark.template Run<PGM<uint64_t, 4>>();
  // benchmark.template Run<PGM<uint64_t, 145>>();
  // benchmark.template Run<PGM<uint64_t, 27>>();
  // benchmark.template Run<PGM<uint64_t, 16>>();
  // benchmark.template Run<PGM<uint64_t, 1331>>();
  // benchmark.template Run<PGM<uint64_t, 30>>();
  // benchmark.template Run<PGM<uint64_t, 3788>>();
  // benchmark.template Run<PGM<uint64_t, 58>>();
  // benchmark.template Run<PGM<uint64_t, 17>>();
  // benchmark.template Run<PGM<uint64_t, 1182>>();
  // benchmark.template Run<PGM<uint64_t, 6>>();
  // benchmark.template Run<PGM<uint64_t, 11>>();
  // benchmark.template Run<PGM<uint64_t, 13>>();
  // benchmark.template Run<PGM<uint64_t, 57>>();
  // benchmark.template Run<PGM<uint64_t, 14>>();
  // benchmark.template Run<PGM<uint64_t, 8>>();
  // benchmark.template Run<PGM<uint64_t, 765>>();
  // benchmark.template Run<PGM<uint64_t, 43>>();
  // benchmark.template Run<PGM<uint64_t, 767>>();
  // benchmark.template Run<PGM<uint64_t, 44>>();
  // benchmark.template Run<PGM<uint64_t, 42>>();
  // benchmark.template Run<PGM<uint64_t, 15>>();
  // benchmark.template Run<PGM<uint64_t, 87>>();
  // benchmark.template Run<PGM<uint64_t, 89>>();
  // benchmark.template Run<PGM<uint64_t, 90>>();
  // benchmark.template Run<PGM<uint64_t, 13>>();
  // benchmark.template Run<PGM<uint64_t, 95>>();
  // benchmark.template Run<PGM<uint64_t, 20>>();
  // benchmark.template Run<PGM<uint64_t, 10>>();
  // benchmark.template Run<PGM<uint64_t, 606>>();
  // benchmark.template Run<PGM<uint64_t, 61>>();
  // benchmark.template Run<PGM<uint64_t, 607>>();
  // benchmark.template Run<PGM<uint64_t, 608>>();
  // benchmark.template Run<PGM<uint64_t, 59>>();
  // benchmark.template Run<PGM<uint64_t, 22>>();
  // benchmark.template Run<PGM<uint64_t, 546>>();
  // benchmark.template Run<PGM<uint64_t, 541>>();
  // benchmark.template Run<PGM<uint64_t, 540>>();
  // benchmark.template Run<PGM<uint64_t, 39>>();
  // benchmark.template Run<PGM<uint64_t, 45>>();
  // benchmark.template Run<PGM<uint64_t, 5>>();
    // benchmark.template Run<PGM<uint64_t, 27>>();
    // benchmark.template Run<PGM<uint64_t, 22>>();
  // benchmark.template Run<PGM<uint64_t, 1875>>();
  // benchmark.template Run<PGM<uint64_t, 16>>();
  // benchmark.template Run<PGM<uint64_t, 145>>();
  // benchmark.template Run<PGM<uint64_t, 1331>>();
  // benchmark.template Run<PGM<uint64_t, 30>>();
  // benchmark.template Run<PGM<uint64_t, 3788>>();
  // benchmark.template Run<PGM<uint64_t, 58>>();
  // benchmark.template Run<PGM<uint64_t, 1182>>();
  // benchmark.template Run<PGM<uint64_t, 57>>();
  // benchmark.template Run<PGM<uint64_t, 768>>();
  // benchmark.template Run<PGM<uint64_t, 87>>();
  // benchmark.template Run<PGM<uint64_t, 95>>();
  // benchmark.template Run<PGM<uint64_t, 20>>();
  // benchmark.template Run<PGM<uint64_t, 61>>();
  // benchmark.template Run<PGM<uint64_t, 1673>>();
  // benchmark.template Run<PGM<uint64_t, 542>>();
  // benchmark.template Run<PGM<uint64_t, 39>>();
  // benchmark.template Run<PGM<uint64_t, 60>>();
  // benchmark.template Run<PGM<uint64_t, 608>>();

  //SOSD Classic
  benchmark.template Run<PGM<uint64_t, 16>>();
  if (pareto) {
    benchmark.template Run<PGM<uint64_t, 4>>();
    benchmark.template Run<PGM<uint64_t, 8>>();
    benchmark.template Run<PGM<uint64_t, 32>>();
    benchmark.template Run<PGM<uint64_t, 64>>();
    benchmark.template Run<PGM<uint64_t, 256>>();
    benchmark.template Run<PGM<uint64_t, 1024>>();
    benchmark.template Run<PGM<uint64_t, 2048>>();
    //if (benchmark.uses_binary_search()) {
      benchmark.template Run<PGM<uint64_t, 4096>>();
      benchmark.template Run<PGM<uint64_t, 8192>>();
    //}
  }
}

INSTANTIATE_TEMPLATES(benchmark_32_pgm, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_pgm, uint64_t);
