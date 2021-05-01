#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using TLl = long long;

double calcArea(int a, int b, int c) {
    double p = (a + b + c) / 2.0;
    if ((p - a) <= 0 || (p - b ) <= 0 || (p - c) <= 0) {
        return 0.0;
    }
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

void solve(std::vector<int>& lengths) {
    std::sort(lengths.begin(), lengths.end());

    double maxArea = 0.0;
    int first = -1;
    int second = -1;
    int third = -1;
    for (int i = 0; i < lengths.size() - 2; ++i) {
        for (int j = i + 1; j < lengths.size() - 1; ++j) {
            int l = j + 1;
            int r = lengths.size() - 1;
            while (r - l >= 3) {
                int m1 = l + (r - l) / 3;
                int m2 = r - (r - l) / 3;
                if (calcArea(lengths[i], lengths[j], lengths[m1]) < calcArea(lengths[i], lengths[j], lengths[m2])) {
                    l = m1;
                } else {
                    r = m2;
                }
            }
            for (int k = l; k <= r; ++k) {
                if (calcArea(lengths[i], lengths[j], lengths[k]) > maxArea) {
                    maxArea = calcArea(lengths[i], lengths[j], lengths[k]);
                    first = i;
                    second = j;
                    third = k;
                }
            }
        }
    }
    if (maxArea == 0.0) {
        std::cout << "0\n";
    } else {
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout.precision(3);
        std::cout << maxArea << "\n";
        std::cout << lengths[first] << " " << lengths[second] << " " << lengths[third] << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); 
    int n;
    std::cin >> n;
    std::vector<int> lengths(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> lengths[i];
    }
    solve(lengths);
    return 0;
}