#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;

int n;
vector<int> v;
int m = 2100000000;
pair<int, int> ans;


void find() {
    int right = v.size() - 1;
    int left = 0;

    while (right > left) {
        int a = v[left];
        int b = v[right];
        int tmp = a+b;
        if (tmp == 0) {
            ans = {a, b};
            return;
        }

        if (abs(tmp) < m) {
            m = abs(tmp);
            ans = {a, b};
        }
        if (tmp > 0) {
            right--;
        } else {
            left++;
        }

    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    find();

    cout << ans.first << " " << ans.second;

    return 0;
}