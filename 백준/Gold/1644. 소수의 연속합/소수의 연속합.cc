#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<int> prime;
int num[4000001];
bool isPrime[4000001];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    isPrime[0] = true;
    isPrime[1] = true;
    for (int i = 2; i*i < 4000001; i++) {
        if (!isPrime[i]){
            for (int j = i*i; j < 4000001; j+=i) {
                isPrime[j] = true;
            }
        }
    }
    for (int i = 0; i < 4000001; i++) {
        if (!isPrime[i]){
            prime.push_back(i);
        }
    }

    for (int i = 0; i < prime.size(); i++) {
        int sum = prime[i];
        num[sum]++;
        for (int j = i+1; j < prime.size(); j++) {
            sum += prime[j];
            if (sum > 4000000){
                break;
            } else{
                num[sum]++;
                if (sum == 20){
                    cout <<i << " " <<  j << "\n";
                }
            }
        }
    }

    cout << num[n];
    return 0;
}