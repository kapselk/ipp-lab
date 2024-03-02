#include "grid.h"

Grid::Grid(int k, const vector<int> &n) {
    Grid::setK(k);
    Grid::setN(n);
    Grid::pref_.assign(k+1, 1);
    for (int i = 1; i <= k; i++) {
        Grid::pref_[i] = Grid::pref_[i-1] * (size_t) n[i];
    }
}

size_t Grid::position(const vector<int> &cord) const {
    size_t ret = 0;
    for (int i = 0; i < Grid::getK(); i++) {
        ret += Grid::getPref()[i] * (size_t) (cord[i] - 1);
    }
    return ret;
}

size_t Grid::move(size_t id, int axis, int delta) const {
    return id + (size_t) delta * Grid::getPref()[axis];
}