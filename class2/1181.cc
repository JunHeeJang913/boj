#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

int main(void){
    int n; cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; ++i){
        cin >> words[i];
    }
    sort(words.begin(), words.end(), compare);
    string cur;
    for(string word: words){
        if(cur == word) continue;
        cout << word << endl;
        cur = word;
    }
    return 0;
}