#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.in");
ofstream out("output.in");

void sinh_hv(vector<int> &a){
    int l = a.size();
    int i = l-2;
    while(i>=0 && a[i] > a[i+1]) i--;
    if(i>=0){
        int j = l-1;
        while(a[j] < a[i]) j--;
        swap(a[i] , a[j]);
    }
    reverse(a.begin() + i + 1 , a.end());    
}

void cau3a(){
    vector<int> a = {2,3,7,6,10,9,8,5,4,1};
    for(int i=1;i<=5;i++){
        sinh_hv(a);
        out << "Hoan vi " << i << ": ";
        for(int x : a) out << x << " ";
        out << endl;
    }
}

bool sinh_th(vector<int> &a , int n , int k){
    int i = k-1;
    while(i>=0 && a[i] == n-k+i) i--;
    if(i<0) return false;
    a[i]++;
    for(int j=i+1;j<k;j++){
        a[j] = a[j-1]+1;
    }
    return true;
}

void cau3b(){
    out << "\nCau 3b - 5 to hop ke tiep:\n";
    int n = 10 , k = 4;
    vector<int> a = {3,5,7,9};
    for(int i=1;i<=5;i++){
        sinh_th(a,n,k);
        out << "To hop " << i << ": ";
        for(int x : a) out << x << " ";
        out << endl;
    }
}

bool sinh_binary(string &s){
    int n = s.size();
    int i = n-1;
    while(i>=0 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if(i<0) return false;
    s[i] = '1';
    return true;
}

void cau3c(){
    out << "\nCau 3c - 5 xau nhi phan ke tiep:\n";
    string s = "1000111010";
    for(int i=1;i<=5;i++){
        sinh_binary(s);
        out << "Xau " << i << ": " << s << endl;
    }
}

int main(){
    cau3a();
    cau3b();
    cau3c();
    return 0;
}