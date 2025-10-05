//liệt kê xâu nhị phân có độ dài n bằng phương pháp quay lui
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

void in(){
    for(int i=1;i<=n;i++){
        cout << a[i];
    }
    cout << endl;
}

void back_track(int i){
    for(int j=0;j<=1;j++){
        a[i] = j;
        if(i==n){
            in();
        }
        else{
            back_track(i+1);
        }
    }
}

int main(){
    cin >> n;
    a.assign(n+1,0);
    back_track(1);
    return 0;
}