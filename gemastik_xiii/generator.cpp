#include<iostream>
using namespace std;
long long int i, j, n, t, temp;
int main(){
    long long int mod = 100000037;
    cin>>n;
    cout<<n<<endl;
    temp = n %mod;
    cout<<temp<<endl;
    for(i=1; i<1000000; i++){
        temp = temp*n;
        cout<<i<<" "<<temp<<endl;
        if(temp == n){
            break;
        }
    }
}
