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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;
vector<int> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i == j){
                continue;
            }
            for (int k = 1; k <= 9; k++) {
                if (j == k || i == k){
                    continue;
                }
                v.push_back(i*100+j*10+k);
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, s, b;
        cin >> a >> s >> b;
        int num[3] = {};
        num[0] = a / 100;
        num[1] = a % 100 / 10;
        num[2] = a % 10;

        for (int j = 0; j < v.size(); j++) {
            int scnt = 0, bcnt = 0;
            int tnum[3] = {};
            tnum[0] = v[j] / 100;
            tnum[1] = v[j] % 100 / 10;
            tnum[2] = v[j] % 10;

            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (num[k] == tnum[l]){
                        if (k == l){
                            scnt++;
                        }else{
                            bcnt++;
                        }
                    }
                }
            }
            if (scnt != s || bcnt != b){
                v.erase(v.begin() + j);
                j--;
            }
        }
    }

    cout << v.size();

    return 0;
}

