#include <iostream>
#include <string>

using namespace std;
int n, m, small = 999999, big = 999999, channel = 100;
char button[10];
bool find_ch = false;
string str, small_str, big_str;

int main() {
    cin >> n >> m;
    str = to_string(n);

    if (m == 10) {
        cout << abs(n - channel);
        return 0;
    } else if (m == 0) {
        cout << min((int)str.length(), abs(n - channel));
        return 0;
    } else if (n == channel) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> button[i];
    }
    for (int i = 0; i < 2; i++) {
        int count = n;
        find_ch = false;
        while (!find_ch) {
            if (i == 0) {
                big_str = to_string(count);

                for (int j = 0; j < m; j++) {
                    if (big_str.find(button[j]) != string::npos) {
                        break;
                    } else if (j == m - 1) {
                        big = stoi(big_str);
                        find_ch = true;
                    }
                }
                if (count >= n * 2 + 100) {
                    break;
                }
                count++;
            } else {
                small_str = to_string(count);

                for (int j = 0; j < m; j++) {
                    if (small_str.find(button[j]) != string::npos) {
                        break;
                    } else if (j == m - 1) {
                        small = stoi(small_str);
                        find_ch = true;
                    }
                }
                if (count == 0) {
                    break;
                }
                count--;
            }
        }
    }
    int r1 = min(abs(n - big) + big_str.length(), abs(n - small) + small_str.length());
    int r2 = abs(n - channel);

    int result = min(r1, r2);
    cout << result;
    return 0;
}
