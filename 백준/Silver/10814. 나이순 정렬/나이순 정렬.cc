#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
bool compare(pair<pair<int, string>,int> a, pair<pair<int, string>,int> b){
    if (a.first.first == b.first.first){
        return a.second < b.second;
    }
    return a.first.first < b.first.first;
}

int main() {
    int n;
    vector<pair<pair<int, string>,int>> member;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        string s;
        cin >> a >> s;
        member.push_back({{a, s},i});
    }
    sort(member.begin(), member.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << member[i].first.first << " " << member[i].first.second << "\n";
    }
    return 0;
}

