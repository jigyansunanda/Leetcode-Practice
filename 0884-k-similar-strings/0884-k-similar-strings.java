class Solution {
    public int kSimilarity(String s, String t) {
        if (s.equals(t)) return 0;
        Queue<String> queue = new LinkedList<>();
        HashSet<String> set = new HashSet<>();
        int minK = 0;
        queue.add(s);
        while (!queue.isEmpty()) {
            int size = queue.size();
            minK++;
            while (size-- > 0) {
                String curr = queue.poll();
                int index = 0;
                while (curr.charAt(index) == t.charAt(index)) ++index;
                for (int nextIndex = index + 1; nextIndex < t.length(); ++nextIndex) {
                    if (curr.charAt(nextIndex) == t.charAt(nextIndex) || curr.charAt(nextIndex) != t.charAt(index)) continue;
                    String afterSwap = swap(curr, index, nextIndex);
                    if (afterSwap.equals(t)) return minK;
                    if (!set.contains(afterSwap)) {
                        set.add(afterSwap);
                        queue.add(afterSwap);
                    }
                }
            }
        }
        return minK;
    }

    private String swap(String s, int i, int j) {
        char[] ca = s.toCharArray();
        char temp = ca[i];
        ca[i] = ca[j];
        ca[j] = temp;
        return new String(ca);
    }
}