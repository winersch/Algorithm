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

int ans;
int a, b, c, n;
bool visited[301];

void find(){
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if (curr == 0){
            ans = 1;
            return;
        }
        if (curr < 0){
            continue;
        }
        if (visited[curr]){
            continue;
        }
        visited[curr] = true;
        q.push(curr - a);
        q.push(curr - b);
        q.push(curr - c);
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b >> c >> n;
    find();
    cout << ans;



    return 0;
}

