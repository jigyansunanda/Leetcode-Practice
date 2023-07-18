class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int studentTypeCount[2] = {0};
        for (int studentType : students) studentTypeCount[studentType]++;
        int i = 0;
        for (; i < sandwiches.size(); ++i) {
            int sandwichOnTop = sandwiches[i];
            if (studentTypeCount[sandwichOnTop] == 0) return (int) students.size() - i;
            studentTypeCount[sandwichOnTop]--;
        }
        return 0;
    }
};