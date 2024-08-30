class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);  
        }
        return parent[x];
    }
    
    void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (auto& connection : connections) {
            unionSets(connection[0], connection[1], parent, rank);
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i, parent) == i) {
                components++;
            }
        }

        return components - 1;
    }
};

