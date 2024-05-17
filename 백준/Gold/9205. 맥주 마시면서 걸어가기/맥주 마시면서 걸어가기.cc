#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

vector<pii> v;
pii festival;
pii home;
bool is_sad;
int n;
bool visited[101];

bool check(pii a){
    if (abs(a.first - festival.first) + abs(a.second - festival.second) <= 1000){
        return true;
    }else{
        return false;
    }
}

void bfs(){
    queue<pii> q;
    q.push(home);

    if (check(home)){
        is_sad = false;
        return;
    }

    while (!q.empty()){
        pii coor = q.front();
        q.pop();
        if (check(coor)){
            is_sad = false;
            return;
        }
        for(int i = 0; i < n; i++){
            if (visited[i]){
                continue;
            }
            int x = abs(coor.first - v[i].first);
            int y = abs(coor.second - v[i].second);
            if (x + y <= 1000){
                visited[i] = true;
                q.push(v[i]);
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        v.clear();
        is_sad = true;
        memset(visited, false, sizeof(visited));
        cin >> home.first >> home.second;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >>a >> b;
            v.push_back({a,b});
        }
        cin >> festival.first >> festival.second;

        bfs();
        if (is_sad){
            cout << "sad" << "\n";
        }else{
            cout << "happy" << "\n";
        }


    }


    return 0;
}