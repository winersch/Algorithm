#include <iostream>

using namespace std;



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a;
    cin >> a;
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int b, c;
        cin >> b >> c;
        sum += b * c;
    }
    if (a==sum){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}