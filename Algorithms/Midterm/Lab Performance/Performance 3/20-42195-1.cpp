#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Itm{
        string in;
        int oja;
        int ojp;
        float opap;
};

void FractionalKnapsack(Itm itm[],int tn,int al);

void FractionalKnapsack(Itm itm[],int tn,int al){
        int ra;
        float fp;
        float ta = 0, tp =0;

        for(int i=0;i<tn;i++){
            if(itm[i].oja + ta<=al){
                ta = ta+itm[i].oja;
                tp = tp+itm[i].ojp;
                cout<<"Choose Item: "<<itm[i].in<<"\nAmount: "<<itm[i].oja<<"\nPrice: "<<itm[i].ojp<<"\All amount: "<<ta<<"\nAll price: "<<tp<<endl;
            }
            else{
                ra = (al-ta);
                fp = ra*(float(itm[i].ojp)/itm[i].oja);
                ta = ta+ra;
                tp = tp+fp;
                cout<<"\nChoose Item: "<<itm[i].in<<"\nAmount: "<<ra<<"\nPrice: "<<fp<<"\nAll amount:"<<ta<<"\nAll price: "<<tp<<endl;
                break;
            }
        }

        cout<<endl<<endl;
        cout<<"All amount: "<<ta<<endl;
        cout<<"All price: "<<tp<<endl;
        cout<<endl;
}

int main(){
    Itm itm[5] = {{"i1",16,10,0},{"i2",16,8,0},{"i3",10,6,0},{"i4",7,3,0},{"i5",1,1,0}};
    Itm bc;

    int tn = 5;
    int al = 21;

    for(int i=0;i<tn;i++){
            itm[i].opap = float(itm[i].ojp)/itm[i].oja;
        }
    for(int i=1;i<tn;i++){
            for(int j=0;j<tn-1;j++){
                if(itm[j+1].opap<itm[j].opap){
                    bc = itm[j+1];
                    itm[j+1] = itm[j];
                    itm[j] = bc;
                }
            }
        }
    FractionalKnapsack(itm,tn,al);

    return 0;
}
