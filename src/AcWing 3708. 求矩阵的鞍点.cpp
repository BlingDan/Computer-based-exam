//
// Created by HUAWEI on 2025/2/18.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    // 输入矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    bool hasSaddlePoint = false;

    // 遍历每一行
    for (int i = 0; i < n; i++) {
        // 找到该行的最大值
        int maxInRow = matrix[i][0];
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
            }
        }

        // 找到所有等于最大值的列索引
        vector<int> maxColIndices;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == maxInRow) {
                maxColIndices.push_back(j);
            }
        }

        // 检查这些最大值是否是其所在列的最小值
        for (int colIndex : maxColIndices) {
            bool isSaddlePoint = true;
            for (int k = 0; k < n; k++) {
                if (matrix[k][colIndex] < maxInRow) {
                    isSaddlePoint = false;
                    break;
                }
            }

            // 如果是鞍点，输出
            if (isSaddlePoint) {
                hasSaddlePoint = true;
                cout << i + 1 << " " << colIndex + 1 << " " << maxInRow << endl;
            }
        }
    }

    // 如果没有鞍点，输出 NO
    if (!hasSaddlePoint) {
        cout << "NO" << endl;
    }

    return 0;
}
