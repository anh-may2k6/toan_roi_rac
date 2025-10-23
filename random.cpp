#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomInt(int min , int max){
    return min + rand() % (max - min + 1);
}

int main(){
    srand(time(0));
    cout << randomInt(1,100);
    return 0;
}