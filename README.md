# HybridMap

An attempt to build a hashmap that is faster than stl, albeit for a smaller set of use-cases.

## Assumptions
- Hash is a double


# Benchmarks
- use perf and some other tools


# Notes - del later
## GCC unordered_map implementation
https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/unordered_map.h
- note uses allocator<pair<T,H>>