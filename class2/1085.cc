#include <iostream>

using namespace std;

int main(void){
    int x, y; cin >> x >> y;
    int w, h; cin >> w >> h;

    cout << min(y, min(x, min(w-x, h-y)));
}