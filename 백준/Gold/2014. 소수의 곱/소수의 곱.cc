#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>
#define ll long long

int k, n;
int arr[101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<ll, vector<ll>, greater<>> pq;

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    int cnt = 0;
    ll head = 0;
    ll res;

    while (cnt != n){
        for (int i = 0; i < k; i++) {
            head = pq.top();
            res = arr[i] * head;
            if(res >= INT32_MAX){
                break;
            }
            pq.push(res);

            if (head % arr[i] == 0){
                break;
            }

        }
        pq.pop();
        cnt++;
    }

    cout << head;

    return 0;

}