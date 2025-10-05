//Dùng phương pháp sinh
#include <iostream>
#include <vector>

using namespace std;

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

int main(){
    cin >> n;
    a.assign(n+1,0);
    do{
        for(int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << endl;
    }while(sinh());
    return 0;
}