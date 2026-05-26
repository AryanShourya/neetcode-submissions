class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> arr,vector<int> nums){

        if(nums.size()==0){
            ans.push_back(arr);
            return;
        }

        vector<int> arr1(arr);
        vector<int> arr2(arr);

        arr2.push_back(nums[0]);
        nums.erase(nums.begin()+0);

        solve(ans,arr1,nums);
        solve(ans,arr2,nums);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(ans,arr,nums);
        return ans;
    }
};
