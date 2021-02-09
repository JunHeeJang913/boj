#include <iostream>
#include <vector>

using namespace std;

//tree의 구현. 노드 수가 많지 않으니 배열로!
const int MAX = 26;
pair<char, char> biTree[MAX];
int n;

void initTree(){
    cin >> n;

    for(int i = 0; i < n; ++i){
        char p, lc, rc;
        cin >> p >> lc >> rc;
        biTree[p-'A'] = make_pair(lc, rc);
    }
}

void preOrder(int node){
    cout << (char)(node + 'A');
    char lc = biTree[node].first;
    char rc = biTree[node].second;
    if(lc != '.')
        preOrder(lc - 'A');
    if(rc != '.')
        preOrder(rc - 'A');
}

void inOrder(int node){
    char lc = biTree[node].first;
    char rc = biTree[node].second;
    if(lc != '.')
        inOrder(lc - 'A');
    cout << (char)(node + 'A');
    if(rc != '.')
        inOrder(rc - 'A');
}

void postOrder(int node){
    char lc = biTree[node].first;
    char rc = biTree[node].second;
    if(lc != '.') postOrder(lc - 'A');
    if(rc != '.') postOrder(rc - 'A');
    cout << (char)(node + 'A');
}

int main(void){
    initTree();
    preOrder(0); cout << '\n';
    inOrder(0); cout << '\n';
    postOrder(0); cout << '\n';
    return 0;
}