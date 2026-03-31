class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // brute force 
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }

        auto compareValue = [](const pair<int,int>& a,const pair<int,int>& b){
            return a.second <= b.second;
        };


        vector<int> ans;
        for(int i=0;i<k;i++){
            auto max = max_element(mp.begin(),mp.end(),compareValue);
            ans.push_back(max->first);
            mp.erase(max);
        }

        return ans;
    }
};
