                           /*Stock span problem and its variations*/

/* The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
and we need to calculate span of stock’s price for all n days.The span Si of the stock’s price on a given 
day i is defined as the maximum number of consecutive days just before the given day, for which the price 
of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values
for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}*/


/*A Simple but inefficient method
Traverse the input price array. For every element being visited, traverse elements on left of it and increment
 the span value of it while elements on the left side are smaller.*/

//Source GFG

#include<bits/stdc++.h>
#include<stack>
using namespace std;

void stock(int arr[],int n){
    // Create a stack and push index of first 
    // element to it 
    stack<int>s;
    s.push(0);

    for(int i=0;i<n;i++){
        /* Pop elements from stack while stack is not 
         empty and top of stack is smaller than 
         price[i]*/ 
        while(s.empty()==false && arr[s.top()]<=arr[i]){
            s.pop();
        }

        int span=(s.empty()?(i+1):(i-s.top()));
        cout<<span<<" ";
        s.push(i);//push index
    }
   
}
//driver code
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stock(arr,n);

    return 0; 
}

/*Input:n=6
    10 4 5 90 120 80 

output: 1 1 2 4 5 1*/

/*IMPORTANT: if array is in decreasing order you will get index+1 span, if in incresasing order you will get only 1 1 1......  span.*/

//Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of the array is added and removed from the stack at most once. So there are total 2n operations at most. Assuming that a stack operation takes O(1) time, we can say that the time complexity is O(n).

//Auxiliary Space: O(n) in worst case when all elements are sorted in decreasing order.
