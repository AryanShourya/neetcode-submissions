class Solution {
private:
    vector<vector<int>> ans;
    void solve(int t,vector<int> arr,vector<int> nums){

        if(t==0 ){
            ans.push_back(arr);
            return;
        }

        if(nums.size()==0 || t<0){
            return;
        }

        vector<int> arr1(arr);
        vector<int> arr2(arr);

        arr1.push_back(nums[0]);
        solve(t-nums[0],arr1,nums);

        nums.erase(nums.begin()+0);

        solve(t,arr2,nums);

        return;
    }
public:
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> arr;
        solve(target,arr,nums);
        return ans;
    }

};
