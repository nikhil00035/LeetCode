class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sumUp=0;
        long long ans = LLONG_MAX;
        long long sumDown = 0;
        int n=grid[0].size();
        for(int i = 0; i < n; i++){
            sumUp += grid[0][i];
        }
        for(int i = 0; i < n; i++){
            sumUp-=grid[0][i];
            long long val = max(sumDown,sumUp);
            sumDown += grid[1][i];
            ans = min(ans,val);
        }
        return ans;
    }
};