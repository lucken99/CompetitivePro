/*
The precision of a floating point number defines how many significant digits it can represent without information loss. 
When outputting floating point numbers, cout has a default precision of 6 and it truncates anything after that.
*/

#include<bits/stdc++.h>
using namespace std;
  
int main()
{
  // floor() function
    double x =1.411, y =1.500, z =1.711;
    cout << floor(x) << endl;
    cout << floor(y) << endl;
    cout << floor(z) << endl;
  
    double a =-1.411, b =-1.500, c =-1.611;
    cout << floor(a) << endl;
    cout << floor(b) << endl;
    cout << floor(c) << endl;
  
  // ceil() function
    double x = 1.411, y = 1.500, z = 1.611;
    cout << ceil(x) << endl;
    cout << ceil(y) << endl;
    cout << ceil(z) << endl;
  
    double a = -1.411, b = -1.500, c = -1.611;
    cout << ceil(a) << endl;
    cout << ceil(b) << endl;
    cout << ceil(c) << endl;
  
  // trunc() function
  
    double x = 1.411, y = 1.500, z = 1.611;
    cout << trunc(x) << endl;
    cout << trunc(y) << endl;
    cout << trunc(z) <<endl;
  
    double a = -1.411, b = -1.500, c = -1.611;
    cout << trunc(a) <<endl;
    cout << trunc(b) <<endl;
    cout << trunc(c) <<endl;
  
  // round() function
  
    double x = 1.411, y = 1.500, z = 1.611;
  
    cout << round(x) << endl;
    cout << round(y) << endl;
    cout << round(z) << endl;
  
    double a = -1.411, b = -1.500, c = -1.611;
    cout << round(a) << endl;
    cout << round(b) << endl;
    cout << round(c) << endl;
  
  // setprecision() function
  
    double pi = 3.14159, npi = -3.14159;
    cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(1) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(2) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(3) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(4) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(5) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(6) << pi <<" "<<npi<<endl;
  
    return 0;
}

/*
Output:
1
1
1
-2
-2
-2
2
2
2
-1
-1
-1
1
1
1
-1
-1
-1
1
2
2
-1
-2
-2
3 -3
3.1 -3.1
3.14 -3.14
3.142 -3.142
3.1416 -3.1416
3.14159 -3.14159
3.141590 -3.141590

/*

// Source: GFG
