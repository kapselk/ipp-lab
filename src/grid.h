#ifndef _GRID_LIB
#define _GRID_LIB

#include <vector>
#include <bitset>

using namespace std;

class Grid {
    private:
        int k_;
        vector<int> n_;
    
    public:
        Grid(int k, const vector<int>& n);
        int getK() { return k_; }
        const vector<int>& getN() { return n_; }
        void setK(int k) { k_ = k; }
        void setN(const vector<int> &n) { n_ = n; }
};

#endif