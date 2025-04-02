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

int n, ans = inf;
int pop[11];
bool sel[11];
vi node[11];

void check(){
    bool blue = false, red = false;
    bool visited[11] = {false};
    for (int i = 0; i < n; i++) {
        if (sel[i] && !blue){
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for (int a : node[curr]) {
                    if (!visited[a] && sel[a]){
                        visited[a] = true;
                        q.push(a);
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if (sel[j] && !visited[j]){
                    return;
                }
            }
            blue = true;
        }
        if (!sel[i] && !red){
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for (int a : node[curr]) {
                    if (!visited[a] && !sel[a]){
                        visited[a] = true;
                        q.push(a);
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if (!sel[j] && !visited[j]){
                    return;
                }
            }
            red = true;
        }
    }
    if (red && blue){
        int b = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (sel[i]){
                b+=pop[i];
            }else{
                r+=pop[i];
            }
        }
        ans = min(ans, abs(b - r));
    }

}

void sol(int idx){
    if (idx == n){
        return;
    }
    for (int i = idx+1; i < n; i++) {
        sel[i] = true;
        check();
        sol(i);
        sel[i] = false;
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pop[i];
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            node[i].push_back(b-1);
        }
    }

    sol(-1);

    cout << ((ans == inf) ? -1 : ans);



}

