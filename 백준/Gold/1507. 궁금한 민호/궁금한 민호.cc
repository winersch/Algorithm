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

int n, ans;
int dist[21][21];
bool disconnect[21][21];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    cout << -1;
                    return 0;
                }
                if (i != k && j != k && dist[i][j] == dist[i][k] + dist[k][j]){
                    disconnect[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!disconnect[i][j]){
                ans += dist[i][j];
            }
        }
    }
    cout << ans/2;
    return 0;
}