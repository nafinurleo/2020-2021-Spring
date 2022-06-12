//Quick Sort
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

//Counting Sort
/*
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void ctsort(int p_arr[] , int p_sz);

void ctsort(int p_arr[], int p_sz){
    int mx_val;

    mx_val = *max_element(p_arr, p_arr + p_sz);

    int q_arr[mx_val];
    int count = 0;

    for(int i=0 ; i<mx_val; i++){
        q_arr[i] = 0;
    }

    for(int i=0 ; i<p_sz; i++){
        for(int j=0 ; j<p_sz; j++){
            if(p_arr[i] == p_arr[j]){
                count++;
            }
        }

        for(int k=0 ; k<mx_val; k++){
            if(p_arr[i] == k+1){
                q_arr[k+1] = count;
            }
        }
        count = 0;
    }

    for(int i=0 ; i<mx_val; i++){
        q_arr[i+1] = q_arr[i] + q_arr[i+1];
    }

    int r_arr[p_sz+1];

    for(int i=p_sz-1; i>=0; i--){
        r_arr[q_arr[p_arr[i]]] = p_arr[i];
        q_arr[p_arr[i]]--;
    }

    cout << endl << endl ;
    for(int i=p_sz; i>=1 ; i--){
        cout << r_arr[i] << "  ";
    }
}

int main(){
    cout << "Enter The Number Of Values: ";
    int p_sz;
    cin >> p_sz;

    cout << "\nEnter " << p_sz << " Values:" << endl;
    int p_arr[p_sz];
    for(int i=0; i<p_sz; i++){
        cin >> p_arr[i];
        if(int(p_arr[i]+'0') < 48 || int(p_arr[i]+'0') > 57){
            cout << "Invalid";
            return 0;
        }
    }

    cout<< "\nAfter Counting Sort: ";
    ctsort(p_arr, p_sz);
    return 0;
}*/
