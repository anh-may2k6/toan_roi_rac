//liet ke cac hoan vi cua 1,2,...n
//sinh ke tiep
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

int n;
vector<int> a;

bool sinh(){
    int i = n-1;
    while(i>0 && a[i] > a[i+1]) i--;
    if(i==0) return false;
    int j = n;
    while(a[j] < a[i]) j--;
    swap(a[i],a[j]);
    reverse(a.begin()+i+1,a.end());
    return true;    
}

void test_case(){
    in >> n;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++){
        a[i] = i;
    }
    do{
        for(int j=1;j<=n;j++){
            out << a[j];
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
