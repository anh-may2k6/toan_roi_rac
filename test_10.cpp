//Liệt kê các xâu nhị phân có độ dài n và có đúng k số 0 liên
//tiếp và m số 1 liên tiếp
//phương pháp sinh xâu nhị phân
//n >= 4
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

bool check(string &s,int k ,int m){
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

int main(){
    int t;
    in >> t;
    while(t--){
        int n,k,m;
        in >> n >> k >> m;
        int total = 1 << n;//2^n
        for(int mask = 0 ; mask < total ; mask++){
            string s;
            for(int i = n-1 ; i>=0 ; i--){
                //Chuyển hệ thập phân sang nhị phân
                s += ((mask >> i) & 1) + '0'; // giống với chia đôi
            }
            if(check(s,k,m)){
                out << s << endl;
            }
        }
        out << endl;
    }
    return 0;
}