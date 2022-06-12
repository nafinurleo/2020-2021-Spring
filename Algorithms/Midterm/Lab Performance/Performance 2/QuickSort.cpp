#include <iostream>
using namespace std ;

void ptarray(int Array[], int l){
        for (int i=l-1; i>=0; i--){
            cout << (char)Array[i] << " ";
        }
}

void swp(int *pq , int *r){
    int tmp=*pq;
    *pq=*r;
    *r=tmp;
}

int quicksort(int Array[], int l){
    int pivot=l-1;
    int r=0;
    int pq=0;
    for(int j=pq; j<l; j++){
        if (Array[pq]<=Array[pivot]){
            swp(&Array[pq],&Array[r]);
            r++;
            pq++;
        }
        else{
            pq++;
        }
    }
    return r;

}

void divide(int Array[],int pq,int t){
    if (pq<t){
        int pivot=quicksort(Array,t);
        divide(Array,pq,pivot-1);
        divide(Array,pivot,t);
    }
}

int main(){
    string wd;
    cout << "Enter String: " << endl ;
    cin >> wd;

    char bc[wd.length()];
    int asc[wd.length()];

    for(int i=0 ; i<wd.length(); i++){
        bc[i] = wd.at(i);
    }

    for(int i=0 ; i<wd.length(); i++){
        asc[i] = (int)bc[i];
    }

    for(int i=0 ; i<wd.length(); i++){
        if(asc[i] < 65 || asc[i] > 90){
            cout << "Invalid Input" ;
            return 0 ;
        }
    }

    quicksort(asc,wd.length());
    divide(asc,0,wd.length());
    cout<<"\nAfter Quick Sort: " <<endl;
    ptarray(asc,wd.length());
    cout<<"\n";
    return 0;
}
