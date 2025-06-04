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


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    map<string,int> m;
    queue<string> q;
    int k, l;
    cin >> k >> l;
    for (int i = 1; i <= l; i++) {
        string a;
        cin >> a;
        q.push(a);
        m[a] = i;
    }
    int idx = 1, cnt = 0;
    while(!q.empty() && cnt < k){
        string curr = q.front();
        q.pop();
        if (m[curr] == idx){
            cnt++;
            cout << curr << "\n";
        }
        idx++;
    }


    return 0;
}
