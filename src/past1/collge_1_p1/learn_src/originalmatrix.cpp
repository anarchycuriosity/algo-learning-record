#include <iostream>
using namespace std;

// 比较两个二维块是否 a < b（字典序）
bool lex_compare(int** a, int** b, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] < b[i][j]) return true;
            if (a[i][j] > b[i][j]) return false;
        }
    return false;
}

// 交换两个二维块
void swap_block(int** a, int** b, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            swap(a[i][j], b[i][j]);
}

int main() {
    int depth, rows, cols;
    cout << "请输入三维矩阵的维度（depth rows cols）：";
    cin >> depth >> rows >> cols;

    // 分配三维数组：cube[depth][rows][cols]
    int*** cube = new int**[depth];
    for (int d = 0; d < depth; ++d) {
        cube[d] = new int*[rows];
        for (int i = 0; i < rows; ++i)
            cube[d][i] = new int[cols];
    }

    // 输入数据
    cout << "请输入每个块的内容（共 " << depth << " 个块，每块 " << rows << "×" << cols << "）：\n";
    for (int d = 0; d < depth; ++d)
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> cube[d][i][j];

    // 字典序排序
    for (int i = 0; i < depth - 1; ++i)
        for (int j = i + 1; j < depth; ++j)
            if (lex_compare(cube[j], cube[i], rows, cols))
                swap_block(cube[i], cube[j], rows, cols);

    // 输出排序后的 cube
    cout << "\n排序后的 cube：\n";
    for (int d = 0; d < depth; ++d) {
        cout << "Block " << d << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << cube[d][i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    // 释放内存
    for (int d = 0; d < depth; ++d) {
        for (int i = 0; i < rows; ++i)
            delete[] cube[d][i];
        delete[] cube[d];
    }
    delete[] cube;

    return 0;
}
