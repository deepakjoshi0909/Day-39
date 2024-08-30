class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int x,int y,vector<vector<int>>& grid,queue<pair<int,int>>& q){
        int n = grid.size();
        grid[x][y] = 2;
        q.push({x,y});

        for(auto d : dir){
            int newX = x + d[0];
            int newY = y + d[1];

            if(newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 1){
                dfs(newX,newY,grid,q);
            }
        }

    }

    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        bool found = false;
        int n = grid.size();

        for(int i=0;i<n;i++){
            if(found) break;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid,q);
                    found = true;
                    break;
                }
            }
        }

        int flip = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();

                for(auto d : dir){
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        if(grid[nx][ny] == 1){
                            return flip;
                        }else if(grid[nx][ny] == 0){
                            grid[nx][ny] = 2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            flip++;
        }
        return -1;
    }
};
