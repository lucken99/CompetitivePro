                                              // FIND ARRAY IS SORTED OR NOT 


#include<iostream>

using namespace std;

bool sorted(int *arr,int n){
    if(n==1){             //BASE CASE
        return true;
    }
    if(arr[0]<arr[1] && sorted(arr+1,n-1)){  //dividing problem into n-1 and campare first and second element 
        return true;
    }
    return false;
}

int main(){
    int x;
    cin>>x;
    int arr[x];
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    if(sorted(arr,n)){                 //caller function
        cout<<"Yes sorted.";
    }
    else{
        cout<<"Not sorted.";
    }
    return 0;
    
}

/*INPUT:  6
           1 2 3 4 5 6
 OUTPUT:  Yes sorted.      */
