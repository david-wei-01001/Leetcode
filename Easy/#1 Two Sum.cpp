class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> myMap;
        for (int i = 0; i < len; i++)
        {
            int curr = nums[i];
            int diff = target - curr;
            if (myMap.count(diff))
            {
                return {myMap[diff], i};
            }
            myMap[curr] = i;
        }
        throw;
    }
};
