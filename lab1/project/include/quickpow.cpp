#include<iostream>
#include<algorithm>
using namespace std;

double quickpow(int a,int b,int q){
    if(a == 1  ||  b == 0){
        return 1;
    }
    if (b%2 == 0){
        int p = quickpow(a,b/2,q);
        return (p*p)%q;
    }else{
        int p = quickpow(a,(b-1)/2,q);
        return (p*p)%q;
    }
}


double myPow(double a, int b,int q){
    long long k = b;
    if( k >=0){
        return quickpow(a,b,q);
    }else{
        return 1/quickpow(a,b,q);
    }
}
int main(){
    cout<<myPow(2,10,1000)<<endl;
    return 0;
}