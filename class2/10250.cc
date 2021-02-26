#include <iostream>

using namespace std;

int MAX = 101;
int H, W, T;

int main(){
    cin >> T;
    for(int i = 0; i < T; ++i){
        int n;
        cin >> H >> W >> n;
        int stair = n % H; int ho = n / H + 1;
        if(stair == 0){
            stair = H;
            --ho;    
        }
        if(ho < 10)
            cout << stair << 0 << ho << endl;
        else 
            cout << stair << ho << endl;
    }
    return 0;
}