# Ignoring the fact this is a horrible interview problem for a second, this is actually a fairly interesting project that tests programmatic problem solving abilities. I've always wondered how a TI-84 could compute algebraic expressions but never bothered to find out; now i know :)

# Took me a couple hours to solve it. In an actual interview I would only be able to sketch out the general structure of the solution and may code out 2~3 sub problems.

# Anyways, here are the LC Easy and Medium problems that are used to compose the entire solution:

# Merge 2 sorted list (LC easy). Used to combine two polynomial terms inside the merge_term(self, term1, term2) function.
# Sort array based on custom comparison key (LC easy). Used to rearrange the polynomial terms in the export_terms(self) function
# Splitting string into tokens based on custom rule (LC Easy). Used in the generate_tokens(s) function to encapsulate the string parsing part of the problem.
# Use a hash map to look up strings and replace them (LC Easy).
# OOD design, overloading "+", "-", and "*" operators for a class (LC Medium).
# Convert infix expression into a postfix expression using a stack (LC Medium). Used in the build_postfix(tokens) function
# Deserialize a binary tree post-order traversal (LC Medium). Used in the evaluate(postfix) function. Recursively build the binary expression tree and use the OOD class to compute the result as we go.
# Here's the code:

import re
class ExpressionNode:
    def __init__(self):
        self.terms = {}

    def set_term(self, term, coef):
        self.terms[term] = coef

    def merge_term(self, term1, term2):
        if term1 == "1":
            return term2
        if term2 == "1":
            return term1
        arr1 = term1.split("*")
        arr2 = term2.split("*")
        arr3 = []
        i, j = 0, 0
        while i < len(arr1) and j < len(arr2):
            if arr1[i] <= arr2[j]:
                arr3.append(arr1[i])
                i += 1
            else:
                arr3.append(arr2[j])
                j += 1
        if i < len(arr1):
            arr3 += arr1[i:]
        if j < len(arr2):
            arr3 += arr2[j:]
        return "*".join(arr3)

    def export_terms(self):
        arr = list(self.terms.keys())
        def reformat(term):
            if term == "1":
                return str(self.terms[term])
            return f"{self.terms[term]}*{term}"
        def cmp_key(term):
            if term == "1":
                return (0,)
            var = term.split("*")
            return (-len(var), *var)
        arr.sort(key=cmp_key)
        return [reformat(t) for t in arr]

    def clear_zeros(self):
        for term in list(self.terms.keys()):
            if self.terms[term] == 0:
                del self.terms[term]

    def __add__(self, other):
        new_node = ExpressionNode()
        for term in self.terms:
            if term in new_node.terms:
                new_node.terms[term] += self.terms[term]
            else:
                new_node.terms[term] = self.terms[term]
        for term in other.terms:
            if term in self.terms:
                new_node.terms[term] += other.terms[term]
            else:
                new_node.terms[term] = other.terms[term]

        new_node.clear_zeros()
        return new_node

    def __sub__(self, other):
        new_node = ExpressionNode()
        for term in self.terms:
            if term in new_node.terms:
                new_node.terms[term] += self.terms[term]
            else:
                new_node.terms[term] = self.terms[term]
        for term in other.terms:
            if term in self.terms:
                new_node.terms[term] -= other.terms[term]
            else:
                new_node.terms[term] = -other.terms[term]

        new_node.clear_zeros()
        return new_node

    def __mul__(self, other):
        new_node = ExpressionNode()
        for t1 in self.terms:
            for t2 in other.terms:
                t3 = self.merge_term(t1, t2)
                if t3 not in new_node.terms:
                    new_node.terms[t3] = 0
                new_node.terms[t3] += self.terms[t1] * other.terms[t2]

        new_node.clear_zeros()
        return new_node

class Solution:
    def basicCalculatorIV(self, expression: str, evalvars: List[str], evalints: List[int]) -> List[str]:

        lookup = {a: b for a, b in zip(evalvars, evalints)}
        operators = {
            "+": 0,
            "-": 0,
            "*": 1,
        }
        def get_tokens(s):
            i = 0
            for j, c in enumerate(s):
                if c == " ":
                    if i < j:
                        yield s[i:j]
                    i = j + 1
                elif c in "()+-*":
                    if i < j:
                        yield s[i:j]
                    yield c
                    i = j + 1
            if i < len(s):
                yield s[i:]

        def build_postfix(tokens):
            postfix = []
            ops = []
            modifier = 0
            for t in tokens:
                if t == "(" or t == ")":
                    modifier += (2 if t == "(" else -2)
                elif t in operators:
                    cur = modifier + operators[t]
                    while len(ops) > 0 and ops[-1][1] >= cur:
                        postfix.append( ops.pop()[0] )
                    ops.append( (t, cur) )
                else:
                    postfix.append(t)
            while len(ops) > 0:
                postfix.append( ops.pop()[0] )
            return postfix

        def evaluate(postfix):
            val = postfix.pop()
            node = ExpressionNode()
            if re.fullmatch("-?[\d]+", val):
                node.set_term("1", int(val))
            elif val not in operators:
                node.set_term(val, 1)
            else:
                right = evaluate(postfix)
                left = evaluate(postfix)
                if val == "+":
                    return left + right
                elif val == "-":
                    return left - right
                else:
                    return left * right
            return node

        tokens = list(get_tokens(expression))
        for i, token in enumerate(get_tokens(expression)):
            if token in lookup:
                tokens[i] = str(lookup[token])

        #print(tokens)
        postfix = build_postfix(tokens)
        # print(postfix)
        node = evaluate(postfix)
        node.clear_zeros()
        #print(node.terms)
        return node.export_terms()