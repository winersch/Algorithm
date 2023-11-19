#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;


int tree[10001];

void visit(int a) {
    cout << tree[a] << "\n";
}

void postorder(int start, int end) {
    if (start >= end) {
        return;
    }

    if (start == end - 1) {
        visit(start);
        return;
    }
    int idx = start + 1;
    while (idx < end){
        if (tree[start] < tree[idx]){
            break;
        }
        idx++;
    }

    postorder(start+1, idx);
    postorder(idx, end);
    cout << tree[start] << "\n";
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    int cnt = 0;
    while (cin >> num) {
        tree[cnt] = num;
        cnt++;
    }

    postorder(0, cnt);

    return 0;
}