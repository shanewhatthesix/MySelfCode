#include <iostream>
#include <vector>
#include <algorithm>

int minTeleportAbility(int n, const std::vector<int>& stairs) {
    int maxZeros = 0;
    int currentZeros = 0;

    for (int i = 1; i < n; ++i) {
        if (stairs[i] == 0) {
            ++currentZeros;
        } else {
            maxZeros = std::max(maxZeros, currentZeros);
            currentZeros = 0;
        }
    }
    // Check the last sequence of zeros if it ends at the last stair
    maxZeros = std::max(maxZeros, currentZeros);

    return maxZeros + 1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> stairs(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> stairs[i];
    }

    std::cout << minTeleportAbility(n, stairs) << std::endl;
    return 0;
}

