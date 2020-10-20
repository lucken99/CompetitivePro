                                        //Water Tapping Problem


/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute
how much water it is able to trap after raining.
Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 
 Basic Insight: 
An element of the array can store water if there are higher bars on left and right. The amount of water 
stored in every element can be found out by finding the heights of bars on the left and right sides. 
The idea is to compute the amount of water that can be stored in every element of the array. 
*/
//Source :GFG
#include<bits/stdc++.h>

using namespace std;

// Function to return the maximum 
// water that can be stored 
int store_water(int arr[],int n){
    int lmax[n],rmax[n];
    int res=0;
    lmax[0]=arr[0];
    rmax[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],arr[i]);
        }
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(arr[i],rmax[i+1]);
    }
    // Calculate the accumulated water element by element 
    // consider the amount of water on i'th bar, the 
    // amount of water accumulated on this particular 
    // bar will be equal to min(lmax[i], rmax[i]) - arr[i]
    for(int i=1;i<n-1;i++){
        res=res+(min(lmax[i],rmax[i])-arr[i]);
    }
        
    
    return res;
}
//Driver code
int main(){
    int arr[]={5,0,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=store_water(arr,n);
    cout<<m;
    return 0;
    
    
}

/*Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Time complexity:O(n)
Only one traversal of the array is needed, So time Complexity is O(n).

Space Complexity: O(n). 
Two extra array is needed each of size n.*/
