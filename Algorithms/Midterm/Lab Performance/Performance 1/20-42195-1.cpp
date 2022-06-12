#include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int allcharacter = 26;

void mergesortstring(string& str){

        int countcharacter[allcharacter] = {0};
            for(int i=0; i<str.length(); i++){
                countcharacter[str[i]-'a']++;
            }

            for(int i=allcharacter-1; i>=0; i--){
                for (int j=0; j<countcharacter[i]; j++){
                    cout << (char)('a'+i);
                    }
                }

}

int main(){

    string s;
    cout << "Enter the character: ";
    cin >> s;
    cout << "Output: ";
    mergesortstring(s);
    return 0;
}
