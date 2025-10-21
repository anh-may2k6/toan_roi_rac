//Liệt kê các xâu nhị phân có độ dài n và có đúng k số 0 liên
//tiếp và m số 1 liên tiếp
//phương pháp quay lui
//n >= 4
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");


int n,k,m;
//mảng để lưu các số nhị phân có độ dài n và có k số 0 liên tiếp 
//m số 1 liên tiếp
vector<string> result;

bool check(string &s){
    //đếm xem trong dãy có nhiều dãy như yêu cầu đề bài ko
    //nếu có thì mình bỏ qua ko thì mình nhận
    int cnt_0 = 0 , cnt_1 = 0;
    for(int i=0; i+k <= s.size() ; i++){
        if(s.substr(i,k) == string(k,'0')){
            if((i>0 && s[i-1] == '0') || (i+k < s.size() && s[i+k] == '0')) continue;
            cnt_0++;
        }
    }
    for(int i=0; i+m <= s.size() ; i++){
        if(s.substr(i,m) == string(m,'1')){
            if((i>0 && s[i-1] == '1') || (i+m < s.size() && s[i+m] == '1')) continue;
            cnt_1++;
        }
    }
    return cnt_0 == 1 && cnt_1 == 1;
}

void back_track(string s){
    if(s.size() == n){
        if(check((s))) result.push_back(s);
        return;
    }
    back_track(s + "0");
    back_track(s + "1");

}

void test_case(){
    result.clear(); // reset mỗi test
    in >> n >> k >> m;
    back_track("");
    for(auto &x : result){
        out << x << endl;
    }
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
        out << endl;
    }
    return 0;
}