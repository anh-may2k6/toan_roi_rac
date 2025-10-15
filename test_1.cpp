//kỹ thuật quay lui

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

int n;
vector<int> a;

void back_track(int i){
    for(int j=0;j<=1;j++){
        a[i] = j;
        if(i == n-1){
            for(int k : a){
                out << k;
            }
            out << endl;
        }
        else{
            back_track(i+1);
        }
    }
}

void test_case(){
    in >> n;
    a.assign(n, 0);
    back_track(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}