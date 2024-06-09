#include "bellman.h"

void BF(int G[20][20], int n, char start_vertex, int BFValue[], int BFPrev[]) {
    int tempBFValue[20];
    int tempBFPrev[20];

    for (int i = 0; i < n; i++) {
        tempBFValue[i] = BFValue[i];
        tempBFPrev[i] = BFPrev[i];
    }

    if (BFValue[start_vertex - 'A'] == -1) {
        BFValue[start_vertex - 'A'] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (BFValue[i] == -1) {
            continue;  
        }

        for (int j = 0; j < n; j++) {
            if (G[i][j] != 0 && (tempBFValue[j] == -1 || tempBFValue[j] > BFValue[i] + G[i][j])) {
                tempBFValue[j] = BFValue[i] + G[i][j];
                tempBFPrev[j] = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == start_vertex - 'A') {
            continue;  
        }
        BFValue[i] = tempBFValue[i];
        BFPrev[i] = tempBFPrev[i];
    }
}

string BF_Path(int graph[20][20], int num_vertices, char start_char, char goal_char) {
    int BFValue[20];
    int BFPrev[20];

    for (int i = 0; i < num_vertices; i++) {
        BFValue[i] = -1;
        BFPrev[i] = -1;
    }

    for (int i = 0; i < num_vertices; i++) {
        BF(graph, num_vertices, start_char, BFValue, BFPrev);
    }

    int goal = goal_char - 'A';
    string path = "";

    while (goal != -1) {
        if (path != "") {
            path = " " + path;
        }
        path = (char)(goal + 'A') + path;
        goal = BFPrev[goal];
    }

    return path;
}