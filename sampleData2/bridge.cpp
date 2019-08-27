#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define enoughsht 0.001

using namespace std;

double length(vector<double> &p1, vector<double> &p2){
    return sqrt(pow((p1[0]-p2[0]),2)+pow((p1[1]-p2[1]),2)+pow((p1[2]-p2[2]),2));
}

int find_length(vector<double> &p1, vector<double> &p2, vector<double> &p3){
    vector<double> p4;
    for(int i = 0; i < p1.size(); i++){
        p4.push_back((p1[i]+p2[i])/2);
    }

    if(length(p1,p2) < enoughsht) {
        return ceil(length(p1,p3));
    }
    else if(length(p1,p3) < length(p2,p3)){
        return find_length(p1,p4,p3);
    }
    else {
        return find_length(p2,p4,p3);
    }
}

int main(){
    ifstream ipf("bridge.inp");
    ofstream opf("bridge.out");
    double xpoint,ypoint,ppoint;
    vector<vector<double>> ps;
    vector<double> p;
    while(ipf >> xpoint >> ypoint >> ppoint){
        p.push_back(xpoint);
        p.push_back(ypoint);
        p.push_back(ppoint);
        ps.push_back(p);
        p.clear();
    }
    /*for(auto it = ps.begin(); it != ps.end(); it++){
        for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++){
            cout<<*it2;
        }
        cout<<endl;
    }*/
    cout<<find_length(ps[0],ps[1],ps[2]);
    //cout<<is_palin("axa");

    return 0;
}