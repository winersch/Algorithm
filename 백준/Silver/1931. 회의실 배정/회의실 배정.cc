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

    vector<pair<int, int>> v;
    int n, end_time, using_time, count = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    end_time = v[0].second;
    using_time = v[0].second - v[0].first;
    count++;
    for (int i = 1; i < n; i++) {
        if (end_time > v[i].second && using_time > v[i].second-v[i].first){
            end_time = v[i].second;
            using_time = v[i].second - v[i].first;

        }else if(v[i].first >= end_time){
            end_time = v[i].second;
            using_time = v[i].second - v[i].first;
            count++;
        }
    }

    cout << count;

    return 0;
}