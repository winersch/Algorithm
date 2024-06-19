#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (maxHeap.empty()) {
            maxHeap.push(a);
        } else if (a > maxHeap.top()) {
            minHeap.push(a);
        } else {
            maxHeap.push(a);
        }

        while (true) {
            if (minHeap.size() == maxHeap.size() || minHeap.size() + 1 == maxHeap.size()) {
                break;
            }
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        cout << maxHeap.top() << "\n";
    }


    return 0;
}