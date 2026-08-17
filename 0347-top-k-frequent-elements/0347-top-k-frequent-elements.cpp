class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (auto& [val, count] : freq) {
            buckets[count].push_back(val);
        }

        vector<int> result;
        for (int i = n; i >= 1 && result.size() < k; i--) {
            for (int val : buckets[i]) {
                result.push_back(val);
                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
        
    }
};