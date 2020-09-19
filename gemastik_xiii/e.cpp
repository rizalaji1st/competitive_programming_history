#include<iostream>
using namespace std;
int main(){
    long long int a, b, temp, temp_b, i, j, selesai, perulangan, n, mod = 100000037;
    cin>>n;
    cin>>a;
    a = a%mod;
    for(i=1; i<n; i++){
        cin>>b;
        perulangan = 1;
        selesai = 1;

        temp = a;
        for(j=1; j<b; j++){
            temp *= temp;
            temp = temp%mod;
            perulangan++;
            if(temp%mod == a){
                selesai = 0;
                break;
            }
        }
        if(selesai == 1){
            a = temp;
        }
        else{
            b = b%perulangan;
            temp = a;
            for(j=0; j<b; j++){
                temp*=temp;
                temp = temp%mod;
            }
            a = temp;
        }
        cout<<a<<endl;
    }
}