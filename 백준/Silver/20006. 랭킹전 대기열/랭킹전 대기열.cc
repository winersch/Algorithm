#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
vector<pair<int,vector<pair<int,string>>>> room;

bool comp(pair<int,string>& p1, pair<int,string>& p2){
    return p1.second < p2.second;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        string s;
        cin >> a >> s;
        if (room.empty()){
            vector<pair<int,string>> v;
            v.push_back({a,s});
            room.push_back({a,v});
            continue;
        }
        bool entered = false;
        for (int j = 0; j < room.size(); j++) {
            if (abs(room[j].first - a) <= 10 && room[j].second.size() < m){
                room[j].second.push_back({a,s});
                entered = true;
                break;
            }
        }
        if (!entered){
            vector<pair<int,string>> v;
            v.push_back({a,s});
            room.push_back({a,v});
        }
    }

    for (int i = 0; i < room.size(); i++) {
        std::sort(room[i].second.begin(), room[i].second.end(), comp);
        if (room[i].second.size() == m){
            cout << "Started!\n";
        }else{
            cout << "Waiting!\n";
        }
        for (int j = 0; j < room[i].second.size(); j++) {
            cout << room[i].second[j].first << " " << room[i].second[j].second << "\n";
        }
    }

    return 0;
}

