// 题目描述
// 给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
// 输入描述
// 第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束。
// 输出描述
// 输出每个指定区间内元素的总和。

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 构建前缀和数组
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int a, b;
    while (cin >> a >> b) {
        // 区间和 = 前缀和[b+1] - 前缀和[a]
        int sum = prefix[b + 1] - prefix[a];
        cout << sum << endl;
    }

    return 0;
}
    