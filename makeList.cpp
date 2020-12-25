#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define URL "boj.kr/"

void makeURL(ofstream & fout, const string & url, const string proNum){
    string proUrl = url + proNum;
    fout<<proUrl<<endl;
}

bool hasLetter(const string & word, const char & letter = '@'){
    const int length = word.length();
    for(int i = 0; i < length; i++){
        if(word[i]==letter)
            return true;
    }
    return false;
}


int main(void){
    const string baseUrl = URL;
    ofstream result;
    result.open("D:\\MyStudy\\boj\\algorithmQList.txt");
    if(!result){
        cout<<"출력파일 열기에 실패"<<endl;
        return 1;
    }
    ifstream numText;
    numText.open("D:\\MyStudy\\boj\\num.txt");
    if(!numText){
        cout<<"입력파일 열기에 실패"<<endl;
        return 1;
    }

    while(numText.get()!=EOF){
        string temp;
        numText>>temp;
        if(hasLetter(temp,'@')==false){
            if(hasLetter(temp, ',')==true)
                temp.pop_back();
            makeURL(result, baseUrl, temp);
        }
        else{
            result<<temp<<endl;
        }
    }

    result.close();
    numText.close();
}