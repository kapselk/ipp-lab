#ifndef _GRID_LIB
#define _GRID_LIB

#include <vector>
#include <bitset>

using namespace std;

class Grid {
    private:
        int k_;
        vector<int> n_;
        vector<size_t> pref_;
    
    public:
        Grid(int k, const vector<int>& n);
        int getK() const { return k_; }
        const vector<int>& getN() const { return n_; }
        const vector<size_t>& getPref() const { return pref_; }
        void setK(int k) { k_ = k; }
        void setN(const vector<int> &n) { n_ = n; }
        size_t position(const vector<int> &cord) const;
        size_t move(size_t id, int axis, int delta) const;
};

#endif