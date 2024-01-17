#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<long long> input;
vector<long long> ans;
long long tmp = 33333333333;
bool is_find = false;

void find(int a, int b) {
    int high = input.size() - 1;
    int low = b+1;

    while (high >= low) {
        int mid = (high + low) / 2;
        long long n = input[a] + input[b] + input[mid];
        if (n == 0) {
            ans.clear();
            ans.push_back(input[a]);
            ans.push_back(input[b]);
            ans.push_back(input[mid]);
            is_find = true;
            return;
        }

        if (abs(n) < tmp) {
            ans.clear();
            ans.push_back(input[a]);
            ans.push_back(input[b]);
            ans.push_back(input[mid]);
            tmp = abs(n);
        }

        if (n > 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());

    for (int i = 0; i < n - 2; i++) {
        if (is_find) {
            break;
        }
        for (int j = i + 1; j < n - 1; j++) {
            if (is_find) {
                break;
            }
            find(i, j);
        }
    }
    sort(ans.begin(), ans.end());

    for (int a: ans) {
        cout << a << " ";
    }

    return 0;
}