/* 
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/


#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int findNumberFromRoman(string s)
{

    unordered_map<char, int> roman;
    int converted_integer = 0;
    string roman_numeral = "IVXLCDM";
    int arr[7] = {1, 5, 10, 50, 100, 500 , 1000};

    for(int i = 0; i<7; i++)
    {   
        roman[roman_numeral[i]] = arr[i];
    }

    if(s.length() == 1)
    {
        return roman[s[0]];
    }

    int j = 0;

    while(j<s.length())
    {
        if(roman[s[j]]<roman[s[j+1]])
        {
            converted_integer = converted_integer + (roman[s[j+1]] - roman[s[j]]);
            j+=2;
        }
        else
        {
            converted_integer = converted_integer + roman[s[j]];
            j+=1;
        }
    }
  
    while(j<s.length())
    {
        if(roman[s[j-1]] > roman[s[j]])
        {

            converted_integer = converted_integer - roman[s[j]];
        }
        else
        {
            converted_integer = converted_integer + roman[s[j]];
        }
        j++;
    }

    

    return converted_integer;
   
}


//Optimized

int findRoman(string s)
{
    unordered_map<char, int> roman;
    int converted_integer = 0;
    string roman_numeral = "IVXLCDM";
    int arr[7] = {1, 5, 10, 50, 100, 500 , 1000};

    for(int i = 0; i<7; i++)
    {   
        roman[roman_numeral[i]] = arr[i];
    }
    roman['\0'] = 0;

    if(s.length() == 1)
    {
        return roman[s[0]];
    }

    int j = 0;

    for(int i = 0;i<s.length();i++)
    {

        if(roman[s[i]]<roman[s[i+1]])
        {
            converted_integer -= roman[s[i]];
        }
        else
        {
            converted_integer += roman[s[i]];
        }

    }

    

    return converted_integer;
}



int main()
{

    string s;
    cin>>s;
    cout<<findRoman(s)<<endl;
}