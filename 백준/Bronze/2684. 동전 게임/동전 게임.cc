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
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

string check[8] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
int ans[8];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            string tmp = s.substr(i,3);
            for (int j = 0; j < 8; j++) {
                if (tmp == check[j]){
                    ans[j]++;
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        memset(ans, 0, sizeof(ans));
    }


    return 0;
}