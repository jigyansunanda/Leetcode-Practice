class MyCalendar {
    TreeMap<Integer, Integer> treeMap;

    public MyCalendar() {
        this.treeMap = new TreeMap<>();
    }

    public boolean book(int start, int end) {
        Integer lowerBound = treeMap.floorKey(start);
        if (lowerBound != null && treeMap.get(lowerBound) > start) return false;
        Integer upperBound = treeMap.ceilingKey(start);
        if (upperBound != null && upperBound < end) return false;
        treeMap.put(start, end);
        return true;
    }
}