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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    deque<int> dq;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        int idx = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == a){
                idx = j;
                break;
            }
        }

        if (idx <= dq.size()/2){
            while(true){
                if (dq.front() == a){
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            while(true){
                if (dq.front() == a){
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << cnt;

    return 0;
}