class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        def wordsEndingIn(i):
            if i == len(s):
                return [""]
            ans = []
            for j in range(i+1, len(s)+1):
                if s[i:j] in wordDict:
                    for tail in wordsEndingIn(j):
                        if tail != '':
                            ans.append(s[i:j] + " " + tail) 
                        else:
                            ans.append(s[i:j])
            return ans
        return wordsEndingIn(0)