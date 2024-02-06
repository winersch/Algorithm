#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int n, ans;
int board[21][21];

void move(int arr[][21]){
    for (int i = 0; i < n; i++) {
        deque<int> dq;
        bool isMerged = false;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0){
                if (!dq.empty() && dq.back() == arr[i][j] && !isMerged){
                    dq.pop_back();
                    dq.push_back(arr[i][j] *2);
                    isMerged = true;
                }else{
                    dq.push_back(arr[i][j]);
                    isMerged = false;
                }
                arr[i][j] = 0;
            }
        }
        int idx = 0;
        while (!dq.empty()){
            arr[i][idx++] = dq.front();
            dq.pop_front();
        }

    }
}

void rotation(int arr[][21]){
    int tmp[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j][n-1-i] = arr[i][j];
        }
    }
    memcpy(arr, tmp, sizeof(tmp));
}

void dfs(int depth){
    if (depth == 5){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }

    int tmp[21][21];
    for (int i = 0; i < 4; i++) {
        memcpy(tmp, board, sizeof(board));
        move(board);
        dfs(depth+1);
        memcpy(board,tmp, sizeof(board));
        rotation(board);
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}
