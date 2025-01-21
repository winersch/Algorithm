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

int n, ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >>n;
    priority_queue<pii, vector<pii>, greater<>> lecture;
    priority_queue<int, vi, greater<>> room;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lecture.push({b, c});
    }

    while(!lecture.empty()){
        int start = lecture.top().first;
        int end = lecture.top().second;
        lecture.pop();
        if (room.empty()){
            ans++;
            room.push(end);
            continue;
        }

        if (room.top() <= start){
            room.pop();
        }else{
            ans++;
        }
        room.push(end);
    }
    cout << ans;

    return 0;
}