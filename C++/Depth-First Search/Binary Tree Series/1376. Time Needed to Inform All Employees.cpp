struct Employee {
    int id;
    int time;
    vector<Employee*> subordinates;
    Employee(int x, int y): id(x), time(y), subordinates({}) {}
};

class Solution {
public:
    
    int helper(Employee* head) {
        if (head->subordinates.empty()) {
            return 0;
        }
        else {
            int maxTime = 0;
            for (auto& s : head->subordinates) {
                maxTime = max(maxTime, helper(s));
            }
            return maxTime + head->time;
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<Employee*> employees;
        for (int i = 0; i < n; i++) {
            Employee* employee = new Employee(i, informTime[i]);
            employees.push_back(employee);
        }
        for (int i = 0; i < n; i++) {
            int m = manager[i];
            if (m != -1) employees[m]->subordinates.push_back(employees[i]);
        }
        return helper(employees[headID]);
    }
};