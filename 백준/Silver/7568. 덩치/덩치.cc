#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int weight[51];
int height[51];
int result[51];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (weight[i] > weight[j] && height[i] > height[j]){
                result[j]++;
            }else if (weight[j] > weight[i] && height[j] > height[i]){
                result[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i]+1 << " ";
    }
    return 0;
}

