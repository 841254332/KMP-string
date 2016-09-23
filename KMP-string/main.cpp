//
//  main.cpp
//  KMP-string
//
//  Created by luojiahua on 16/9/22.
//  Copyright © 2016年 luojiahua. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void get_next(string T, int next[]){
    int i = 0, j = -1;
    next[0]=0;
    while (i<T.length()) {
        if (j==-1||T[i]==T[j]) {
            i++;
            j++;
            next[i]=j+1;
        }else{
            j=next[j]-1;
        }
    }
}

int Index_kmp(string s, string t, int next[]){
    int i=0, j=0;
    while (i<s.length()&&j<t.length()) {
        if (j==-1||s[i]==t[j]) {
            i++;
            j++;
        }else{
            j=next[j]-1;
        }
    }
    if(j>=t.length()){
        cout<<i-t.length()<<endl;
        return 0;
    }else{
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "abababcdeabcfghojk";
    string t = "abc";
    int next[t.length()];
    get_next(t, next);
//    for (int i = 0; i<t.length(); i++) {
//        cout<<next[i]<<endl;
//    }
    Index_kmp(s, t, next);
    return 0;
}
