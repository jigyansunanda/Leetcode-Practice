class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        for (int i=0; i<num.length(); ++i) {
            while (!st.isEmpty() && (k>0) && (st.peek() > num.charAt(i))) {
                st.pop();
                --k;
            }
            st.push(num.charAt(i));
        } 
        for (int remaining = 0; remaining < k; ++remaining) st.pop();
        String ans = "";
        while (st.isEmpty() == false) ans += st.pop();
        ans = reverse(ans);
        int z = ans.length();
        for (int i=0; i<z; ++i) {
            if (ans.charAt(i) == '0') continue;
            else return ans.substring(i, z);
        }
        return "0";
    }

    public static String reverse(String s) {
        String ans = "";
        for (int i=s.length()-1; i>=0; --i) ans += s.charAt(i);
        return ans;
    }
}