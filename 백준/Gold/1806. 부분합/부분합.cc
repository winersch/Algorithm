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

int n, s;
int ans = 100001;
int input[100001];
int tmp, cnt;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        if (input[i] >= s){
            cout << 1;
            return 0;
        }
        tmp += input[i];
        cnt++;
        while (tmp >= s){
            if (i+1-cnt < 0){
                break;
            }
            ans = min(ans, cnt);
            tmp -= input[i+1-cnt];
            cnt--;
        }
    }
    if (ans > 100000){
        ans = 0;
    }
    cout << ans;
    return 0;
}