/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    void helper(int& res, vector<Employee*>& employees, int id, unordered_map<int, int>& indexMap) {
        int index = indexMap[id];
        res += employees[index]->importance;
        for (int s : employees[index]->subordinates) {
            helper(res, employees, s, indexMap);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_map<int, int> indexMap;
        for (int i = 0; i < employees.size(); i++) {
            indexMap[employees[i]->id] = i;
        }
        helper(res, employees, id, indexMap);
        return res;
    }
};