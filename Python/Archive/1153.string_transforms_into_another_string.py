class Solution:
    def canConvert(self, str1, str2):
        # 两字符串相等，可以转化
        if str1 == str2: return True
        # 字符串2包含26个字母，不能转化
        if len(set(str2)) == 26: return False
        # 记录每个字母在字符串1出现的最后一个位置
        lastAppear = [-1 for _ in range(26)]
        for i in range(len(str1)):
            letter = ord(str1[i]) - ord('a')
            if lastAppear[letter]!=-1 and str2[lastAppear[letter]]!=str2[i]:
                return False
            lastAppear[letter] = i
        return True