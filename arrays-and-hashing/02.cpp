class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencymap;
        for (int num:nums){
            frequencymap[num]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for (const auto& pair : frequencymap){
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> result;
        for(int i = buckets.size()-1; i>=0 && result.size()<k; --i){
            for (int num : buckets[i]){
                result.push_back(num);
                if (result.size() == k){
                    break;
                }
            }
        }

        return result;
        
    }
};