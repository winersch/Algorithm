#include <iostream>
#include <cmath>

using namespace std;

// x1^2 + y1^2 = r1^2



int main() {
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double center_distance;
        center_distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        if ((x1 == x2) && (y1 == y2)) {
            if (r1 == r2){// 원이 겹칠 때
                cout << -1 << "\n";
            }else{  // 한 원이 다른 원을 포함
                cout << 0 << "\n";
            }
        } else {
            if ((center_distance == r1 + r2) || (center_distance + min(r1, r2) == max(r1, r2))) {       // 외접, 내접
                cout << 1 << "\n";
            } else if ((center_distance < r1 + r2) && (abs(r1 - r2) < center_distance)) { // 두점에서 만남
                cout << 2 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
