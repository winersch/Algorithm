#include <iostream>
#include <queue>

using namespace std;


int main() {
    int n, a;
    cin >> n;
    queue<int> q;
    if (n == 1){
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        q.push(i+1);
    }
    while(!q.empty()){
        q.pop();
        if (q.empty()){
            break;
        }
        a = q.front();
        q.pop();
        q.push(a);
    }
    cout << a;
    return 0;
}
