class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();

        set<pair<int, int>> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<> > minHeap;

        minHeap.push({grid[0][0], 0, 0});
        visited.insert({0, 0});


        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            int t = curr[0], r = curr[1], c = curr[2];
            minHeap.pop();

            if (r == N - 1 and c == N - 1) return t;
            
            for (auto& d: directions) {
                int nr = r + d[0], nc = c + d[1];
                if (min(nr, nc) < 0 || nr == N || nc == N || visited.contains({nr, nc})) continue;
                visited.insert({nr, nc});
                minHeap.push({max(t, grid[nr][nc]), nr, nc});
            }
        }
    }
};
