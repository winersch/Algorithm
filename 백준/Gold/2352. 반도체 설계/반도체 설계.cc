#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

int n;
int port[40001];
int lis[40001];

int binary_search(int left, int right, int target) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> port[i];
    }

    int j = 0, i = 1;
    lis[0] = port[0];

    while(i < n){
        if (lis[j] < port[i]){
            lis[j+1] = port[i];
            j++;
        }else{
            int idx = binary_search(0,j,port[i]);
            lis[idx] = port[i];
        }
        i++;
    }

    cout << j+1;
    return 0;
}