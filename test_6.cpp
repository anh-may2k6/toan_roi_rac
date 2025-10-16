//liet ke cac hoan vi cua 1,2,...n
//quay lui

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

int n;
vector<int> num;
vector<bool> used;

void back_track(int i){
    for(int j=1;j<=n;j++){
        if(used[j]) continue;
        num[i] = j;
        used[j] = true;
        if(i==n){
            for(int k=1;k<=n;k++){
                out << num[k];
            }
            out << endl;
        }
        else{
            back_track(i+1);
        }
        used[j] = false;
    }
}

void test_case(){
    in >> n;
    num.assign(n+1,0);
    used.assign(n+1,false);
    back_track(1);
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

