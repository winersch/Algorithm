#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}