#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int is_palin(string a){
    string b = a;
    reverse(b.begin(),b.end());
    string c;
    string d;
    for(int i = 0; i < a.length(); i++){
        c = a;
        c.erase(i,1);
        d = c;
        reverse(d.begin(),d.end());
        if(c == d) break;
    }
    if(a == b) return 1;
    else if(c == d) return 2;
    else return 3;
}

int main(){
    ifstream ipf("palin.inp");
    ofstream opf("palin.out");
    int n;
    ipf >> n;
    string a;
    while(ipf >> a){
        opf<<is_palin(a)<<"\n";
    }
    //cout<<is_palin("axa");

    return 0;
}