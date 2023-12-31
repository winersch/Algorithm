#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int input[2001];
bool palin[2001][2001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }

    for (int i = 1; i <= n; i++) {
        palin[i][i] = true;
        if (i < n && input[i] == input[i + 1]) {
            palin[i][i + 1] = true;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 2; j <= n; j++) {
            if (input[i] == input[j] && palin[i+1][j-1] == true){
                palin[i][j] = true;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << palin[a][b] << "\n";
    }

    return 0;
}