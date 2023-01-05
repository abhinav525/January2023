// we have to return the maximum from every possible sliding window
// brute force approach will be--we are calculating all the subarrays and returning the maximum from each.(h-k+1) is number of subarrays TC=0(NXK)
//we can use dequeue data structure to add the new ele and remove the prev ele.
// we will store in the decreasing order in the dequeue, and top most ele will be our answer,
// we will remove the last top ele and add the ele by checking from back and will remove  all the ele samller than the new ele, and return the top most ele.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;

        vector<int> ans;
        for(int i=0;i<k;i++){
            //visiting first subarray
            while(!dq.empty() && dq.back()<nums[i])
            //it is useless to have smaller ele as uy current ele is larger than it 
            {
                dq.pop_back();
            }

            dq.push_back(nums[i]);


        }
        ans.push_back(dq.front());// we will keep the maximum ele in the sub array in deque
        for(int i=k;i<nums.size();i++){
            if(dq.front()==nums[i-k])dq.pop_front();//remove the prev largest ele of the sub array.
             while(!dq.empty() && dq.back()<nums[i])
            //it is useless to have smaller ele as uy current ele is larger than it 
            {
                dq.pop_back();
            }

            dq.push_back(nums[i]);
            ans.push_back(dq.front());

        }
        return ans;
        
    }
};
