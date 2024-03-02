#ifndef _SCANNER_LIB
#define _SCANNER_LIB

#include <vector>
#include <bitset>

#include "grid.h"
#include "const.h"

Grid readGrid();
bitset<M> readBoard(int n);
bool readNewline();
bool readEof();

#endif