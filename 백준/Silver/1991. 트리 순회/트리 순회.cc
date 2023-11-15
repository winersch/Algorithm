#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;


int n;
vector<pair<pair<char, char>, char>> v;


void visit(int a) {
    cout << v[a].second;
}

void preorder(int a) {
    visit(a);
    if (v[a].first.first != '.') {
        preorder(v[a].first.first - 'A');
    }
    if (v[a].first.second != '.') {
        preorder(v[a].first.second - 'A');
    }
}

void inorder(int a) {
    if (v[a].first.first != '.') {
        inorder(v[a].first.first - 'A');
    }
    visit(a);
    if (v[a].first.second != '.') {
        inorder(v[a].first.second - 'A');
    }
}

void postorder(int a) {
    if (v[a].first.first != '.') {
        postorder(v[a].first.first - 'A');
    }
    if (v[a].first.second != '.') {
        postorder(v[a].first.second - 'A');
    }
    visit(a);
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        v[parent - 'A'].second = parent;
        v[parent - 'A'].first.first = left;
        v[parent - 'A'].first.second = right;

    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

    return 0;
}