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
#include <list>
#include <unordered_set>
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

struct triple{
    int a, b, c, d;
};
vector<triple> ans;
bool comp(triple& a, triple& b){
    if (a.a == b.a){
        return a.b < b.b;
    }
    return a.a < b.a;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int b = 2; b <= 100; ++b)
        for (int c = b+1; c <= 100; ++c)
            for (int d = c+1; d <= 100; ++d) {
                int sum = b*b*b + c*c*c + d*d*d;
                int a = round(pow(sum, 1.0/3));
                if (a >= 2 && a <= 100 && a*a*a == sum) {
                    ans.push_back({a,b,c,d});
                }
            }
    std::sort(ans.begin(), ans.end(), comp);

    for(triple t : ans){
        cout << "Cube = " << t.a << ", Triple = (" << t.b << "," << t.c << "," << t.d << ")\n";
    }

    return 0;
}

