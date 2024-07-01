#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> middle;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<>> min_heap;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (min_heap.empty()) {
                if (max_heap.empty()) {
                    max_heap.push(a);
                } else if (a < max_heap.top()){
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(a);
                }else{
                    min_heap.push(a);
                }
            } else if (max_heap.top() > a) {
                max_heap.push(a);
            } else {
                min_heap.push(a);
            }
            while (true) {
                if (min_heap.size() == max_heap.size() || min_heap.size() + 1 == max_heap.size()) {
                    break;
                }
                if (max_heap.size() > min_heap.size()) {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                } else {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
            if (i % 2 == 0) {
                middle.push_back(max_heap.top());
            }
        }
        cout << middle.size() << "\n";
        for (int i = 0; i < middle.size(); i++) {
            if (i > 1 && i % 10 == 0) {
                cout << "\n";
            }
            cout << middle[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}