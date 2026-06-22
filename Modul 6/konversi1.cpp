#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> vertices(N);

    for (int i = 0; i < N; i++) {
        cin >> vertices[i];
    }

    int M;
    cin >> M;

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        char startVertex, endVertex;
        int weight;
        cin >> startVertex >> endVertex >> weight;

        int startIndex = 0, endIndex = 0;

        for (int j = 0; j < N; j++) {
            if (vertices[j] == startVertex) {
                startIndex = j;
            }
            if (vertices[j] == endVertex) {
                endIndex = j;
            }
        }
        matrix[startIndex][endIndex] = weight;
    }

    cout << "Adjacency Matrix:" << endl;

    cout << "  ";
    for (int i = 0; i < N; i++) {
        cout << vertices[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << vertices[i] << " ";
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}