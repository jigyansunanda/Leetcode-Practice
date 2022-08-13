class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string & A, const string & B) {
            int space1 = A.find(' ');
            int space2 = B.find(' ');
            if (!isdigit(A[space1 + 1]) and !isdigit(B[space2 + 1])) {
                // both A and B are letter-logs
                string contentA = A.substr(space1 + 1);
                string contentB = B.substr(space2 + 1);
                if (contentA == contentB) {
                    // if both A and B have same content, then compare the identifiers
                    return (A.substr(0, space1) <= B.substr(0, space2));
                }
                // else the string with lexicographically smaller content comes first
                return (contentA <= contentB);
            } else if (!isdigit(A[space1 + 1])) {
                // because A is a letter-log and should come before B, which is a digit-log
                return true;
            } else {
                // because A is a digit-log and should come after B, which is a letter-log
                return false;
            }
        });
        return logs;
    }
};