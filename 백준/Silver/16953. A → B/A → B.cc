#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;


long long int a, b;
queue<pair<long long int,int>> q;

void bfs(){

    while (!q.empty()){
        long long int tmp = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (tmp == b){
            cout << cnt;
            return;
        }else if (tmp > b){
            continue;
        }
        long long int mul = tmp*2;
        if (mul == b){
            cout << cnt+1;
            return;
        }else{
            q.push({mul, cnt+1});
        }

        long long int plus = tmp*10+1;
        if (plus == b){
            cout << cnt+1;
            return;
        } else{
            q.push({plus, cnt+1});
        }
    }

    cout << -1;
    return;

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b;
    q.push({a,1});

    bfs();

    return 0;
}