#include<iostream>
#include<limits>
using namespace std;

int MCM(int b[],int c){
    cout<<c<<endl;

    int d[c][c];
    int s,t,m,n,o;
    for(s=1;s<=c;s++){
        d[s][s] = 0;}
    for (n=2;n<=c;n++){
            for (s=1;s<=c-n+1;s++){
                t = s+n-1;
                d[s][t] = INT_MAX;
                    for (m=s;m<=t-1;m++){
                        o = d[s][m]+d[m+1][t]+b[s-1]*b[m]*b[t];
                            if (o<d[s][t]){
                                    d[s][t] = o;
                            }
                        }
                    }
                }
    return d[1][c];
}

int main(){
     int c,s;
     cout<<"\nEnter number of matrices: ";
     cin>>c;

     int arr[c+1];
     cout<<"\nEnter dimensions:-\n ";
     for(s=0;s<=c;s++){
            cout<<"\nEnter d"<<s<<" : ";
            cin>>arr[s];
     }
     cout<<"Minimum number of multiplication is: "<<MCM(arr,c);
     return 0;
}
