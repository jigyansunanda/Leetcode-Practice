class WidthComparator implements Comparator<int[]> {
    public int compare(final int[] A, final int[] B) {
        if (A[0] != B[0]) {
            return A[0] - B[0];
        } else {
            return B[1] - A[1];
        }
    }
}

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, new WidthComparator());
        // for (int[] envelope : envelopes) {
        //     System.out.print("[" + envelope[0] + ", " + envelope[1] + "]  ");
        // }
        // System.out.println();
        int[] tail = new int[envelopes.length];
        int tailSize = 0;
        for (int i = 0; i < envelopes.length; i++) {
            int currentEnvelopeHeight = envelopes[i][1];
            int index = binarySearchOnHeight(tail, tailSize, currentEnvelopeHeight);
            if (index + 1 == tailSize) {
                ++tailSize;
                tail[index + 1] = currentEnvelopeHeight;
            } else {
                tail[index + 1] = Math.min(tail[index + 1], currentEnvelopeHeight);
            }
        }
        return tailSize;
    }

    private int binarySearchOnHeight(int[] tail, int tailSize, int currentEnvelopeHeight) {
        int lo = -1, hi = tailSize;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;
            if (tail[mid] < currentEnvelopeHeight) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
}