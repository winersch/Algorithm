#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

int n;
int paper[2500][2500];
int ans[3];

void find(int y, int x, int size){
    int start = paper[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (paper[i][j] != start){
                find(y, x, size / 3);
                find(y+size/3, x, size / 3);
                find(y+size/3+size/3, x, size / 3);
                find(y, x+size/3, size / 3);
                find(y, x+size/3+size/3, size / 3);
                find(y+size/3, x+size/3, size / 3);
                find(y+size/3+size/3, x+size/3+size/3, size / 3);
                find(y+size/3, x+size/3+size/3, size / 3);
                find(y+size/3+size/3, x+size/3, size / 3);
                return;
            }
        }
    }
    ans[start+1]++;
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> paper[i][j];
        }
    }
    find(1,1,n);

    for(int a : ans){
        cout << a << "\n";
    }

    return 0;
}
