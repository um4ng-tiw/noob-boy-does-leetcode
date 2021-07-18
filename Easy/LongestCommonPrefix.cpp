/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/
#include<iostream>
#include<vector>
using namespace std;

string solver(vector<string> input, int i, int n, string prefix)
{

    int j;
    for(j = 0; j<n-1; j++)
    {   
        if(input[j][i] == '\0' || input[j+1][i] == '\0' || input[j].empty()|| input[j+1].empty())
            return prefix;

        if(input[j][i] != input[j+1][i])
            return prefix;
    }

    prefix+=input[j][i];

    return solver(input, i+1, n, prefix);

}




string longestCPFix(vector<string> input)
{   
    int n = input.size();

    if(n==1)
        return input[0];

    string result = solver(input, 0, n, "");

    return result;


}



int main()
{
    vector<string> input;
    int n;
    cin>>n;
    for(int i =0; i<n; i++)
    {
        string s;
        cin>>s;
        input.push_back(s);
    }

    cout<<longestCPFix(input)<<endl;

}