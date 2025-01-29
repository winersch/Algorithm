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

int n, m;
bool arr[101];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            for (int j = b; j <= n; j+=b) {
                arr[j] = !arr[j];
            }
        }else{
            int left = b-1;
            int right = b+1;
            while(left > 0 && right <= n && arr[left] == arr[right]){
                left--;
                right++;
            }
            left++;
            right--;
            for (int j = left; j <= right; j++) {
                arr[j] = !arr[j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
        if (i%20 == 0){
            cout << "\n";
        }
    }
    return 0;
}