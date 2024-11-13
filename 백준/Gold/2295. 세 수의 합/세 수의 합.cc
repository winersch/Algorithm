#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;
vi v, two;

int binarySearch(int idx) {
    int mid;
    int left = 0, right = two.size() - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (two[mid] < idx) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            two.push_back(v[i] + v[j]);
        }
    }
    sort(two.begin(), two.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = v[i] - v[j];
            int pos = binarySearch(tmp);
            if (pos < two.size() && two[pos] == tmp){
                cout << v[i];
                return 0;
            }
        }
    }


    return 0;
}