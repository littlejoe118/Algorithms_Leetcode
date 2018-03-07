//Author: Rookie118
//Title: Longest Substring Without Repeating Characters
//Completion time: 2018-03-07

/*************The first version*************/
class Solution {
public:
    int reverse(int x) {
        vector<int> reverse;
        int count;  //记录乘10次数
        long long temp;
        bool flag_zero = true;  //一位数字为0标记
        bool flag_neg = false;  //负数标记
        long long result = 0; 
        
        if(x < 0)  //x正数化，负数标记置为true
        {
            x = -x;
            flag_neg = true;
        }
        else if (x == 0)  //直接返回x
        {
            return x; 
        }
        
        while(x != 0)
        {
            if(x % 10 == 0 && flag_zero)  
            {}
            else 
            {
                flag_zero = false;  //直到x的余数第一次不为0，零数标记置为false
                reverse.push_back(x % 10);  
            }
            x = x / 10; 
        }
        for(int i = 0; i < reverse.size(); ++i)
        {
            temp = reverse[i];  //存储每一位数字
            count = reverse.size() - i - 1;  
            while(count)
            {
                temp = temp * 10;
                --count;
            }
            result = result + temp;
        }
        if(flag_neg)  //如果为负数，则结果负数化
            result = -result;
        if(result > INT_MIN && result < INT_MAX)  //判断是否在int类型数值范围内
            return (int)result;
        else
            return 0；    
    }
};
