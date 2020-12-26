#include <iostream>

using namespace std;

int main(void){
    int a,b;
    char comma;
    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        cin>>a>>comma>>b;
        cout<<a+b<<endl;
    }
    return 0;
}