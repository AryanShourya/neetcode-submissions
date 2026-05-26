class Solution {
private: 
    vector<vector<int>> ans;

    void solve(vector<int> arr,int indx,vector<int> nums){
        if(nums.size()==0){
            ans.push_back(arr);
            return;
        }

        if(indx >= nums.size()){
            return;
        }

        vector<int> arr1(arr);
        vector<int> arr2(arr);
        vector<int> nums2(nums);

        // if we choose nums[indx]
        arr1.push_back(nums[indx]);
        nums.erase(nums.begin()+indx);
        solve(arr1,0,nums);

        // if we do not choose nums[indx]
        solve(arr2,indx+1,nums2);

        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<int> arr;
         solve(arr,0,nums);
         return ans;
    }
};
