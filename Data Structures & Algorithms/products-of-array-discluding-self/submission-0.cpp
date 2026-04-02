class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // brute froce 
        vector<int> ans;

        vector<int> prefix_prod,suffix_prod;
        prefix_prod.push_back(1);
        suffix_prod.push_back(1);
        int pr = 1, sf = 1;

        for(int i=0,j=nums.size()-1;i<nums.size()-1 && j>0; i++,j--){
            pr *= nums[i];
            prefix_prod.push_back(pr);

            sf *= nums[j];
            suffix_prod.insert(suffix_prod.begin(),sf);
        }

        for(int i=0;i<nums.size();i++){
            ans.push_back(prefix_prod[i]*suffix_prod[i]);
        }

        return ans;
    }
};
