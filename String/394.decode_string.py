class Solution:
    def helper(self,num = 1) -> str:
        ans = ""
        while self.i<self.n and self.s[self.i]!= "]":
            if self.s[self.i].isdigit():  # Recursive call
                ans += self.helper(self.get_num())

            else:       # Add specifc char
                ans+= self.s[self.i]
                self.i +=1

        if self.i < self.n:
            # Skip "]"
            self.i+=1 

        return ans*num

    def get_num(self) -> int:
        num = 0
        while self.s[self.i].isdigit():
            num = (num*10) +  int(self.s[self.i])
            self.i+=1
        # Skip '['
        self.i+=1
        return num

    def decodeString(self, s: str) -> str:        
        self.i = 0
        self.s = s
        self.n = len(s)
        return self.helper()

    # def usingStacks(self, s):
    #     if not s:
    #         return ""
    #     numStack = []
    #     charStack = []
    #     res = ""
    #     i = 0
    #     while i < len(s):
    #         if s[i].isdigit():
    #             count = 0
    #             while s[i].isdigit():
    #                 count = count * 10 + int(s[i])
    #                 i = i+1
    #             numStack.append(count)
    #         elif s[i] == '[':
    #             charStack.append(res)
    #             res = ''
    #             i=i+1
    #         elif s[i] == ']':
    #             temp = charStack.pop()
    #             c = int(numStack.pop())
    #             temp += c * res
    #             res = temp
    #             i+=1
    #         else:
    #             res+=(s[i])
    #             i = i +1
    #     return res

solution = Solution()
print(solution.decodeString("3[a]2[bc]"))
print(solution.decodeString("3[a2[c]]"))
print(solution.decodeString("2[abc]3[cd]ef"))
print(solution.decodeString("abc3[cd]xyz"))
