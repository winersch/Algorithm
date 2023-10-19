#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> pq;
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