from scipy.optimize import linprog

# minimize::

#         c @ x

#     such that::

#         A_ub @ x <= b_ub
#         A_eq @ x == b_eq
#         lb <= x <= ub

#     Note that by default ``lb = 0`` and ``ub = None`` unless specified with
#     ``bounds``.

# Example 1, min, s.t. >=, bound >= 0
obj = [3,-2,4]
lhs_ineq = [[-1,3,-1],[-2,-1,1],[-1,-1,-3],[0,1,-1]]
rhs_ineq = [-3,-4,-5,-2] # linprog requires constraints in form of <=, so need to reverse rhs_ineq and lhs_ineq
opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq, method="interior-point")
print(opt)

# Example 2, dual problem of example 1, max, s.t. <=, bound >= 0
obj = [-3,-4,-5,-2] # linprog returns the minimum, so need to reverse the obj to make max become min
lhs_ineq = [[1,2,1,0],[-3,1,1,-1],[1,-1,3,1]]
rhs_ineq = [3,-2,4]
opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq, method="interior-point")
print(opt)