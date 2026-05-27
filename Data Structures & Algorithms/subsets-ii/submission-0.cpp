class Solution {
private:
    vector<vector<int>> ans;

    void solve(vector<int> arr,vector<int> nums,int indx){

        if(indx >=nums.size() || nums.size()==0){
            ans.push_back(arr);
            return;
        }

        vector<int> arr1(arr);
        vector<int> arr2(arr);

        // take the element 
        arr1.push_back(nums[indx]);
        solve(arr1,nums,indx+1);

        // do not take the element 
        int i = indx;
        while(i < nums.size() && nums[i] == nums[indx]){
            i++;
        }

        solve(arr2,nums,i);
        return;
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve({},nums,0);
        return ans;
    }
};
