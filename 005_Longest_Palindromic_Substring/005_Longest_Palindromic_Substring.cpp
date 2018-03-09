class Solution {
public:
    bool isPalindromic(string s, int length)
    {
        for(int i = 0; i < length / 2; ++i)
        {
            if(s[i] != s[length - i - 1])
                return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        string sub, max_str;
        int max_len = 0;
        
        if(s.size() < 2)
            return s;
        
        for(int i = 0; i < s.size(); ++i)
            for(int j = s.size() - 1; j >= i; --j)
            {
                if(s[i] == s[j])
                {
                    sub = s.substr(i, j - i + 1);
                    if(isPalindromic(sub, j - i + 1))
                    {
                        if(sub.size() == s.size())
                            return s;
                        if(max_len < j - i + 1)
                        {
                            max_len = j - i + 1;
                            max_str = sub;
                        }   
                    }
                        
                }
            }
        return max_str;
    }
};
