#include <iostream>
using namespace std;

int getmax(int b, int c){
     if(b>c){
            return b;
     }
     else{
            return c;}
}

void kpsk(int val[], int wgt[], int f, int g){
    int Ks[f+1][g+1];
    int itm,wt;

    for(wt=0;wt<=g;wt++){
            Ks[0][wt]=0;
    }
    for(itm=0;itm<=f;itm++){
            Ks[itm][0]=0;
    }
    for(itm=1;itm<=f;itm++){
            for(wt=1;wt<=g;wt++){
                if(wgt[itm]<=wt){
                    Ks[itm][wt] = getmax(Ks[itm-1][wt], val[itm] + Ks[itm-1][wt - wgt[itm]]);
    }
    else
        Ks[itm][wt]= Ks[itm-1][wt];
    }
}
    cout<<"\n\nMaximum profit: "<<Ks[f][g] << endl;

    int it[f];
    int count=0;
    int combine_weight=Ks[f][g];
    int s=f;
    int t=g;
    int count_item=1;

    while(combine_weight!=0){
        if(Ks[s][t]==Ks[s-1][t]){

            count_item++;

            s=s-1;
        }
        else{

            count_item++;

            it[count]=s;
            count++;
            combine_weight=combine_weight - val[s];
            s=s-1;
            for(int itm=0;itm<=g;itm++){
                if(Ks[s][itm]==combine_weight){

                    t=itm;
                    break;
                }
            }
        }
    }

    cout<<"Picked items: ";
    for(int itm=0;itm<count;itm++){
        cout<<"("<<wgt[it[itm]]<<","<<val[it[itm]]<<") ";
     }

    }

int main(){
     int f,itm,g;

     cout<<"Enter items number: ";
     cin>>f;

     int wgt[f+1], val[f+1];
     for(itm=1;itm<=f;itm++){
         cout<<"\nEnter weight for item "<<itm<<": ";
         cin>>wgt[itm];
         cout<<"Enter value for item "<<itm<<": ";
         cin>>val[itm];
     }

     cout<<"\nEnter capacity of knapsack: ";
     cin>>g;

     kpsk(val,wgt,f,g);
}
