class Solution {
public:
    int findTheLongestSubstring(const string &str) {
        const int len = str.size();
        std::array<int,26> vovelValue = {};
        vovelValue['a'-'a'] = 1;
        vovelValue['e'-'a'] = 2;
        vovelValue['i'-'a'] = 4;
        vovelValue['o'-'a'] = 8;
        vovelValue['u'-'a'] = 16;
        
        std::array<int,32> leftmostPos;
        for(int i = 0; i < 32; i++){
            leftmostPos[i] = -1;
        }
        
        vector<int> values(len,0);
        
        int currentVal = 0;
        for(int i = 0; i < len; i++) {
            const int pos = str[i]-'a';
            currentVal ^= vovelValue[pos];
            values[i] = currentVal;
            if (leftmostPos[currentVal] == -1) {
                leftmostPos[currentVal] = i;
            }
        }

        int best = 0;
        for(int i = 0; i < len; i++) {
            const int val = values[i];
            if (!val) {
                best = i+1;
                continue;
            }
            if (leftmostPos[val] != -1) {
                if (i - leftmostPos[val] > best) {
                    best = i - leftmostPos[val];
                }
            }
        }
        
        return best;
    }
};
