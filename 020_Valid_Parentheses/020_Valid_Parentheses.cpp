/*
 *Author: Rookie118
 *Title: Valid Parentheses
 *Completion time: 2018-03-17
*/

//The first version
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        char record;
        
        if(s.length() < 2)
            return false;

        for(int i = s.length()-1; i >= 0; --i)
        {
            if(s[i] != '(' && s[i] != '[' && s[i] != '{')
                stack.push_back(s[i]);
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                if(stack.size() == 0)
                    return false;
                record = stack.back();
                stack.pop_back();
                if((s[i] == '(' && record != ')') || (s[i] == '[' && record != ']') || (s[i] == '{' && record != '}'))
                    return false;       
            }   
        }
        if(stack.size() != 0)
            return false;
        else
            return true; 
    }
};
