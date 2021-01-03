#include <iostream>

using namespace std;

const string starBlank="* ";

int main(void){
    int n;

    cin>>n;

    for(int i=0;i<n;++i){
        for(int j=0;j<n-(i+1);++j)
            cout<<" ";
        for(int k=0;k<i+1;++k)
            cout<<starBlank;
        cout<<endl;
    }
}