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

vector<string> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string ans = "";
    int dist = 0;
    for (int i = 0; i < m; i++) {
        int cnt[4] = {};
        for (int j = 0; j < n; j++) {
            switch(v[j][i]){
                case 'A':
                    cnt[0]++;
                    break;
                case 'C':
                    cnt[1]++;
                    break;
                case 'G':
                    cnt[2]++;
                    break;
                case 'T':
                    cnt[3]++;
                    break;
            }
        }
        int idx = 0, maxCnt = 0;
        for (int j = 0; j < 4; j++) {
            if (cnt[j] > maxCnt){
                maxCnt = cnt[j];
                idx = j;
            }
        }
        char c;
        switch(idx){
            case 0:
                c = 'A';
                break;
            case 1:
                c = 'C';
                break;
            case 2:
                c = 'G';
                break;
            case 3:
                c = 'T';
                break;
        }
        ans.push_back(c);
        for (int j = 0; j < 4; j++) {
            if (j == idx){
                continue;
            }
            dist += cnt[j];
        }

    }

    cout << ans << "\n" << dist;

    return 0;
}

