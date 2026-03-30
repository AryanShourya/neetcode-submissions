class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;

        // brute force approach
        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i]){
                return true;
            }
        }


        
    }
};