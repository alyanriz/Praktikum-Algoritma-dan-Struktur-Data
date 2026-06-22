#include <iostream>
#include <vector>
using namespace std;

int R, C;
int startRow, startCol, endRow, endCol;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int totalPaths = 0;

int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

void dfs(int row, int col) {
    if (row == endRow && col == endCol) {
        totalPaths++;
        return;
    }
    
    visited[row][col] = true;
    
    for (int i = 0; i < 4; i++) {
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];
        
        if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C) {
            if (grid[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                dfs(newRow, newCol);
            }
        }
    }
    
    visited[row][col] = false;
}

int main() {
    cin >> R >> C;
    
    grid.assign(R, vector<int>(C));
    visited.assign(R, vector<bool>(C, false));
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    
    cin >> startRow >> startCol;
    cin >> endRow >> endCol;
    
    dfs(startRow, startCol);
    
    cout << totalPaths << endl;
    
    return 0;
}