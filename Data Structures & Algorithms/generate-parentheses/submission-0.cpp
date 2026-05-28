class Solution {
public:
    vector<string> ans;

    void solve(string arr,int bracket,int n){
        
        if(arr.length() == 2*n){
            if(bracket == 0){
                ans.push_back(arr);
                return;
            }
            else{
                return;
            }
        }

        if(bracket < 0){
            return;
        }


        solve(arr+'(',bracket+1,n);
        solve(arr + ')',bracket-1,n);

        return;
    }


    vector<string> generateParenthesis(int n) {
        solve({},0,n);
        return ans;
    }
};
