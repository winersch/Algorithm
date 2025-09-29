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
#include <ctime>
#include <iomanip>
#include <regex>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int arr[5], ans[5] = {1,2,3,4,5};

bool check(){
    for (int i = 0; i < 5; i++) {
        if (arr[i] != ans[i]){
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    while(!check()){
        for (int i = 0; i < 4; i++) {
            if (arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                for(int a : arr){
                    cout << a << " ";
                }
                cout << "\n";
            }
        }
    }


    return 0;
}
