#include <iostream>

int Sumatoria(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return n + Sumatoria(n-1);
}

int main(){ std::cout<<Sumatoria(5)<<"\n"; }