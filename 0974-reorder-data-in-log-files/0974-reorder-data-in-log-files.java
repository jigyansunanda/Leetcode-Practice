class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (log1, log2) -> {
            String[] log1Split = log1.split(" ", 2);
            String[] log2Split = log2.split(" ", 2);

            boolean isDigit1 = Character.isDigit(log1Split[1].charAt(0));
            boolean isDigit2 = Character.isDigit(log2Split[1].charAt(0));
            if (isDigit1 && isDigit2) {
                return 0;
            } else if (isDigit1 && !isDigit2) {
                return 1;
            } else if (!isDigit1 && isDigit2) {
                return -1;
            } else {
                int comp = log1Split[1].compareTo(log2Split[1]);
                if (comp == 0)
                    return log1Split[0].compareTo(log2Split[0]);
                else
                    return comp;
            }
        });

        return logs;
    }
}