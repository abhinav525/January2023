// at once we can do only 2 or 3 task-if num of task of given num  are >1 then we can perform it every time ,we can choose 3 max and at last we can do in 2 that is optimum.and if only 1 task is left then we will backtrack to the prev task and then decrease that task by 1.
class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;//same level task thats count will be stored here.

        }
        int mini=0;//store the num of rounds
        for(auto it:m){
            if(it.second==1) return -1;
            int cnt=0;
            while(it.second>3){
                it.second-=3, cnt++;
            
            }
            if(it.second)//backtrack ek stp peeche do aage will be ek step aage
             cnt++;
            mini+=cnt;
        }
        return mini;
    }
};
