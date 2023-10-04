#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0){
            if (pq.empty()){
                cout << 0 << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else{
            pq.push(a);
        }
    }


    return 0;

}