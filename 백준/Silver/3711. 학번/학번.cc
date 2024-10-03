#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

bool visited[1000001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i < 1000000; i++) {
            bool check = true;
            memset(visited,false,sizeof(visited));
            for (int j = 0; j < n; j++) {
                if (visited[v[j]%i]){
                    check = false;
                    break;
                }
                visited[v[j]%i] = true;
            }
            if (check){
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}