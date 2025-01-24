#include <iostream>
using namespace std;

// fibbo

int fibbo(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibbo(n-1) + fibbo(n-2);
    }
}

// prime 

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    
    for(int i=2; i*i <=n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}


int main() {
    
    int n = 10;
    // cout<<fibbo(n)<<endl;

    // for(int i=1; i<=n; i++){
    //     cout<<fibbo(i)<<" ";
    // }

    int number = 17;

    if(isPrime(number)){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"Non prime"<<endl;
    }

    

    return 0;
}