#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str;
    cin>>str;
    int i = 0;
    while(str[i]!='\0'){
        cout<<str[i];
        i++;
        if(i%10==0)
            cout<<endl;
    }
}