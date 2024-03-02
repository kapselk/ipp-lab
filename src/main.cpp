#include <vector>
#include <bitset>
#include <iostream>

#include "grid.h"
#include "const.h"
#include "scanner.h"
#include "bfs.h"

using namespace std;

int main() {
    Grid grid = readGrid();
    readNewline();
    vector<int> start = readVector();
    readNewline();
    vector<int> end = readVector();
    readNewline();
    bitset<M> board = readBoard(grid.getPref()[grid.getK()]);

    size_t ans = minDistance(grid, board, start, end);
    
    if (ans == 0 && start != end) {
        cout << "The path between start and end doesn't exist.\n";
    } else {
        cout << ans << "\n";
    }
}