#include <iostream>
#include <algorithm>

using namespace std;

int own[20000001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        own[a+10000000]++;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << own[a+10000000] << " ";
    }

    return 0;
}