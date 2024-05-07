// Ricardo Jiménez Ureña A01636825
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Node {
    int x, y, dist;
};

// Complexity: O(1)
bool isSafe(int x, int y, int M, int N, int maze[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE][MAX_SIZE]) {
    return (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMazeBacktracking(int x, int y, int M, int N, int maze[MAX_SIZE][MAX_SIZE], int solution[MAX_SIZE][MAX_SIZE]) {
    if (x == M - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y, M, N, maze, solution)) {
        solution[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (solveMazeBacktracking(nextX, nextY, M, N, maze, solution))
                return true;
        }

        solution[x][y] = 0;
    }
    return false;
}

// Complexity: O(M*N)
bool solveMazeBranchAndBound(int M, int N, int maze[MAX_SIZE][MAX_SIZE], int solution[MAX_SIZE][MAX_SIZE]) {
    int visited[MAX_SIZE][MAX_SIZE] = {0};
    queue<Node> q;

    Node s = {0, 0, 0};
    q.push(s);
    visited[0][0] = 1;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        int x = curr.x;
        int y = curr.y;

        if (x == M - 1 && y == N - 1) {
            solution[x][y] = 1;
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isSafe(nextX, nextY, M, N, maze, visited)) {
                visited[nextX][nextY] = 1;
                solution[nextX][nextY] = 1;
                Node adj = {nextX, nextY, curr.dist + 1};
                q.push(adj);
            }
        }
    }
    return false;
}

// Complexity: O(M*N)
void printSolution(int M, int N, int solution[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ifstream fin("in.txt");
    if (!fin) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    int M, N;
    fin >> M >> N;

    int maze[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fin >> maze[i][j];
        }
    }
    fin.close();

    int solution[MAX_SIZE][MAX_SIZE] = {0};

    cout << "Solution using Backtracking:" << endl;
    if (solveMazeBacktracking(0, 0, M, N, maze, solution)) {
        printSolution(M, N, solution);
    } else {
        cout << "No solution exists" << endl;
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            solution[i][j] = 0;

    cout << "Solution using Branch and Bound:" << endl;
    if (solveMazeBranchAndBound(M, N, maze, solution)) {
        printSolution(M, N, solution);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
