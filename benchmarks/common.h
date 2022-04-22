#include "config.h"
#include "searches/branching_binary_search.h"
#include "searches/branchless_binary_search.h"
#include "searches/branchless_binary_search_no_prefetch.h"
#include "searches/standard_binary_search_no_prefetch.h"
#include "searches/standard_binary_search.h"
#include "searches/interpolation_search.h"
#include "searches/linear_search.h"
#include "searches/bfs.h"
#include "searches/eytzinger_layout_search.h"
#include "searches/eytzinger_layout_search_no_prefetch.h"
#include "searches/kbbs.h"
#include "searches/kbfs.h"

#ifdef FAST_MODE
#define INSTANTIATE_TEMPLATES(func_name, type_name) \
  template void func_name<BranchingBinarySearch>(   \
      sosd::Benchmark<type_name, BranchingBinarySearch>&, bool)
#else
#define INSTANTIATE_TEMPLATES(func_name, type_name)               \
  template void func_name<LinearSearch>(                          \
      sosd::Benchmark<type_name, LinearSearch>&, bool);           \
  template void func_name<BranchingBinarySearch>(                 \
      sosd::Benchmark<type_name, BranchingBinarySearch>&, bool);  \
  template void func_name<BranchlessBinarySearch>(                \
      sosd::Benchmark<type_name, BranchlessBinarySearch>&, bool); \
  template void func_name<BranchlessBinarySearchNoPrefetch>(                \
      sosd::Benchmark<type_name, BranchlessBinarySearchNoPrefetch>&, bool); \
  template void func_name<StandardBinarySearchNoPrefetch>(                \
      sosd::Benchmark<type_name, StandardBinarySearchNoPrefetch>&, bool); \
  template void func_name<StandardBinarySearch>(                \
      sosd::Benchmark<type_name, StandardBinarySearch>&, bool); \
  template void func_name<InterpolationSearch>(                   \
      sosd::Benchmark<type_name, InterpolationSearch>&, bool);      \
  template void func_name<BFS_Search>(                              \
      sosd::Benchmark<type_name, BFS_Search>&, bool);                \
  template void func_name<EytzingerLayoutSearch>(                              \
      sosd::Benchmark<type_name, EytzingerLayoutSearch>&, bool);\
  template void func_name<EytzingerLayoutSearchNoPrefetch>(                              \
      sosd::Benchmark<type_name, EytzingerLayoutSearchNoPrefetch>&, bool);\
  template void func_name<KBBS_Search>(                              \
      sosd::Benchmark<type_name, KBBS_Search>&, bool);          \
  template void func_name<KBFS_Search>(                              \
      sosd::Benchmark<type_name, KBFS_Search>&, bool)
#endif

#ifdef FAST_MODE
#define INSTANTIATE_TEMPLATES_RMI(func_name, type_name)         \
  template void func_name<BranchingBinarySearch>(               \
      sosd::Benchmark<type_name, BranchingBinarySearch>&, bool, \
      const std::string&)
#else
#define INSTANTIATE_TEMPLATES_RMI(func_name, type_name)                     \
  template void func_name<LinearSearch>(                                    \
      sosd::Benchmark<type_name, LinearSearch>&, bool, const std::string&); \
  template void func_name<BranchingBinarySearch>(                           \
      sosd::Benchmark<type_name, BranchingBinarySearch>&, bool,             \
      const std::string&);                                                  \
  template void func_name<BranchlessBinarySearch>(                          \
      sosd::Benchmark<type_name, BranchlessBinarySearch>&, bool,            \
      const std::string&);                                                  \
  template void func_name<BranchlessBinarySearchNoPrefetch>(                          \
      sosd::Benchmark<type_name, BranchlessBinarySearchNoPrefetch>&, bool,            \
      const std::string&);                                                  \
      template void func_name<StandardBinarySearchNoPrefetch>(                          \
          sosd::Benchmark<type_name, StandardBinarySearchNoPrefetch>&, bool,            \
          const std::string&);                                                  \
  template void func_name<InterpolationSearch>(                             \
      sosd::Benchmark<type_name, InterpolationSearch>&, bool,               \
      const std::string&);                                                   \
  template void func_name<BFS_Search>(                                      \
      sosd::Benchmark<type_name, BFS_Search>&, bool,                        \
      const std::string&);                                                  \
  template void func_name<EytzingerLayoutSearch>(                                      \
      sosd::Benchmark<type_name, EytzingerLayoutSearch>&, bool,                        \
      const std::string&);                                                             \
  template void func_name<EytzingerLayoutSearchNoPrefetch>(                                      \
      sosd::Benchmark<type_name, EytzingerLayoutSearchNoPrefetch>&, bool,                        \
      const std::string&);                                                             \
  template void func_name<StandardBinarySearch>(                                      \
      sosd::Benchmark<type_name, StandardBinarySearch>&, bool,                        \
      const std::string&);                                                             \
      template void func_name<KBBS_Search>(                                      \
      sosd::Benchmark<type_name, KBBS_Search>&, bool,                        \
      const std::string&);                                                   \
  template void func_name<KBFS_Search>(                                      \
      sosd::Benchmark<type_name, KBFS_Search>&, bool,                        \
      const std::string&);
#endif
