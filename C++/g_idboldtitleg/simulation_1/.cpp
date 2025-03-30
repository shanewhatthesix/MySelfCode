#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 用于存储视图信息的结构体
struct View {
    int x, y, width, height;
    string id;
    vector<View> children;

    View() : x(0), y(0), width(0), height(0), id("") {}
};

// 解析输入字符串，创建 View 对象
View parseView(const string& line) {
    int x, y, width, height;
    char idBuffer[100] = ""; // 用于存储 ID 字符串

    // 解析字符串
    sscanf(line.c_str(), "(%d,%d,%d,%d) \"%[^\"]\"", &x, &y, &width, &height, idBuffer);
    string id(idBuffer); // 将字符数组转换为字符串

    View view;
    view.x = x;
    view.y = y;
    view.width = width;
    view.height = height;
    view.id = id;

    // 输出解析的视图信息
    cout << "Parsed View: " << id << " | Position: (" << x << ", " << y << ") | Size: (" << width << ", " << height << ")\n";

    return view;
}

// 递归计算带有 ID 的元素在屏幕上的绝对坐标
void calculateCoordinates(const View& view, int parentX, int parentY) {
    int absoluteX = parentX + view.x;
    int absoluteY = parentY + view.y;

    // 输出带 ID 的元素的坐标
    if (!view.id.empty()) {
        cout << view.id << " | Absolute Position: (" << absoluteX << ", " << absoluteY << ")\n";
    }

    // 递归计算子元素的坐标
    for (size_t i = 0; i < view.children.size(); ++i) {
        calculateCoordinates(view.children[i], absoluteX, absoluteY);
    }
}

int main() {
    int n;
    cin >> n; // 输入最外层的视图有几个
    cin.ignore(); // 忽略换行符

    vector<View> views(n);
    string line;

    // 逐行读取视图数据
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        views[i] = parseView(line);

        // 处理子元素
        while (getline(cin, line) && line != "(0,0,0,0)") {
            // 检测缩进
            int level = 0;
            while (line[level] == ' ') level++; // 计算缩进的空格数

            // 仅当缩进为4时，将子元素解析并加入到当前视图
            if (level == 4) {
                views[i].children.push_back(parseView(line));
            }
        }
    }

    // 处理每个视图并输出带有 ID 的元素的坐标
    for (size_t i = 0; i < views.size(); ++i) {
        calculateCoordinates(views[i], 0, 0);
    }

    return 0;
}

