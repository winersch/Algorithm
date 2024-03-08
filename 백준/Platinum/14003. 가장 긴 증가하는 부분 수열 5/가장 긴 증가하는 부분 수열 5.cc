#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

int n;
vector<int> v;
vector<int> lis, record;

int binarySearch(int id) {
    int mid;
    int left = 0, right = lis.size() - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < id) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a ;
        v.push_back(a);
    }

    lis.push_back(v[0]);
    for (int i = 0; i < n; i++) {
        if (lis.back() < v[i]) {
            lis.push_back(v[i]);
            record.push_back(lis.size() - 1);
        } else {
            int pos = binarySearch(v[i]);
            lis[pos] = v[i];
            record.push_back(pos);
        }
    }

    cout << lis.size();
    cout << endl;
    vector<int> k;
    int tmp = lis.size() - 1;
    for (int i = record.size() - 1; i >= 0; i--) {
        if (tmp == record[i]){
            tmp--;
            k.push_back(v[i]);
        }
    }

    std::sort(k.begin(), k.end());
    for (int i = 0; i < k.size(); i++) {
        cout << k[i] << " ";
    }

    return 0;
}