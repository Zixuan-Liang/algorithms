#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Meeting {

    vector<string> participants;
    unordered_map<string, string> assignments;

public:

    Meeting(vector<string> persons, vector<string> jobs) : participants(persons) {
        for (int i = 0; i < jobs.size(); i++) {
            assignments[persons[i]] = jobs[i];
        }
        // Do something
    }

    string getAssignment(string personName) {
        if (assignments.find(personName) != assignments.end()) {
            return assignments[personName];
        }
        // Else throw key error
    }

};