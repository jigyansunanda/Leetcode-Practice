class Solution {
    private HashSet<String> dictionary;

    public List<String> wordBreak(String s, List<String> wordDict) {
        this.dictionary = new HashSet<>(wordDict);
        return generateValidWords(s, 0);
    }

    private List<String> generateValidWords(String s, int startIndex) {
        List<String> result = new ArrayList<>();
        if (startIndex == s.length()) {
            return result;
        } else {
            for (int endIndex = startIndex + 1; endIndex <= s.length(); ++endIndex) {
                String prefix = s.substring(startIndex, endIndex);
                if (dictionary.contains(prefix)) {
                    String remainingString = s.substring(endIndex);
                    List<String> suffixes = generateValidWords(remainingString, 0);
                    if (suffixes.isEmpty()) {
                        if (remainingString.length() == 0) result.add(prefix);
                    } else {
                        for (String suffix : suffixes) {
                            result.add(prefix + " " + suffix);
                        }
                    }
                }
            }
            return result;
        }
    }
}