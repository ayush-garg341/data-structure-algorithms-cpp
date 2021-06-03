class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_dict = set();
        length = 0;
        for i in range(0, len(s)):
            count = 0
            for j in range(i, len(s)):
                if not s[j] in char_dict:
                    char_dict.add(s[j])
                    count += 1
                else:
                    break;
            if count>length:
                length = count
            char_dict.clear()

        return length
