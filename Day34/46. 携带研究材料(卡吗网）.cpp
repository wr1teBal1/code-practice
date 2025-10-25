#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    private:
    static bool cmp(const vector<float>& a, const vector<float>& b){
        return a[1] > b[1];
    }
public:
    int knapsack01(int kind, int volume, vector<vector<int>>& matrix){
        vector<int> dp(volume + 1, 0);
        vector<vector<float>> pre(kind, vector<float>(2,0));

        for(int i = 0; i < kind; i++){
            pre[i][1] = matrix[i][1] / (float)matrix[i][0];
            pre[i][0] = i;
        }
        sort(pre.begin(), pre.end(), cmp);
        for(int i = 0; i < kind; i++){
            int idx = (int)pre[i][0];
            int w = matrix[idx][0];
            int v = matrix[idx][1];
            for(int j = volume; j >= w; j--){
                dp[j] = max(dp[j], dp[j - w] + v);
            }

        }
        return dp[volume];
    }
};



int main(){
    int kind, volume;
    cin >> kind >> volume;
    vector<vector<int>> matrix(kind, vector<int>(2,0));
    for(int i = 0; i < kind; i++){
        cin >> matrix[i][0];
    }
    for(int i = 0; i < kind; i++){
        cin >> matrix[i][1];
    }
    Solution sol;
    cout << sol.knapsack01(kind, volume, matrix) << endl;

    return 0;
}