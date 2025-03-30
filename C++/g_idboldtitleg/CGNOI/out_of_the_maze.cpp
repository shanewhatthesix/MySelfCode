#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 105;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m;

// 四个方向的移动：上、右、下、左
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Point {
    int x, y, steps;
    Point(int _x, int _y, int _s) : x(_x), y(_y), steps(_s) {}
};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#' && !visited[x][y];
}

int bfs(int startX, int startY) {
    queue<Point> q;
    q.push(Point(startX, startY, 0));
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        // 如果找到终点
        if (maze[current.x][current.y] == 'T') {
            return current.steps;
        }
        
        // 尝试四个方向
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                q.push(Point(newX, newY, current.steps + 1));
            }
        }
    }
    return -1; // 如果没有找到路径
}

int main() {
    cin >> n >> m;
    
    int startX, startY;
    // 读入迷宫并找到起点
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            visited[i][j] = false;
        }
    }
    
    cout << bfs(startX, startY) << endl;
    
    return 0;
}

/*
描述
当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。假设你已经得到了一个n×m的迷宫的图纸，请你找出从起点到出口的最短路

输入
第一行是两个整数n和m(1≤n,m≤100)，表示迷宫的行数和列数。
接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点'T'表示出口。数据保证从入口能走到出口。

输出
输出从起点到出口最少需要走的步数。

输入样例 1 

3 3
S#T
.#.
...
输出样例 1

6

本题使用算法：广度优先搜索



*/