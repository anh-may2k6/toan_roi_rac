//Liet ke cac tap con k phan tu cua 1,2,...n
//Sinh ke tiep
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

int n,k;
vector<int> a;

bool sinh(){
    int i = k;
    while(i>0 && a[i] == n-k+i) i--;
    if(i==0) return false;
    a[i]++;
    for(int j=i+1;j<=k;j++){
        a[j] = a[j-1] + 1;
    }
    return true;
}

void test_case(){
    in >> k >> n;
    a.assign(k+1 , 0);
    for(int i=1;i<=k;i++){
        a[i] = i;
    }
    do{
        for(int i=1;i<=k;i++){
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