#include <bits/stdc++.h>
using namespace std;

int main() {
    double s[3][3];
    cin >> s[0][0] >> s[0][1] >> s[0][2];
    cin >> s[1][0] >> s[1][1] >> s[1][2];
    cin >> s[2][0] >> s[2][1] >> s[2][2];

    cout << 4 		<< " " << s[0][1] << " " <<s[0][2]  << endl;
    cout << 5		<< " " << s[1][1] << " " << s[1][2] << endl;
    cout << 6<< " " << s[2][1] << " " << s[2][2] << endl;

    return 0;
}
