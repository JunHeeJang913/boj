#include <iostream>
#include <string>

using namespace std;

const string day[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};

const int dateOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(void){
    int month, date;
    cin>>month>>date;

    int sumOfDDiff=0; 
    int mDiff=month-1;
    int dDiff=date;

    for(int i=0;i<mDiff;++i)
        sumOfDDiff+=dateOfMonth[i];
    sumOfDDiff+=date-1;

    cout<<day[sumOfDDiff%7];
}