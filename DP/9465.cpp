#include <iostream>
#include <cstring>

using namespace std;
int sticker[2][100001];
int cache[2][100001];
int width;

//fun(n) = max(fun(n-2), fun(n-1))
int subfindMValue(bool row, int width){
    //base case
    if(width<1) return 0;
    if(width == 1)
        return sticker[row][1];

    //memoization
    int& ret = cache[row][width];
    if(ret != -1) return ret;
    ret = max(
        sticker[row][width]+subfindMValue(!row, width-1),
        sticker[row][width]+subfindMValue(!row, width-2)
    );
    return ret;
}

int findMValue(int width){
    return max(
        subfindMValue(0,width), 
        subfindMValue(1, width)
    );
}

void initSticker(){
    int score;
    cin>>width;
    for(int i=0; i<2;++i){
        for(int j = 1; j<=width; ++j){
            cin>>score;
            sticker[i][j]=score;
        }
    }
}

int solve(){
    int maxValue;
    
    initSticker();
    memset(cache, -1, sizeof(cache));

    maxValue = findMValue(width);
    return maxValue;
}

int main(void){
    //test case;
    int T;
    cin>>T;

    while(0<T){
        int solution = solve();
        cout<<solution<<endl;
        --T;
    }

    return 0;
}