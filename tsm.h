#ifndef TSM_H
#define TSM_H

#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

void TSP(int G[20][20], vector<int> &path, vector<bool> &visited, int currPos, int n, int count, int cost, int &ans, vector<int> &bestPath);
string Traveling(int G[20][20], int n, char start);
string TSP(int G[20][20], int n, int start);
string Traveling(int G[20][20], int n, char start);

#endif // TSM_H
