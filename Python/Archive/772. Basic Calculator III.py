# 带括号的+-*/
# 两个栈，一个存数字，一个存运算符+优先级
# +-优先级1，*/优先级2，左括号后面的运算符优先级+10，右括号后面的运算符优先级-10（恢复正常优先级）
# 保证运算符栈的优先级是单调递增，如果有一个新的运算符的优先级小于等于栈顶，就一直出栈运算，
# 直到栈空或者栈恢复单调递增为止
# 该方案可直接用来解决224和227 (224:带括号的+-,227:不带括号的+-*/)

class Solution:

    def calculate(self, s):
        processedS = []
        for i in range(len(s)):
            if s[i] in ['+', '-'] and (i==0 or s[i-1]=='('):
                processedS.append('0')
            if s[i] != ' ':
                processedS.append(s[i])
        processedS.append('+')
        s = ''.join(processedS)

        numStack = []
        opStack = []

        priority = {'+':1, '-':1, '*':2, '/':2}
        prio = 0
        i = 0
        while i<len(s):
            if s[i] in priority:
                oper = (s[i], priority[s[i]]+prio)
                while opStack and opStack[-1][1] >= oper[1]:
                    op = opStack.pop()[0]
                    cur = 0
                    b = numStack.pop()
                    a = numStack.pop()
                    if op == '+':
                        cur = a + b 
                    elif op == '-':
                        cur = a - b
                    elif op == '*':
                        cur = a * b
                    elif op == '/':
                        cur = int(a/b)
                    numStack.append(cur)
                opStack.append(oper)
                i+=1
            elif s[i] == '(':
                prio += 10
                i+=1
            elif s[i] == ')':
                prio -= 10
                i+=1
            else:
                num = 0
                while i<len(s) and s[i].isdigit():
                    num = 10*num + int(s[i])
                    i+=1
                numStack.append(num)
        return numStack.pop()