#include <iostream>
#include <vector>

using namespace std;
int n;
long long numOfSwap = 0;

vector<int> seq;
vector<int> seq2;

void merge(int left, int right){
    int mid = (left+right) / 2;

    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right){
        if(seq[i] <= seq[j]){
            seq2[k++] = seq[i++];
        } else {
            seq2[k++] = seq[j++];
            numOfSwap += (long long) (mid + 1 - left);
        }
    }

    int temp;
    if(i < mid) temp = i;
    else temp = j;

    while(k <= right) seq2[k++] = seq[temp++];

    for(int i = left; i <= right; ++i) seq[i] = seq2[i];
}

void mergeSort(int left, int right){
    int mid = (left+right)/2;
    if(left < right){
        mergeSort(left,mid);
        mergeSort(mid+1, right);
        merge(left,right);
    }
}

/*
void bubSort(){
    for(int i = n - 1; i > 0; --i){
        for(int j = 0; j < i; ++j){
            if(seq[j] > seq[j+1]){
                int temp = seq[j];
                seq[j] = seq[j+1];
                seq[j+1] = temp;
                ++numOfSwap;
            }
        }
    }
}*/

int main(void){
    cin >> n;
    seq.reserve(n);
    seq2.reserve(n);
    for(int i = 0; i < n; ++i){
        cin >> seq[i];
    }
    mergeSort(0, n-1);

    cout << numOfSwap;
}