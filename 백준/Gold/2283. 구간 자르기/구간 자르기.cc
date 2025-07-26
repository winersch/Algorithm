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
#include <list>
#include <unordered_set>
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;


int n, k;
int arr[1000001], sum[1000001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a + 1; j <= b; j++) {
            arr[j]++;
        }
    }
    sum[0] = 0;
    for (int i = 1; i < 1000001; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    int start = 0, end = 0;
    int a = 0, b = 0;

    while (end < 1000001) {
        int t = 0;
        if (start == 0) {
            t = sum[end];
        } else {
            t = sum[end] - sum[start];
        }
        if (t == k) {
            a = start;
            b = end;
            break;
        }
        if (t < k) {
            end++;
        } else {
            start++;
        }

    }

    cout << a << " " << b;


    return 0;
}