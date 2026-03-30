class Solution {
public:

    bool are_anagrams(vector<int> arr,string &str){

        if(str.size()==0)return true;

        for(int i=0;i<str.size();i++){
            arr[str[i] - 'a'] -= 1;
        }

        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }

        return true;
        
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        int size = strs.size();
        vector<int> seen(size,0);
        int ansIndx =0;

        for(int i=0;i<size;i++){
            
            if(seen[i] != 1){
                string str = strs[i];
                ans.push_back({str});
                seen[i] = 1;
                int n = str.size();
                vector<int> arr(26,0);

                if(n!=0){
                    for(int i=0;i<n;i++){
                        arr[str[i]-'a'] += 1;
                    }
                }

                for(int j=i+1;j<size;j++){

                    if(strs[j].size() == n && are_anagrams(arr,strs[j])){
                        ans[ansIndx].push_back(strs[j]);
                        seen[j] = 1;
                    }
                }
                
                ansIndx++;
            }
        }

        return ans;
    }
};
