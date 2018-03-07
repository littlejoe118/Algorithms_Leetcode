class Solution {
public:
    void quicksort(vector<int>& nums, int left, int right)
    {
        int temp = nums[left], record;        
        int i = left, j = right;
        if(left > right)
            return;
        
        while(i != j)
        {
            while(nums[j] >= temp && i < j)
                --j;
            while(nums[i] <= temp && i < j)
                ++i;
            
            if(i < j)
            {
                record = nums[i];
                nums[i] = nums[j];
                nums[j] = record;
            }
        }
        nums[left] = nums[i];
        nums[i] = temp;
        
        quicksort(nums, left, i - 1);
        quicksort(nums, i + 1, right);
        return;
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        vector<int> nums;
        if(nums1.size() == 0 && nums2.size() == 0)
            return 0;
        else if(nums1.size() == 0)
        {
            if(nums2.size() % 2 == 0)
                median = (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0;
            else
                median = nums2[nums2.size() / 2];
            return median;
        }
        else if(nums2.size() == 0)
        {         
            if(nums1.size() % 2 == 0)
                median = (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;
            else
                median = nums1[nums1.size() / 2];
            return median;
        }
        else
        {
            nums = nums1;
            for(int i = 0; i < nums2.size(); ++i)
                nums.push_back(nums2[i]);
            
            quicksort(nums, 0, nums.size() - 1);
            
            if(nums.size() % 2 == 0)
                median = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
            else
                median = nums[nums.size() / 2];
            
            return median;    
        }  
    }
};
