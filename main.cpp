#include <bits/stdc++.h>
#include "tsm.h"
#include "bellman.h"

int main()
{
    int n = 8;
    int Graph[20][20] = {
        {0, 42, 0, 0, 20, 80, 0, 0},
        {42, 0, 28, 94, 0, 72, 56, 0},
        {0, 28, 0, 0, 65, 0, 0, 51},
        {0, 94, 0, 0, 89, 99, 85, 0},
        {20, 0, 65, 89, 0, 0, 21, 57},
        {80, 72, 0, 99, 0, 0, 0, 19},
        {0, 56, 0, 85, 21, 0, 0, 44},
        {0, 0, 51, 0, 57, 19, 44, 0}};

    int BFValue[20];
    int BFPrev[20];
    for (int i = 0; i < n; i++)
    {
        BFValue[i] = -1;
        BFPrev[i] = -1;
    }

    int num_vertices = 12;
    int GraphTVL[20][20] = {
        {0, 85, 0, 0, 0, 0, 92, 0, 50, 83, 21, 0},
        {85, 0, 0, 0, 0, 40, 0, 0, 0, 35, 89, 0},
        {0, 0, 0, 42, 97, 0, 55, 56, 0, 0, 0, 28},
        {0, 0, 42, 0, 0, 22, 0, 0, 0, 0, 0, 69},
        {0, 0, 97, 0, 0, 78, 0, 0, 40, 0, 0, 0},
        {0, 40, 0, 22, 78, 0, 49, 0, 0, 0, 63, 14},
        {92, 0, 55, 0, 0, 49, 0, 53, 0, 72, 0, 25},
        {0, 0, 56, 0, 0, 0, 53, 0, 31, 0, 78, 0},
        {50, 0, 0, 0, 40, 0, 0, 31, 0, 93, 0, 61},
        {83, 35, 0, 0, 0, 0, 72, 0, 93, 0, 77, 0},
        {21, 89, 0, 0, 0, 63, 0, 78, 0, 77, 0, 84},
        {0, 0, 28, 69, 0, 14, 25, 0, 61, 0, 84, 0}};

    cout << "Function BF: " << endl;
    for (int i = 0; i < n; i++)
    {
        BF(Graph, n, 'E', BFValue, BFPrev);
        cout << "step" << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++)
        {
            cout << BFValue[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << BFPrev[j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "Function BF_Path: " << BF_Path(Graph, n, 'A', 'D') << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "TSP Functions: " << Traveling(GraphTVL, num_vertices, 'A') << endl;
    cout << "------------------------------------" << endl;

    return 0;
}

//* Cách chạy: g++ -o main main.cpp bellman.cpp tsm.cpp -> ./main