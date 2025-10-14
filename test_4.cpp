#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<bool> used;

void quay_lui(int k){
    if(k > n){
        for(int i=1;i<=n;i++) cout << a[i];
        cout << " ";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            a[k] = i;
            used[i] = true;
            quay_lui(k+1);
            used[i] = false;
        }
    }
}

void test_case(){
    cin >> n;
    a.assign(n+1,0);
    used.assign(n+1,false);
    quay_lui(1);
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}