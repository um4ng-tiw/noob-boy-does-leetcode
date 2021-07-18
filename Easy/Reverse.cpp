/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
 

Constraints:

-231 <= x <= 231 - 1

 */


#include<iostream>
using namespace std;

int reverse(int x)
{class Solution {
public:
    
    const int N= 214748365;
    const int M= -214748365;
    int reverse(int x) {
        
         int reverse = 0;

    while(x)
    {
        int digit = x%10;        
        if(reverse >= N || reverse <= M)
            return 0;
        reverse = reverse * 10 + digit;
      
       
        x = x/10;
    }

    return reverse;
        
    }
};
}




int main()
{
    int x;
    cin>>x;
    cout<<reverse(x)<<endl;
}