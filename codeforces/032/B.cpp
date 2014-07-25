#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    while( getline(cin,s) ){
        for( int i = 0 ; i != s.length() ; i++){
            if(s[i] == '.' )
                cout << '0';
            else {
                if( i+1 != s.length() ){
                    if( s[i+1]  == '.'){
                        cout << '1';
                        i++;
                    }
                    else{
                        cout << '2';
                        i++;
                    }
                }
            }
        }
        cout << endl;
    }
}

// 137963	2010-10-02 11:19:59	delta_4d	B - Borze	GNU C++	Accepted	30 ms	1300 KB
