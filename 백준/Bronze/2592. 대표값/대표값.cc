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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int arr[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int sum = 0, a = 0, cnt = 0;
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        arr[n]++;
        if (arr[n] > cnt){
            cnt = arr[n];
            a = n;
        }
        sum += n;
    }
    cout << sum/10 << "\n" << a;
}

