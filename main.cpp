#include <bits/stdc++.h>
#include "tsm.cpp"
#include "bellman.cpp"

using namespace std;

int main() {
    int G[20][20] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int n = 4;
    int BFValue[20];
    int BFPrev[20];
    BF(G, n, 'A', BFValue, BFPrev);
    cout << "Bellman-Ford Algorithm: " << BF_Path(G, n, 'A', 'D') << endl;
    
    char start = 'A';
    cout << "Traveling Salesman Problem: " << Traveling(G, n, start) << endl;

    return 0;
}