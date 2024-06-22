class Solution {
    private HashSet<String> set;

    public List<String> wordBreak(String s, List<String> wordDict) {
        this.set = new HashSet<>(wordDict);
        List<String> words = generateValidWords(s, 0);
        return words;
    }

    private List<String> generateValidWords(String s, int index) {
        if (index == s.length()) {
            return Collections.emptyList();
        } else {
            List<String> words = new ArrayList<>();
            for (int nextIndex = index + 1; nextIndex <= s.length(); ++nextIndex) {
                String prefix = s.substring(index, nextIndex);
                if (set.contains(prefix)) {
                    String suffixString = s.substring(nextIndex);
                    List<String> suffixes = generateValidWords(suffixString, 0);
                    if (suffixes.isEmpty()) {
                        if (suffixString.isEmpty()) {
                            words.add(prefix);
                        }
                    } else {
                        for (String suffix : suffixes) {
                            words.add(prefix + " " + suffix);
                        }
                    }
                }
            }
            return words;
        }
    }
}