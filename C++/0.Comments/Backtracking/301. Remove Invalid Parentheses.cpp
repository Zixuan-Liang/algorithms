#include <string>
#include <vector>

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int leftRemove = 0,rightRemove = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                leftRemove++;
            }
            else if(s[i] == ')'){
                if(leftRemove == 0)
                    rightRemove++;
                else if(leftRemove > 0)
                    leftRemove--;
            }
        }
        unordered_set<string> temp;
        string path;
        backTrack(s,leftRemove,rightRemove,path,temp,0,0,0);
        vector<string> res(temp.begin(),temp.end());
        return res;
    }

    void backTrack(string& s,int leftRemove,int rightRemove,string& path,unordered_set<string>& temp,int leftCount,int rightCount,int idx){
        if(idx == s.size()){
            if(leftRemove == 0 && rightRemove == 0){
                temp.insert(path);
            }
            return;
        }
        //选择删除当前遍历到的字符
        if(s[idx] == '(' && leftRemove > 0){
            backTrack(s,leftRemove-1,rightRemove,path,temp,leftCount,rightCount,idx+1);
        }
        if(s[idx] == ')' && rightRemove > 0){
            backTrack(s,leftRemove,rightRemove-1,path,temp,leftCount,rightCount,idx+1);
        }
        //选择保留当前遍历到的字符
        path.push_back(s[idx]);
        //如果s[idx]是其他字母,则直接递归
        if(s[idx] != '(' && s[idx] != ')'){
            backTrack(s,leftRemove,rightRemove,path,temp,leftCount,rightCount,idx+1);
        }
        //如果s[idx]是左括号,则改变leftCount,然后递归
        else if(s[idx] == '('){
            backTrack(s,leftRemove,rightRemove,path,temp,leftCount+1,rightCount,idx+1);
        }
        //因为当左括号的数目严格小于右括号的数目时,此表达式无效,所以在添加右括号时要判断一下
        //如果是右括号,且左括号比右括号的个数多,则添加右括号的操作是有效的,改变rightCount,然后递归
        else if(rightCount < leftCount){
            backTrack(s,leftRemove,rightRemove,path,temp,leftCount,rightCount+1,idx+1);
        }
        path.pop_back();
    }
};