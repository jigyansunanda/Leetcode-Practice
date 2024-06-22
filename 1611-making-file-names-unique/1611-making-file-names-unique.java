class Solution {
    public String[] getFolderNames(String[] names) {
        HashMap<String, Integer> map = new HashMap<>();
        int n = names.length;
        String[] ans = new String[n];
        for (int i = 0; i < n; i++) {
            ans[i] = getName(map, names[i]);
        }
        return ans;
    }

    private String getName(HashMap<String, Integer> map, String name) {
        if (map.containsKey(name)) {
            int nextCount = map.get(name) + 1;
            while (map.containsKey(getIndexedName(name, nextCount))) {
                ++nextCount;
            }
            map.put(name, nextCount);
            String newName = getIndexedName(name, nextCount);
            map.put(newName, 0);
            return newName;
        } else {
            map.put(name, 0);
            return name;
        }
    }

    private String getIndexedName(String name, int index) {
        return name + "(" + index + ")";
    }
}