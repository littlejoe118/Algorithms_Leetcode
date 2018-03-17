/*
 *Author: Rookie118
 *Title: 3Sum
 *Completion time: 2018-03-17
*/

//The first version
//Time complexity: O(n^2)
//Space complexity: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;

        std::sort(nums.begin(), nums.end());
        if(nums.front() > 0)
            return result;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int left = i + 1;
            int right =  nums.size() - 1;
            
            while(left < right)
            {
                if(nums[left] + nums[right] < -nums[i])
                    ++left;
                else if(nums[left] + nums[right] > -nums[i])
                    --right;
                else
                {
                    vector<int> temp(3, 0);
                    temp[0] = nums[i];
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    result.push_back(temp);   
                
                    while(left < right && nums[left] == temp[1])
                        ++left;
                    while(left < right && nums[right] == temp[2])
                        --right;
                }
            }
            while(i + 1 < nums.size() && nums[i+1] == nums[i])
                ++i;
        }
        return result;   
    }
};
