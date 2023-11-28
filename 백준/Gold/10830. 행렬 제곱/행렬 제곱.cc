#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

long long int n, b;
long long int matrix[5][5];
long long int tmp[5][5];
long long int ans[5][5];

void mul(long long int x[5][5], long long int y[5][5]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                tmp[i][j] += (x[i][k] * y[k][j]);
            }
            tmp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
        ans[i][i] = 1;
    }
    while(b > 0){
        if(b %2 == 1){
            mul(ans, matrix);
        }
        mul(matrix, matrix);
        b /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}