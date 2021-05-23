# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

def generateParenthesis(n, open=0):
    if n > 0 and 0 <= open:
        return ['(' + p for p in generateParenthesis(n-1, open+1)] + \
               [')' + p for p in generateParenthesis(n, open-1)]
    return [')' * open] * (not n)

print generateParenthesis(3)