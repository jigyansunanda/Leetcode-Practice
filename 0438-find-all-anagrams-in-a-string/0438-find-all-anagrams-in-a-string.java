class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        if (p.length() > s.length()) return ans;
        int[] pCount = new int[26];
        for (int i = 0; i < p.length(); ++i) {
            pCount[p.charAt(i) - 'a']++;
        }
        int[] sCount = new int[26];
        for (int startIndex = 0; startIndex + p.length() - 1 < s.length(); ++startIndex) {
            int endIndex = startIndex + p.length() - 1;
            if (startIndex == 0) {
                for (int j = startIndex; j <= endIndex; ++j) {
                    sCount[s.charAt(j) - 'a']++;
                }
            } else {
                sCount[s.charAt(endIndex) - 'a']++;
                sCount[s.charAt(startIndex - 1) - 'a']--;
            }
            if (Arrays.equals(sCount, pCount)) ans.add(startIndex);
        }
        return ans;
    }
}