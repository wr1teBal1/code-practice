// 题目描述
// 在一个城市区域内，被划分成了n * m个连续的区块，
// 每个区块都拥有不同的权值，
// 代表着其土地价值。
// 目前，有两家开发公司，
// A 公司和 B 公司，希望购买这个城市区域的土地。 

// 现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。

// 然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，
// 而且每个子区域都必须包含一个或多个区块。 
// 为了确保公平竞争，你需要找到一种分配方式，
// 使得 A 公司和 B 公司各自的子区域内的土地总价值之差最小。 

// 注意：区块不可再分。

// 输入描述
// 第一行输入两个正整数，代表 n 和 m。 

// 接下来的 n 行，每行输出 m 个正整数。

// 输出描述
// 请输出一个整数，代表两个子区域内土地总价值之间的最小差距。
// 输入示例
// 3 3
// 1 2 3
// 2 1 3
// 1 2 3
// 输出示例
// 0
// 提示信息
// 如果将区域按照如下方式划分：

// 1 2 | 3
// 2 1 | 3
// 1 2 | 3 

// 两个子区域内土地总价值之间的最小差距可以达到 0。

// 数据范围：

// 1 <= n, m <= 100；
// n 和 m 不同时为 1。

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            totalSum += grid[i][j];
        }
    }
    int minDiff = INT_MAX;
    // 横向划分
    for (float a = 0.5; a < n ; ++a){
        int sum = 0;
        for(int j = 0; j <= a; ++j){
            for(int k = 0; k < m; ++k){
                sum += grid[j][k];
            }
        }
        int diff = abs(totalSum - 2 * sum);
        if(diff < minDiff) minDiff = diff;
    }
    // 纵向划分
    for (float a = 0.5; a < m ; ++a){
        int sum = 0;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k <= a; ++k){
                sum += grid[j][k];
            }
        }
        int diff = abs(totalSum - 2 * sum);
        if(diff < minDiff) minDiff = diff;
    }
    cout << minDiff << endl;
    return 0;
}