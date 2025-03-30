#include <iostream>
#include <iomanip> // 用于iomanip进行输出格式设置
using namespace std;

char board[20][20] = {0}; // 初始化棋盘
int boardSize = 15; // 棋盘大小设置为15x15

void showboard() {
    cout << "   ";
    for (int i = 1; i <= boardSize; ++i) {
        cout << setw(3) << i; // 使用setw设置每个列宽为3
    }
    cout << endl;

    for (int i = 1; i <= boardSize; ++i) {
        cout << setw(3) << i; // 行号，每个列宽为3

        for (int j = 1; j <= boardSize; ++j) {
            if (board[i][j] == 0) cout << "   "; // 空白位置显示空
            else cout << " " << board[i][j] << " "; // 棋子显示
        }
        cout << endl;
    }
}

bool checkWin(int x, int y) {
    char player = board[x][y];
    if (player == 0) return false;

    // 四个方向的增量
    int dx[4] = {1, 0, 1, 1}; // 水平方向、垂直方向、\方向、/方向
    int dy[4] = {0, 1, -1, 1};

    for (int d = 0; d < 4; ++d) {
        int count = 1; // 当前棋子的计数

        // 向一个方向检查
        for (int step = 1; step < 5; ++step) {
            int nx = x + dx[d] * step;
            int ny = y + dy[d] * step;
            if (nx >= 1 && nx <= boardSize && ny >= 1 && ny <= boardSize && board[nx][ny] == player) {
                count++;
            } else {
                break;
            }
        }

        // 向另一个方向检查
        for (int step = 1; step < 5; ++step) {
            int nx = x - dx[d] * step;
            int ny = y - dy[d] * step;
            if (nx >= 1 && nx <= boardSize && ny >= 1 && ny <= boardSize && board[nx][ny] == player) {
                count++;
            } else {
                break;
            }
        }

        // 检查是否达成五子连线
        if (count >= 5) {
            cout << (player == '☆' ? "黑方" : "白方") << " 获胜！" << endl;
            return true; // 有人胜利了
        }
    }

    return false; // 没有胜利
}

int main() {
    showboard();

    while (true) {
        // 黑方下棋
        while (true) {
            cout << "黑方，请输入落子位置（行 列）：";
            int i, j;
            cin >> i >> j;
            if (board[i][j] == 0) {
                board[i][j] = '☆'; // 黑子
                showboard();
                if (checkWin(i, j)) return 0; // 判断胜利
                break;
            } else {
                cout << "对不起，该位置已经有棋子了。\n";
            }
        }

        // 白方下棋
        while (true) {
            cout << "白方，请输入落子位置（行 列）：";
            int i, j;
            cin >> i >> j;
            if (board[i][j] == 0) {
                board[i][j] = '○'; // 白子
                showboard();
                if (checkWin(i, j)) return 0; // 判断胜利
                break;
            } else {
                cout << "对不起，该位置已经有棋子了。\n";
            }
        }
    }

    return 0;
}