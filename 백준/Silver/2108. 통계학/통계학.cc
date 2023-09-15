#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main() {
    int n, sum = 0, mode = 0, tmode = 0, top = -5000, low = 5000;
    vector<int> v, vmode;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++) {
        top = max(top, v[i]);
        low = min(low, v[i]);
        if (i == n-1){
            if (tmode > mode){
                mode = tmode;
                vmode.clear();
                vmode.push_back(v[i]);
            }else if(tmode == mode){
                vmode.push_back(v[i]);
            }
        }else if (v[i] != v[i+1]){
            if (tmode > mode){
                mode = tmode;
                vmode.clear();
                vmode.push_back(v[i]);
            }else if(tmode == mode){
                vmode.push_back(v[i]);
            }
            tmode = 0;
        }else{
            tmode++;
        }

    }

    sort(vmode.begin(), vmode.end());

    if (vmode.size()>1){
        mode = vmode[1];
    }else{
        mode = vmode[0];
    }

    cout << int(round(double(sum)/n)) << "\n";
    cout << v[n/2] << "\n";
    cout << mode << "\n";
    cout << abs(top-low) << "\n";

    return 0;
}
