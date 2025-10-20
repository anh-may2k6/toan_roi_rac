//Liệt kê các cách chia số tự nhiên n thành tổng các số nhỏ hơn
//sinh kế tiếp
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
    while(i>0 && a[i] == 1)  i--;
    if(i==0) return false;
    a[i]--;
    int sum = 0;
    for(int j=1;j<=i;j++){
        sum += a[j];
    }
    int res = n - sum;

    k=i;
    while(res > a[i]){
        a[++k] = a[i];
        res -= a[i];
    }
    if(res > 0) a[++k] = res;
    return true;
}

void test_case(){
    in >> n;
    a.assign(n+1 , 0);
    k = 1;
    a[k] = n;
    do{
        if(a[1] != n){
            for(int i=1;i<=k;i++){
                if(i>1) out << " + ";
                out << a[i];
            }
            out << endl;
        }
    }while(sinh());
    out << endl;
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }    
    return 0;
}