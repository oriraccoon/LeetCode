#include <vector>
using namespace std;

vector<int> dir_x = {0, 1, 1, 1, 0, -1, -1, -1};  // 시계방향 x 이동
vector<int> dir_y = {1, 1, 0, -1, -1, -1, 0, 1};  // 시계방향 y 이동

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows_size = grid.size();
        int cols_size = grid[0].size();

        // 시작점이 막혀있거나 종료점이 막혀있으면 경로가 없음
        if (grid[0][0] != 0 || grid[rows_size - 1][cols_size - 1] != 0) {
            return -1;
        }

        // BFS를 위한 초기 설정
        vector<vector<bool>> visited(rows_size, vector<bool>(cols_size, false));
        vector<pair<int, int>> queue;  // 직접 만든 큐
        queue.push_back(make_pair(0, 0));
        visited[0][0] = true;
        int distance = 1;  // 시작점도 거리 포함

        while (!queue.empty()) {
            vector<pair<int, int>> next_queue;
            for (int k = 0; k < queue.size(); k++) {
                int x = queue[k].first;
                int y = queue[k].second;

                // 목표 지점에 도달한 경우
                if (x == rows_size - 1 && y == cols_size - 1) {
                    return distance;
                }

                // 8방향 탐색
                for (int i = 0; i < 8; i++) {
                    int nxt_x = x + dir_x[i];
                    int nxt_y = y + dir_y[i];

                    if (nxt_x >= 0 && nxt_x < rows_size && nxt_y >= 0 && nxt_y < cols_size && 
                        grid[nxt_x][nxt_y] == 0 && !visited[nxt_x][nxt_y]) {
                        visited[nxt_x][nxt_y] = true;
                        next_queue.push_back(make_pair(nxt_x, nxt_y));
                    }
                }
            }
            queue = next_queue;  // 다음 레벨의 큐로 교체
            distance++;
        }

        return -1;  // 경로를 찾을 수 없는 경우
    }
};