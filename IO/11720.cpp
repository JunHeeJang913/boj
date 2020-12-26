#include <iostream>
#include <string>

using namespace std;

int main(void){
    int num;
    int sum = 0;
    string str;
    cin>>num>>str;
    for(int i = 0; i<num; ++i){
        int temp;
        temp = str[i]-'0';
        sum+=temp;
    }
    cout<<sum<<endl;
}