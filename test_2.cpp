//Ki thuat sinh ke tiep
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

int n;
vector<int> a;

bool sinh(){
    int i = n;
    while(i>0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i==0) return false;
    a[i] = 1;
    return true;
}

void test_case(){
    in >> n;
    a.assign(n+1,0);
    do{
        for(int i=1;i<=n;i++){
            out << a[i];
        }
        out << endl;
    }while(sinh());
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