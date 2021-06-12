#include <string>
#include <vector>

class Solution {
public:
    std::string boldWords(std::vector<std::string>& words, std::string S) {
        
        // the mask
        std::vector<bool> mask(S.size(), false);

        for (const auto& str : words) {
            // find the occurence and update the mask
            std::size_t pos = 0;
            while ((pos = S.find(str, pos)) != std::string::npos) {
                for (int i = 0; i < str.size(); ++i) {
                    mask[pos + i] = true;
                }

                pos += 1;
            }
            
        }

        std::string result;
        bool status = 0;   // 0 means we are outside of the mask region, 1 means we are inside.
        for (int i = 0; i < mask.size(); ++i) {

            if (status == 0) {
                if (mask[i]) {
                    result += "<b>";
                    status = 1;
                }

            } else if (status == 1) {
                if (!mask[i]) {
                    result += "</b>";
                    status = 0;
                }
            }

            result += S[i];
        }

        if (status == 1) {
            result += "</b>";
        }

        return result;
    }
};
