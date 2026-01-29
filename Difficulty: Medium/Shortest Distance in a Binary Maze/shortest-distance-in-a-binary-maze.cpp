// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();

        int sx = source.first;
        int sy = source.second;
        int dx = destination.first;
        int dy = destination.second;

        if (grid[sx][sy] == 0 || grid[dx][dy] == 0)
            return -1;

        if (sx == dx && sy == dy)
            return 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        queue<pair<int,int>> q;
        q.push({sx, sy});

        vector<vector<int>> dist(n, vector<int>(m, -1));
        dist[sx][sy] = 0;

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;

                    if (nr == dx && nc == dy)
                        return dist[nr][nc];

                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};
