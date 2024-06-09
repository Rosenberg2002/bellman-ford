#include "tsm.h"

//* Trường hợp size <= 10
void TSP(int G[20][20], vector<int>& path, vector<bool>& visited, int currPos, int n, int count, int cost, int& ans, vector<int>& bestPath) {
    if (count == n && G[currPos][path[0]] > 0) {
        if (ans > cost + G[currPos][path[0]]) {
            ans = cost + G[currPos][path[0]];
            bestPath = path;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && G[currPos][i] > 0) {
            visited[i] = true;
            path.push_back(i);

            TSP(G, path, visited, i, n, count + 1, cost + G[currPos][i], ans, bestPath);

            visited[i] = false;
            path.pop_back();
        }
    }
}

string Traveling(int G[20][20], int n, char start) {
    vector<int> path;
    vector<bool> visited(n, false);
    int startIndex = start - 'A';

    path.push_back(startIndex);
    visited[startIndex] = true;
    int ans = INT_MAX;
    vector<int> bestPath;

    TSP(G, path, visited, startIndex, n, 1, 0, ans, bestPath);

    string result;
    for (int i : bestPath) {
        result += char(i + 'A');
        result += " ";
    }
    result += start;

    return result;
}

//*Xài cho trường hợp size > 10
// string TSP(int G[20][20], int n, int start) {
//     vector<vector<int>> dp(1 << n, vector<int>(n, INF));
//     vector<vector<int>> parent(1 << n, vector<int>(n, -1));
//     dp[1 << start][start] = 0;

//     for (int mask = 0; mask < (1 << n); mask++) {
//         for (int u = 0; u < n; u++) {
//             if ((mask & (1 << u)) == 0) {
//                 continue;
//             }
//             for (int v = 0; v < n; v++) {
//                 if ((mask & (1 << v)) != 0) {
//                     continue;
//                 }
//                 if (G[u][v] != 0 && dp[mask][u] != INF) {
//                     int newMask = mask | (1 << v);
//                     if (dp[newMask][v] > dp[mask][u] + G[u][v]) {
//                         dp[newMask][v] = dp[mask][u] + G[u][v];
//                         parent[newMask][v] = u;
//                     }
//                 }
//             }
//         }
//     }

//     int mask = (1 << n) - 1;
//     int last = start;
//     for (int i = 0; i < n; i++) {
//         if (dp[mask][i] + G[i][start] < dp[mask][last] + G[last][start]) {
//             last = i;
//         }
//     }

//     vector<int> path;
//     while (last != -1) {
//         path.push_back(last);
//         int next = parent[mask][last];
//         mask = mask ^ (1 << last);
//         last = next;
//     }

//     reverse(path.begin(), path.end());
//     string result;
//     for (int i : path) {
//         result += static_cast<char>(i + 'A');
//         result += " ";
//     }
//     result += static_cast<char>(start + 'A');
//     return result;
// }

// string Traveling(int G[20][20], int n, char start) {
//     int startIndex = start - 'A';
//     string result = TSP(G, n, startIndex);
//     return result;
// }
