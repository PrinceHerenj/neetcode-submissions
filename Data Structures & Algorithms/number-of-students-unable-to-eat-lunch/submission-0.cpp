class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int result = students.size();
        unordered_map<int, int> hash;
        for (auto x: students) {
            if (!hash.contains(x)) hash[x] = 0;
            hash[x]++;
        }

        for (auto x: sandwiches) {
            if (hash[x] > 0) {
                hash[x]--;
                result--;
            }
            else return result;
        }
        
        return result;
    }
};