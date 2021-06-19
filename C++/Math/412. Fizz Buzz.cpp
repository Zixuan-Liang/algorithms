class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            bool fizz = i % 3 == 0;
            bool buzz = i % 5 == 0;
            if (fizz && buzz) {
                res.push_back("FizzBuzz");
            }
            else if (fizz) {
                res.push_back("Fizz");
            }
            else if (buzz) {
                res.push_back("Buzz");
            }
            else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};