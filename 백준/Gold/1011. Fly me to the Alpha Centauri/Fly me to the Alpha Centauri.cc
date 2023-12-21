#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        double dist = y-x;
        double rdist = sqrt(dist);
        int rounddist = round(sqrt(dist));

        if (rdist <= rounddist){
            cout << rounddist *2-1 << "\n";
        }else{
            cout << rounddist * 2 << "\n";
        }

    }
    return 0;
}