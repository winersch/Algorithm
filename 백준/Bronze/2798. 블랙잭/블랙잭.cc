#include <iostream>
#include <vector>

using namespace std;

int card[100];
int visited[100];

int closest = 300000;

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    for (int i = 0; i < n; i++) {
        visited[i] = 1;
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                continue;
            }
            visited[j] = 1;
            for (int k = 0; k < n; k++) {
                if (visited[k]) {
                    continue;
                }
                int a = card[i] + card[j] + card[k];
                int b = m - (card[i] + card[j] + card[k]);
                if (a > m){
                    continue;
                }

                if (b == 0){
                    cout << a;
                    return 0;
                }

                closest = min(closest, b);
            }
            visited[j] = 0;
        }
        visited[i] = 0;
    }

    cout << m-closest;

    return 0;
}
