//Liệt các cách chia số tự nhiên n thành các số nhỏ hơn n
//Dùng thuật toán quay lui
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

int n;
vector<int> a;

void back_track(int sum , int last){
    if(sum == n){
        for(int i=0;i<a.size();i++){
            if(i>0) out << " + ";
            out << a[i];
        }
        out << endl;
        return;
    }
    for(int next = min(last , n-sum) ; next >=1 ; next--){
        a.push_back(next);
        back_track(sum + next , next);
        a.pop_back(); // quay lui ở chỗ này
    }
}

void test_case(){
    in >> n;
    a.clear();
    back_track(0,n-1);
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