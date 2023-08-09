#include <iostream>
using namespace std;

int main() {
    int a, b, c, profit; // a = 고정비용, b = 생산원가, c = 판매단가
    cin >> a >> b >> c;
    profit = c-b;
    if (profit <= 0){
        cout << -1;
        return 0;
    }
    cout << a/profit+1;
    return 0;
}
