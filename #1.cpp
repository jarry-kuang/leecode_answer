#1.cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create an hashmap(empty)
        unordered_map<int,int> hashtable;
        for(int i=0; i< nums.size();i++){
            //find it, if it is availble,check same or not same number
            auto it = hashtable.find(target-nums[i]);
            if (it != hashtable.end()){
                return{it->second,i};
                }
            //if don't find it, put data in hashtable
            hashtable[nums[i]]=i;
        }
        return{};
    }
};