#ifndef _GRID_LIB
#define _GRID_LIB

#include <vector>
#include <bitset>

class Grid {
    private:
        int k_;
        vector<int> n_;
    
    public:
        Grid(int k, const vector<int>& n);
        int getK() { return k_; }
        const vector<int>& getN() { return n_; }
        void setK() { k_ = k; }
        void setN(const vector<int> &n) { n_ = n; }
};

#endif