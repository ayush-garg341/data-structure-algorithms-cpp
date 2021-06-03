class Solution(object):
    def lengthOfLongestSubstring(self, s):
        char_dict = {};
        length = 0;
        for i in range(0, len(s)):
            count = 0
            for j in range(i, len(s)):
                if not char_dict.has_key(s[j]):
                    char_dict[s[j]] = 1
                    count += 1
                else:
                    break;
            if count>length:
                length = count
            char_dict.clear()

        return length
