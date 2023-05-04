class Solution {
    public static int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = gas[i] - cost[i];
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        int totalGas = 0, maxCost = 0, startIndex = 0;
        for (int i=0; i<n; ++i) {
            totalGas += arr[i];
            if (totalGas < 0) {
                startIndex = i + 1;
                maxCost += Math.abs(totalGas);
                totalGas = 0;
            }
        }
        return (totalGas >= maxCost) ? startIndex : -1;
    }
}