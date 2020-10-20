                                        //Find_next_greater_element
                       
/*Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is 
the first greater element on the right side of x in array. Elements for which no greater element exist, consider 
next greater element as -1.*/

/*BEST APPROACH:
(Using Stack)

Push the first element to stack.
Pick rest of the elements one by one and follow the following steps in loop.
Mark the current element as next.
If stack is not empty, compare top element of stack with next.
If next is greater than the top element,Pop element from stack. next is the next greater element for the popped element.
Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
Finally, push the next in the stack.
After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.*/

#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int> nextgreater(int arr[],int n){
    // Create Two stack and push last element into first
   
    stack<int>s,s1;
    s.push(arr[n-1]);
    s1.push(-1);
    for(int i=n-2;i>=0;i--){
         /* After iterating over the loop, the remaining 
           elements in stack do not have the next greater 
           element, so print -1 for them */
        while(s.empty()==false && s.top()<=arr[i]){
            s.pop();
        }

        int next=(s.empty()?-1:s.top());
        s1.push(next);
    }
    
   return s1;
}
//driver code
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    stack<int>s=nextgreater(arr,n);
    int k=s.size();
    for(int i=0;i<k;i++){
        cout<<s.top()<<" ";
        s.pop();
        
    }
    return 0;
    
}

/*INPUT: 11, 13, 21, 3
Output:
 11 -- 13
 13 -- 21
 3 -- -1
 21 -- -1
Time Complexity: O(n).
The worst case occurs when all elements are sorted in decreasing order. If elements are sorted in decreasing order, then every element is processed at most 4 times.

Initially pushed to the stack.
Popped from the stack when next element is being processed.
Pushed back to the stack because the next element is smaller.
Popped from the stack in step 3 of algorithm.*/
