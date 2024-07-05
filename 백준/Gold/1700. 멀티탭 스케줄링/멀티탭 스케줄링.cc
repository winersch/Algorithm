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

using namespace std;

int n, k, ans;
int plug[101];
vector<int> v;
vector<int> sequence[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        sequence[a].push_back(i);
    }

    for (int i = 0; i < k; i++) {
        int maxSequence = 0;
        int plugIdx;
        bool isPop = true;
        for (int j = 0; j < n; j++) {
            if (v[i] == plug[j]){
                isPop = false;
                sequence[v[i]].erase(sequence[v[i]].begin());
                break;
            }
            if (plug[j] == 0){
                plug[j] = v[i];
                sequence[v[i]].erase(sequence[v[i]].begin());
                isPop = false;
                break;
            }
        }
        if (!isPop){
            continue;
        }
        for (int j = 0; j < n; j++) {

            if (sequence[plug[j]].empty()){
                plugIdx = j;
                break;
            }
            if (sequence[plug[j]][0] > maxSequence){
                maxSequence = sequence[plug[j]][0];
                plugIdx = j;
            }
        }
        if (isPop){
            plug[plugIdx] = v[i];
            sequence[v[i]].erase(sequence[v[i]].begin());
            ans++;
        }
    }

    cout << ans;

    return 0;
}