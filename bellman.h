
#ifndef BELLMAN_H
#define BELLMAN_H

#include <bits/stdc++.h>
using namespace std;

void BF(int G[20][20], int n, char start_vertex, int BFValue[], int BFPrev[]);
string BF_Path(int graph[20][20], int num_vertices, char start_char, char goal_char);

#endif // BELLMAN_H





