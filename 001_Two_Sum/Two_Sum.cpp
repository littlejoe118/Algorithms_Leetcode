/*
 *Author: Rookie118
 *Title: Two Sum
 *Completion time: 2018-03-01
*/

//The first version
//Time complexity: O(n^2)
//Space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        if(indices.size() == 0)
            return indices;
    }
};
