//Author: Rookie118
//Title: Roman to Integer
//Completion time: 2018-03-09

/*************The first version*************/
class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0)
            return 0;
        
        int sum = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case 'I':
                    if(s[i + 1] == 'V' || s[i + 1] == 'X')
                        sum -= 1;
                    else
                        sum += 1;
                    break;
                case 'X':
                    if(s[i + 1] == 'L' || s[i + 1] == 'C')
                        sum -= 10;
                    else
                        sum += 10;
                    break;
                case 'C':
                    if(s[i + 1] == 'D' || s[i + 1] == 'M')
                        sum -= 100;
                    else
                        sum += 100;
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;      
            }
        }
        return sum;
    }
};
