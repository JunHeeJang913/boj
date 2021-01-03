#include <iostream>

using namespace std;

string calBlank(int i){
    string blank="";
    for(int j=0;j<2*i-1;++j)
        blank+=" ";
    return blank;
}

int main(void){
    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        if(i!=n-1){
            for(int j=0;j<n-(i+1);++j){
                cout<<" ";
            }
            if(i==0)
                cout<<"*";
            else 
                cout<<"*"<<calBlank(i)<<"*";
        }
        else{
            for(int j=0;j<2*i+1;++j){
                cout<<"*";
            }
        }
        cout<<endl;
    }
}