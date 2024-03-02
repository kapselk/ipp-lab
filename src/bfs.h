#ifndef _BFS_LIB
#define _BFS_LIB

#include <vector>
#include <bitset>
#include "grid.h"
#include "const.h"

size_t minDistance(const Grid &grid, const bitset<M> &board, const vector<int> &start, const vector<int> &end);
size_t minDistance(const Grid &grid, const bitset<M> &board, size_t start, size_t end);

#endif