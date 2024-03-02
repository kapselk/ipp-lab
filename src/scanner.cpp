#include "scanner.h"
#include <vector>
#include <bitset>
#include <cstdio>
#include <cctype>

#include "grid.h"
#include "const.h"

char checkChar() {
    char c = getchar();
    ungetc(c, stdin);
    return c;
}

bool isNewline(char c) {
    return c == '\n' || c == '\r';
}

bool isEOF(char c) {
    return c == EOF;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

unsigned int readUInt() {
    int ret = 0;
    while(isDigit(checkChar())) {
        char c = getchar();
        ret = ret * 10 + (c - '0');
    }
    return ret;
}

void readSpaces() {
    while (isspace(checkChar())) {
        getchar();
    }
}

bool readNewline() {
    if (!isNewline(checkChar())) return false;
    getchar();
    return true;
}

bool readEof() {
    if (isNewline(checkChar())) readNewline();
    if (!isEOF(checkChar())) return false;
    getchar();
    return true;
}

vector<int> readVector() {
    vector<int> ret;
    readSpaces();
    while (!isNewline(checkChar()) && !isEOF(checkChar())) {
        ret.push_back(readUInt());
        readSpaces();
    }
    return ret;
}

Grid readGrid() {
    vector<int> n = readVector();
    int k = (int) n.size();
    Grid ret(k, n);
    return ret;
}

int hexDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'A' && c <= 'F') return (c - 'A') + 10;
    else return -1;
}

bitset<M> readBoard(int n) {
    bitset<M> ret;

    readSpaces();
    if (checkChar() == '0') {
        getchar(); getchar(); // 0x
        int setd = 0;
        while (!isNewline(checkChar())) {
            int h = hexDigit(checkChar());
            getchar();
            for (int i = 3; i >= 0; i--) {
                int v = (1 << i) & h;
                ret[setd++] = (v > 0 ? true : false);
            }
        }
        for (int i = 0; i < setd; i++) {
            bool tmp = ret[i];
            ret[i] = ret[setd - i - 1];
            ret[setd] = tmp;
        }
    } else {
       getchar();
        vector<int> params = readVector();
        // size of params = 5
        unsigned int a, b, m, r, s0;
        a = params[0]; b = params[1]; m = params[2];
        r = params[3]; s0 = params[4];
        unsigned int s = s0;
        for (int i = 1; i <= (int) r; i++) {
            s = ((s * a) % m + b) % m;
            unsigned int w = s % n;
            size_t j = w;
            while (j < (size_t) n) {
                ret[j] = 1;
                j += ((size_t) 1 << 32);
            }
        }
    }
    return ret;
}