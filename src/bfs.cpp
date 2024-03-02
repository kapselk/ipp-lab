#include "bfs.h"
#include <vector>
#include <bitset>

#include "grid.h"
#include "const.h"

size_t minDistance(const Grid &grid, const bitset<M> &board, const vector<int> &start, const vector<int> &end) {
    return minDistance(grid, board, grid.position(start), grid.position(end));
}

size_t minDistance(const Grid &grid, const bitset<M> &board, size_t start, size_t end) {
    bitset<M> visited;
    visited[start] = 1;
    int dist = 1;
    vector<size_t> now, next;
    now.push_back(start);
    while (!now.empty() || !next.empty()) {
        if (now.empty()) {
            now = next;
            next.clear();
            dist++;
        }
        for (size_t u : now) {
            if (u == end) {
                return dist;
            }
            for (int axis = 0; axis < grid.getK(); axis++) {
                size_t v = grid.move(u, axis, -1);
                if (!visited[v]) {
                    visited[v] = 1;
                    next.push_back(v);
                }
                v = grid.move(u, axis, 1);
                if (!visited[v]) {
                    visited[v] = 1;
                    next.push_back(v);
                }
            }
        }
    }
    return 0;
}