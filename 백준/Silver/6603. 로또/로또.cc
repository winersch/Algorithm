#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

vector<int> v;
int ans[7];

void print(int n,int idx, int depth){
    if (depth == 6){
        for (int i = 0; i < 6; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = idx; i < n; i++) {
            ans[depth] = v[i];
            print(n,i+1,depth+1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true){
        int n;
        cin >> n;
        if (n == 0){
            break;
        }
        v.clear();
        memset(ans, 0, sizeof(ans));

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        print(n,0,0);
        cout << "\n";
    }

    return 0;
}
