class Solution {
    bool updatetonext(set<char> charset, char& a, char max)
    {
        auto it(charset.upper_bound(a));
        if(it != charset.end() && *it <= max)
        {
            a = *it;
            return true;
        }
        a = *charset.begin();
        return false;
    }
public:
    string nextClosestTime(string time) {
        set<char> charset;
        
        for(int i=0;i<5;i++)
            charset.insert(time[i]);
        
        if(updatetonext(charset, time[4], '9'))
            return time;
        if(updatetonext(charset, time[3], '5'))
            return time;
        if(updatetonext(charset, time[1], (time[0] == '2')?'3':'9'))
            return time;
        
        updatetonext(charset,time[0],'2');
        
        return time;
        
        
    }
};