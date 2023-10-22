#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n, cnt;
int input[1000001];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (m.find(a) == m.end()){
            m.insert({a, 0});
        }
        input[i] = a;
    }

    for(auto a : m){
        m[a.first] = cnt;
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        auto it = m.find(input[i]);
        cout << it->second << " ";

    }
    return 0;
}