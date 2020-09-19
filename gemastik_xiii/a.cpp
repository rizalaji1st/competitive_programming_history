#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long long int i, j,  n, temp;
    long long int a, b, c, d;
    cin>>n;
    long long int jarak[n], r[n];
    string kota_a[n], kota_b[n], str_temp;
    for(i=0; i<n; i++){
        cin>>kota_a[i];
        cin>>a>>b>>r[i];
        cin>>kota_b[i];
        cin>>c>>d>>temp;
        r[i]+=temp;
        jarak[i] = sqrt(abs(a-c)*abs(a-c) + abs(b-d)*abs(b-d));
        
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(jarak[j]>jarak[i]){
                temp = jarak[i];
                jarak[i] = jarak[j];
                jarak[j] = temp;

                temp = r[i];
                r[i] = r[j];
                r[j] = temp;

                str_temp = kota_a[i];
                kota_a[i] = kota_a[j];
                kota_a[j] = str_temp;

                str_temp = kota_b[i];
                kota_b[i] = kota_b[j];
                kota_b[j] = str_temp;
                
            }
        }
    }
    
    /*
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(r[j]-jarak[i]>0){
                temp = jarak[i];
                jarak[i] = jarak[j];
                jarak[j] = temp;

                temp = r[i];
                r[i] = r[j];
                r[j] = temp;

                str_temp = kota_a[i];
                kota_a[i] = kota_a[j];
                kota_a[j] = str_temp;

                str_temp = kota_b[i];
                kota_b[i] = kota_b[j];
                kota_b[j] = str_temp;
                break;
            }
        }
    }*/

    for(i=0; i<n; i++){
        cout<<kota_a[i]<<" "<<kota_b[i]<<" "<<jarak[i]<<endl;
    }
}