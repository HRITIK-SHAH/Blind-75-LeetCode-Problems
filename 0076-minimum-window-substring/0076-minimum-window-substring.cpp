class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> freq(128, 0);

        // Characters that we need
        for (char c : t) {
            freq[c]++;
        }

        int need = t.size();
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            
            if (freq[s[right]] > 0) {
                need--;
            }

            freq[s[right]]--;

            
            while (need == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    need++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};