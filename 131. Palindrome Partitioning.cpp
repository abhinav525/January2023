class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v={};
        fnc(s,v,ans);
        return ans;
        
    }
    void fnc(string s ,vector<string>v,vector<vector<string>>&ans){
        if(s.size()<1){
            ans.push_back(v);
            return;
        }
        int start =0;
        for(int len=1;len<=s.size();len++){
            string x= s.substr(start,len);
            if(ispalindrome(x))
            {
                v.push_back(x);
                string y=s.substr(len,s.size()-len);
                fnc(y,v,ans);
                v.pop_back();  
            }
        }
    }
    bool ispalindrome(string x){
        string t=x;
        reverse(t.begin(),t.end());
        return x==t;
    }
};
