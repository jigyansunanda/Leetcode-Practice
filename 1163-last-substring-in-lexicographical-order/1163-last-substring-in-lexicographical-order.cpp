class Solution {
public:
// We use "j" to find a better starting index. If any is found, we use it to update "i"

// 1."i" is the starting index of the first substring
// 2."j" is the staring index of the second substring
// 3."k" is related to substring.length() (eg. "k" is substring.length()-1)

// Case 1 (s[i+k]==s[j+k]):
// -> If s.substr(i,k+1)==s.substr(j,k+1), we keep increasing k.
// Case 2 (s[i+k]<s[j+k]):
// -> If the second substring is larger, we update i with max(i+k+1,j). 
//Since we can skip already matched things (The final answer is s.substr(i))
// Case 3 (s[i+k]>s[j+k]):
// -> If the second substring is smaller, we just change the starting index of the second string to j+k+1. 
//Because s[j]~s[j+k] must be less than s[i], otherwise "i" will be updated by "j". So the next possible candidate is "j+k+1".

    string lastSubstring(string s) {
        int n=s.length(),i=0,j=1,k=0;
        while(j+k<n)
        {
            if(s[i+k]==s[j+k]) k++; 
            else if(s[i+k]<s[j+k]) i=max(i+k+1,j),j=i+1,k=0;
            else j+=k+1,k=0;
        }
        return s.substr(i);
    }
};