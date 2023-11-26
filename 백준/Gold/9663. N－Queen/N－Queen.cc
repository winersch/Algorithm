#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int n, ans;
int chess[16];

bool check(int a) {
    for (int i = 0; i < a; i++) {
        if (chess[i] == chess[a] || abs(chess[a] - chess[i]) == a - i){
            return false;
        }
    }
    return true;
}

void find(int num) {
    if (num == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        chess[num] = i;
        if (check(num)){
            find(num+1);
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    find(0);

    cout << ans;


    return 0;
}