#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position {
    int row;
    int col;
    int distance;
};

int main() {
    int R, C;
    cin >> R >> C;
    
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    
    int startRow, startCol, endRow, endCol;
    cin >> startRow >> startCol;
    cin >> endRow >> endCol;
    
    queue<Position> q;
    q.push({startRow, startCol, 0});
    
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[startRow][startCol] = true;
    
    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};
    
    int shortestPath = -1; 
    
    while (!q.empty()) {
        Position current = q.front();
        q.pop();
        
        if (current.row == endRow && current.col == endCol) {
            shortestPath = current.distance;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dRow[i];
            int newCol = current.col + dCol[i];
            
            if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C) {
                if (grid[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol, current.distance + 1});
                }
            }
        }
    }
    
    cout << shortestPath << endl;
    
    return 0;
}