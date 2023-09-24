#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

vector<int> result;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    queue<int> yose;
    for (int i = 1; i <= n; i++) {
        yose.push(i);
    }

    while(!yose.empty()){
        for (int i = 0; i < k-1; i++) {
            yose.push(yose.front());
            yose.pop();
        }
            result.push_back(yose.front());
            yose.pop();
    }
    cout << "<";
    for (int i = 0; i < result.size()-1; i++) {
        cout << result[i] << ", ";
    }
    cout << result[result.size()-1] << ">";
    return 0;
}