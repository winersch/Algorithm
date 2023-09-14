#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v1, v2;

int find(int input) {
    int high = v1.size()-1;
    int low = 0;

    while (high >= low) {
        int mid = (high + low) / 2;
        if (v1[mid] == input) {
            return 1;
        }
        if (v1[mid] < input) {
            low = mid + 1;
        } else if (v1[mid] > input) {
            high = mid - 1;
        }

    }
    return 0;

}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }

    sort(v1.begin(), v1.end());

    for (int i = 0; i < m; i++) {
        cout << find(v2[i]) << "\n";
    }


    return 0;
}
