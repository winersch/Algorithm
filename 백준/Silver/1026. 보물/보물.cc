#include <iostream>
#include <algorithm>

using namespace std;

int A[50];
int B[50];

int main() {
    int num, sum=0;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < num; i++) {
        cin >> B[i];
    }

    sort(A,A+num);
    sort(B,B+num, greater<int>());

    for (int i = 0; i < num; i++) {
        sum += (A[i]*B[i]);
    }
    cout << sum;
    return 0;
}
