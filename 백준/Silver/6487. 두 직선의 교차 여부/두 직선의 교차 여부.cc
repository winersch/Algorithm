#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 1234567
#define ll long long
#define pii pair<int,int>

using namespace std;

int t;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;

    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        bool slope1, slope2, eqslope;
        float slope1val, slope2val, x, y, b1, b2;

        if (x1 == x2) {
            slope1 = false;
        } else {
            slope1 = true;
            slope1val = ((float) (y2 - y1)) / ((float) (x2 - x1));
        }

        if (x3 == x4) {
            slope2 = false;
        } else {
            slope2 = true;
            slope2val = ((float) (y4 - y3)) / ((float) (x4 - x3));
        }

        if ((!slope1) && (!slope2)) {
            eqslope = true;
        } else if ((!slope1) || (!slope2)) {
            eqslope = false;
        } else if (slope1val == slope2val) {
            eqslope = true;
        } else {
            eqslope = false;
        }

        if (eqslope) {
            if ((!slope1) && (x1 == x3)) {
                cout << "LINE\n";
            }
            if ((!slope1) && (x1 != x3)) {
                cout << "NONE\n";
            }
            if (slope1) {
                b1 = (float) (y1) - (slope1val) * (float) (x1);
                b2 = (float) (y3) - (slope2val) * (float) (x3);
                if (b1 == b2) {
                    cout << "LINE\n";
                } else {
                    cout << "NONE\n";
                }
            }
        } else {
            if (!slope1) {
                x = x1;
                b2 = (float) (y4) - (slope2val) * (float) (x4);
                y = (slope2val * x) + b2;
            } else {
                if (!slope2) {
                    x = x3;
                    b1 = (float) (y1) - (slope1val) * (float) (x1);
                    y = (slope1val * x) + b1;
                } else {
                    b1 = (float) (y1) - (slope1val) * (float) (x1);
                    b2 = (float) (y3) - (slope2val) * (float) (x3);
                    x = (b2 - b1) / (slope1val - slope2val);
                    y = (slope1val * x) + b1;
                }
            }
            cout.precision(2);
            cout << fixed << "POINT " << x << " " << y << "\n";
        }
    }

    return 0;
}