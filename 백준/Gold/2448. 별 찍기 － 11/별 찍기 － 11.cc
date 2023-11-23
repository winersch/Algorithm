#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int n;
int grid[3072][6243];

void print(int x, int y, int size){
    if (size == 3){
        grid[y][x] = 1;
        grid[y + 1][x - 1] = 1;
        grid[y + 1][x + 1] = 1;

        grid[y + 2][x - 2] = 1;
        grid[y + 2][x - 1] = 1;
        grid[y + 2][x] = 1;
        grid[y + 2][x + 1] = 1;
        grid[y + 2][x + 2] = 1;
    } else{
        print(x,y,size/2);
        print(x - size/2, y + size/2, size/2);
        print(x + size/2 , y + size/2, size/2);
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    print(n-1, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2-1; j++) {
            if (grid[i][j] == 1){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}