/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s)
{
    stack<char> pStack;
    unordered_map<char, char> p;
    p[')'] = '(';
    p[']'] = '[';
    p['}'] = '{';

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            pStack.push(s[i]);
        }
        else
        {
            if (pStack.empty())
                return false;
            char parenthesis_pop = pStack.top();

            pStack.pop();
            if (parenthesis_pop != p[s[i]])
            {

                return false;
            }
        }
    }

    if (!pStack.empty())
        return false;

    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << "Entered string is:" << s << endl;

    cout << isValid(s);
}
