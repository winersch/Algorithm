#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n,m;
vector<int> arr;
int out[7];

void print(int depth){
    if (depth == m){
        for (int i = 0; i < m; i++) {
            cout << out[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        out[depth] = arr[i];
        print(depth+1);
        out[depth] = 0;
    }

}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    print(0);


    return 0;
}