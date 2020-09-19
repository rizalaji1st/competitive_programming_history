#include<iostream>
using namespace std;
int main(){
    int i, j, k, n, a, b, c;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>a>>b>>c;
        for(j=0; j<c; j++){
            if(a>b) a = a/2;
            else b = b/2;
        }
        if(a>b)cout<<a<<" "<<b<<endl;
        else cout<<b<<" "<<a<<endl;
    }
}