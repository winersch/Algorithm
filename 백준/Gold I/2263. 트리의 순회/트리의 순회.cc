#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f;
#define mod 1000000000;
using namespace std;

int n;

vector<int> buildPreorder(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& inorderMap){
    if (inStart > inEnd || postStart > postEnd){
        return {};
    }
    int rootVal = postorder[postEnd];
    int rootIdx = inorderMap[rootVal];

    int left = rootIdx - inStart;

    vector<int> leftPreorder = buildPreorder(inorder, postorder, inStart, rootIdx-1, postStart, postStart + left-1, inorderMap);
    vector<int> rightPreorder = buildPreorder(inorder, postorder, rootIdx+1, inEnd, postStart+left, postEnd -1, inorderMap);

    vector<int> preorder;
    preorder.push_back(rootVal);
    preorder.insert(preorder.end(), leftPreorder.begin(), leftPreorder.end());
    preorder.insert(preorder.end(), rightPreorder.begin(), rightPreorder.end());

    return preorder;
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >>n;
    int a;
    vector<int> inorder, postorder;
    unordered_map<int,int> inorderMap;
    for (int i = 0; i < n; i++) {
        cin >> a;
        inorder.push_back(a);
        inorderMap[a] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        postorder.push_back(a);
    }

    vector<int> preorder = buildPreorder(inorder, postorder, 0, n-1, 0, n-1, inorderMap);

    for(int x : preorder){
        cout << x << " ";
    }

    return 0;
}
