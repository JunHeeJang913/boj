#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        for(int h=0;h<n-(i+1);++h)
            cout<<" ";
        for(int j=0;j<=i;++j)
            cout<<"*";
        cout<<endl;
    }
}