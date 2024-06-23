class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> set = new HashSet<>(wordList);
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        int ladderLength = 1;
        while (!queue.isEmpty()) {
            ++ladderLength;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                char[] chars = queue.poll().toCharArray();
                for (int j = 0; j < chars.length; j++) {
                    char prev = chars[j];
                    for (char k = 'a'; k <= 'z'; ++k) {
                        chars[j] = k;
                        String nextString = new String(chars);
                        if (set.contains(nextString)) {
                            if (nextString.equals(endWord)) return ladderLength;
                            set.remove(nextString);
                            queue.add(nextString);
                        }
                    }
                    chars[j] = prev;
                }
            }
        }
        return 0;
    }
}