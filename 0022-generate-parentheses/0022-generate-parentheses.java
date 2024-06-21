class Solution {
    public List<String> generateParenthesis(int n) {
        String parenthesis = "";
        List<String> ans = new ArrayList<>();
        generateParenthesis(n, 0, parenthesis, ans);
        return ans;
    }

    private void generateParenthesis(int n, int openingBracket, String parenthesis, List<String> ans) {
        if (openingBracket == n && parenthesis.length() == 2 * n) {
            ans.add(parenthesis);
            return;
        }
        if (openingBracket < n) generateParenthesis(n, openingBracket + 1, parenthesis + "(", ans);
        int closingBracket = parenthesis.length() - openingBracket;
        if (openingBracket > closingBracket) generateParenthesis(n, openingBracket, parenthesis + ")", ans);
    }
}