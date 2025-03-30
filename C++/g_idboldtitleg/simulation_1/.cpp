#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// ���ڴ洢��ͼ��Ϣ�Ľṹ��
struct View {
    int x, y, width, height;
    string id;
    vector<View> children;

    View() : x(0), y(0), width(0), height(0), id("") {}
};

// ���������ַ��������� View ����
View parseView(const string& line) {
    int x, y, width, height;
    char idBuffer[100] = ""; // ���ڴ洢 ID �ַ���

    // �����ַ���
    sscanf(line.c_str(), "(%d,%d,%d,%d) \"%[^\"]\"", &x, &y, &width, &height, idBuffer);
    string id(idBuffer); // ���ַ�����ת��Ϊ�ַ���

    View view;
    view.x = x;
    view.y = y;
    view.width = width;
    view.height = height;
    view.id = id;

    // �����������ͼ��Ϣ
    cout << "Parsed View: " << id << " | Position: (" << x << ", " << y << ") | Size: (" << width << ", " << height << ")\n";

    return view;
}

// �ݹ������� ID ��Ԫ������Ļ�ϵľ�������
void calculateCoordinates(const View& view, int parentX, int parentY) {
    int absoluteX = parentX + view.x;
    int absoluteY = parentY + view.y;

    // ����� ID ��Ԫ�ص�����
    if (!view.id.empty()) {
        cout << view.id << " | Absolute Position: (" << absoluteX << ", " << absoluteY << ")\n";
    }

    // �ݹ������Ԫ�ص�����
    for (size_t i = 0; i < view.children.size(); ++i) {
        calculateCoordinates(view.children[i], absoluteX, absoluteY);
    }
}

int main() {
    int n;
    cin >> n; // ������������ͼ�м���
    cin.ignore(); // ���Ի��з�

    vector<View> views(n);
    string line;

    // ���ж�ȡ��ͼ����
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        views[i] = parseView(line);

        // ������Ԫ��
        while (getline(cin, line) && line != "(0,0,0,0)") {
            // �������
            int level = 0;
            while (line[level] == ' ') level++; // ���������Ŀո���

            // ��������Ϊ4ʱ������Ԫ�ؽ��������뵽��ǰ��ͼ
            if (level == 4) {
                views[i].children.push_back(parseView(line));
            }
        }
    }

    // ����ÿ����ͼ��������� ID ��Ԫ�ص�����
    for (size_t i = 0; i < views.size(); ++i) {
        calculateCoordinates(views[i], 0, 0);
    }

    return 0;
}

