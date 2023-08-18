#include <iostream>
#include <algorithm>

using namespace std;


string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string chess[50];

int check_WB(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[x + i][y + j] != WB[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int check_BW(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[x + i][y + j] != BW[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {

    int n, m, result = 9999;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> chess[i];
    }
    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            int temp;
            temp = min(check_BW(i, j), check_WB(i, j));
            if (result > temp){
                result = temp;
            }
        }
    }
    cout << result;
    return 0;
}
