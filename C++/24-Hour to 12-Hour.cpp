#include <iostream>
#include <sstream> // stringstream

using namespace std;

// 24 to 12
string convert(string time) {

    // C++分词
    // vector<string> tokens;
    // stringstream stream(time);
    // string token;
    // while (getline(stream, token, ':')) {
    //     tokens.push_back(token);
    // }

    // size_t found = time.find(':');
    // string hour = time.substr(0, size_t);
    string hour = time.substr(0, 2);

    string suffix;
    if (hour >= "00" && hour <= "11") suffix = " AM";
    else suffix = " PM";

    if (hour == "00") hour = "12";
    else if (hour >= 13 && hour <= 23) hour = to_string(stoi(hour) - 12);

    return hour + time.substr(2) + suffix;
}

// 12 to 24
string convert(string time) {

    string hour = time.substr(0, 2);

    string suffix = time.substr(time.size()-2);
    if (suffix == "AM") hour = (hour == "12") ? "00" : hour;
    else if (suffix == "PM") hour = (hour == "12") ? "12" : to_string(stoi(hour) + 12);

    return hour + time.substr(2, time.size()-4);

}