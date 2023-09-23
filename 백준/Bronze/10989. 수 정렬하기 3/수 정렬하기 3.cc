#include <iostream>


using namespace std;

int num[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num[a]++;
    }

    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < num[i]; j++) {
            cout << i << "\n";
        }
    }

    return 0;
}