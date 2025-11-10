#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& profit, vector<int>& weight, int maxCap, int idx, int n, vector<vector<int>>& dp){
    if(idx >= n || maxCap <= 0){
        return 0;
    }

    if(dp[idx][maxCap] != -1){
        return dp[idx][maxCap];
    }

    int pick = 0;
    if(maxCap >= weight[idx]){
        pick = profit[idx] + solve(profit, weight, maxCap - weight[idx], idx + 1, n, dp);
    }
    int noPick = solve(profit, weight, maxCap, idx + 1, n, dp);

    return dp[idx][maxCap] = max(pick, noPick);
}

int solveTab(vector<int>& profit, vector<int>& weight, int n, int& maxCap){
    vector<vector<int>> dp(n+1, vector<int>(maxCap + 1, 0));
    for(int i = n-1; i >= 0; i--){
        for(int w = 0; w <= maxCap; w++){
            int pick = 0;
            if(w - weight[i] >= 0){
                pick = profit[i] + dp[i+1][w - weight[i]];
            }
            int noPick = dp[i+1][w];
            dp[i][w] = max(pick, noPick);
        }
    }
    return dp[0][maxCap];
}

int knapsack(vector<int>& profit, vector<int>& weight, int& maxCap, int n){
    vector<vector<int>> dp(n+1, vector<int>(maxCap+1, -1));
    return solve(profit, weight, maxCap, 0, n, dp);
}

int main(){
    int maxCap = 8;
    vector<int> profit = {1, 2, 5, 6};
    vector<int> weight = {2, 3, 4, 5};

    cout << "Maximum value: " << knapsack(profit, weight, maxCap, profit.size()) << endl;
    cout << "Maximum value: " << solveTab(profit, weight, profit.size(), maxCap) << endl;
}