#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;
    string s;
    vector<pair<int,string>> arr;
    for (int i = 0; i < n; i++) {
        cin >> s;
        arr.push_back(make_pair(s.length(), s));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].second == arr[i+1].second){
            continue;
        }
        cout << arr[i].second << endl;
    }
    return 0;
}