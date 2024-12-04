class Solution {
public:
    int firstUniqChar(string s) {
        // 定义频率数组，记录每个字符的频率
        int freq[26] = {0};
        // 从头到尾遍历字符串，统计字符频率
        for(int i = 0; i< s.size(); i++){
            freq[s[i]-'a']++;
        }
        // 从字符串的第一个字符开始，查看字符频率
        // 如果字符频率为1，则返回字符所在索引
        for(int i = 0; i< s.size(); i++){
            if(freq[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
