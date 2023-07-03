class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        while (build_wall(grid)) {}
        return res;
    }
    
private:
    int res = 0;
    int dfs(vector<vector<int>>& grid, int i, int j, int k, int& wall, vector<vector<int>>& infected_grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] < 0) return 0;
        if (grid[i][j] == k) {
            if (infected_grid[i][j] > 0) wall++; // only build wall on boundary
            return 0;
        }
        
        if (grid[i][j] == 1) {
            grid[i][j] = k; // grid[i][j] = 1 -> k, not boundary, don't build wall
            return dfs(grid, i + 1, j, k, wall, infected_grid) + dfs(grid, i, j + 1, k, wall, infected_grid)
                 + dfs(grid, i - 1, j, k, wall, infected_grid) + dfs(grid, i, j - 1, k, wall, infected_grid);
        }
        
        grid[i][j] = k; // grid[i][j] = 0 -> k
        infected_grid[i][j]++; // record the boundary
        wall++; // only build wall on boundary
        return 1;
    }
    
    bool build_wall(vector<vector<int>>& grid) {
        int k = 1, m = grid.size(), n = grid[0].size(), max_infected = -1, K = 0, add_wall = 0;
        vector<vector<int>> infected_grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int wall = 0, infected = dfs(grid, i, j, ++k, wall, infected_grid);
                    if (max_infected < infected) {
                        max_infected = infected;
                        add_wall = wall;
                        K = k;
                    }
                }
            }
        }
        
        if (k == 1) return false; // no free infected area exists, stop
        
        res += add_wall;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) grid[i][j] = (grid[i][j] == K && infected_grid[i][j] <= 1) ? infected_grid[i][j] - 1 : 1; // set area inside new wall as -1, else where as 1
            }
        }
        return true;
    }
};