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

struct team{
    int num, mem, score, five;
};

bool comp(team& t1, team& t2){
    if (t1.score == t2.score){
        return t1.five < t2.five;
    }
    return t1.score < t2.score;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<team> v(n+1);
        vi input(n+1);
        vi teamCnt(n+1);
        for (int i = 1; i <= n; i++) {
            v[i].num = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> input[i];
            teamCnt[input[i]]++;
        }
        int score = 1;
        for (int i = 1; i <= n; i++) {
            int a = input[i];
            if (teamCnt[a] < 6){
                continue;
            }
            if (v[a].mem == 4){
                v[a].five = i;
            }
            v[a].mem++;
            if (v[a].mem < 5){
                v[a].score += score;
            }
            score++;
        }
        std::sort(v.begin(), v.end(), comp);

        for(auto a : v){
            if (a.mem == 6){
                cout << a.num << "\n";
                break;
            }
        }

    }

    return 0;
}

