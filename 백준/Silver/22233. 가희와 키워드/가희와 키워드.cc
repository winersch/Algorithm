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

int n, m, cnt;
unordered_set<string> memo;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        memo.insert(s);
        cnt++;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int start = 0, end;

        while((end = s.find(',', start)) != string::npos){
            string sub = s.substr(start, end-start);
            if (memo.erase(sub)){
                cnt--;
            }
            start = end+1;
        }
        string sub = s.substr(start);
        if (memo.erase(sub)){
            cnt--;
        }
        cout << cnt << "\n";
    }


    return 0;
}

