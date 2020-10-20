                               //COUNT_SET_BIT_USING_LOOKUP_METHOD
        
/*Here we assume that the size of INT is 32-bits. It’s hard to count all 32 bits in one go using lookup table (” because it’s infeasible to create lookup table of size 232-1 “). So we break 32 bits into 8 bits of chunks( ow lookup table of size (28-1 ) index : 0-255 ).

LookUp Table
In lookup tale, we store count of set_bit of every
number that are in a range (0-255)
LookupTable[0] = 0 | binary 00000000 CountSetBits 0
LookupTable[1] = 1 | binary 00000001 CountSetBits 1
LookupTable[2] = 1 | binary 00000010 CountSetBits 1
LookupTanle[3] = 2 | binary 00000011 CountSetBits 2
LookupTable[4] = 1 | binary 00000100 CountSetBits 1
and so…on upto LookupTable[255].                

*/

#include<bits/stdc++.h>

using namespace std;
int count(int table[],int n){
    //For first 8 bit
    int res=table[n & 0xff];
    
    n=n>>8;
    //For next 8 bit
    res=res+table[n& 0xff];
    n=n>>8;
    //For next 8 bit
    res=res+table[n& 0xff];
    n=n>>8;
    //For next 8 bit
    res=res+table[n & 0xff];
    return res;
}

int main(){
    int table[256];
    table[0]=0;
    /// generate lookup table 
    for(int i=1;i<256;i++){
        table[i]=(i&1)+table[i/2];
    }
    int bit=count(table,255);
    cout<<bit;
    
    return 0;
}


/*Time Complexity : O(1)*/
