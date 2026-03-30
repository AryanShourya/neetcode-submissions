class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!= t.size())return false;

        // brute force approach
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // for(int i=0;i<s.size();i++){
        //     if(s[i]!=t[i]){
        //         return false;
        //     }
        // }

        // optimal approach 

        int array[26] = {0};

        for(int i=0;i<s.size();i++){
            array[s[i]-'a'] += 1;
            array[t[i]-'a'] -= 1;
        }

        for(int count:array){
            if(count!=0){
                return false;
            }
        }
        return true;
    }
};
