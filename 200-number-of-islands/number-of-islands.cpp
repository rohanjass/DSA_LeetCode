class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (auto d : dir) {
                            int nr = r + d.first;
                            int nc = c + d.second;

                            if (nr < 0 || nc < 0 || nr == grid.size() ||
                                nc == grid[0].size() || grid[nr][nc] != '1')
                                continue;
                            

                            q.push({nr,nc});
                            grid[nr][nc]='0';
                        }
                    }
                }
            }
        }
        return res;
    }
};