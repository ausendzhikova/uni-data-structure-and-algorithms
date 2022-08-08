#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


char graph[25][25];
int adjMatrix[25][25];
bool visited[25][25];

int vertexCount = 0, edgesCount = 0;
int hamiltonPathsCount = 0;

int hasWayCount = 0;



//0 -s,  1- way, 2- x, 3-e
int getType(int x, int y) {
    if (graph[x][y] == 's') return 0;
    if (graph[x][y] == '-')return 1;
    if (graph[x][y] == 'x') return 2;
    if (graph[x][y] == 'e') return 3;
    return 10;
}

bool isValid(int x, int y) {
    if (x < 0 || x >= vertexCount || y < 0 || y >= edgesCount || visited[x][y] == 1 || adjMatrix[x][y] == 0 || getType(x, y) == 2) {
        return false;
    }
    return true;
}

bool isEndNear(int x, int y) {
    if (getType(x - 1, y) == 3 || getType(x + 1, y) == 3 || getType(x, y - 1) == 3 || getType(x, y + 1) == 3) {
        return true;
    }
    return false;
}

void dfs(int x, int y,int counter) {
   
    if (isEndNear(x, y) && hasWayCount == counter) {
        hamiltonPathsCount++;
    }

   
    if (isValid(x-1,y) && getType(x - 1, y) == 1 ) {
        visited[x - 1][y] = 1;
        dfs(x - 1, y,++counter);
        --counter;
        visited[x - 1][y] = 0;
    }

    if (isValid(x + 1, y) && getType(x + 1, y) == 1) {
        visited[x + 1][y] = 1;
        dfs(x + 1, y,++counter);
        --counter;
        visited[x + 1][y] = 0;
    }

    if (isValid(x, y - 1) && getType(x, y - 1) == 1) {
        visited[x][y - 1] = 1;
        dfs(x, y - 1,++counter);
        --counter;
        visited[x][y - 1] = 0;
    }

    if (isValid(x, y + 1) && getType(x, y + 1) == 1) {
        visited[x][y + 1] = 1;
        dfs(x, y + 1,++counter);
        --counter;
        visited[x][y + 1] = 0;
    }

   
}

int main() {

    cin >> vertexCount >> edgesCount;
    int x = -1, y = -1;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < edgesCount; j++) {
            char symb;
            cin >> symb;
            graph[i][j] = symb;
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;
            visited[i][j] = 0;
            if (symb == 's') {
                x = i;
                y = j;
            }
            if (symb == '-') {
                hasWayCount++;
            }
        }

    }
    dfs(x, y,0);

    cout << hamiltonPathsCount << "\n";

}