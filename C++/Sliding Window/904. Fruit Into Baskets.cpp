class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int last = -1;
        int second_last = -1;
        int last_count = 0;
        int curr_max = 0;
        int ans = 0;
        
        for(int f : tree) {
            if(f==last || f==second_last) //till now there's atmost 2 types 
                curr_max++;
            else 
                curr_max = last_count+1;  //when we have encountered the 3rd type             
                                          // so now discard the 1st type and comsider 2nd and 3rd types
            if(f==last) 
                last_count++;                        
            else{
                last_count =1;
                second_last = last;
                last = f;
            }
            ans = max(ans,curr_max);
        }
        return ans;
    }
};