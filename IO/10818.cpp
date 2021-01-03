#include <iostream>
#define MAX 1000000
#define MIN -1000000

using namespace std;

int main(void){
    int n;
    cin>>n;

    int max=MIN;
    int min=MAX;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(max<=a) max = a;
        if(a<=min) min = a;
    }

    cout<<min<<" "<<max;

    return 0;
}