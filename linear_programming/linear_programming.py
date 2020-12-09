from scipy.optimize import linprog

# minimize::
#         c @ x
#     such that::
#         A_ub @ x <= b_ub
#         A_eq @ x == b_eq
#         lb <= x <= ub
#     Note that by default ``lb = 0`` and ``ub = None`` unless specified with
#     ``bounds``.

# Example 1
# min 3x - 2y + 4z
# s.t. x - 3y + z >= 3
#       2x + y - z >= 4
#       x + y + 3z >= 5
#       -y + z >= 2
#       x,y,z >= 0
obj = [3,-2,4]
lhs_ineq = [[-1,3,-1],[-2,-1,1],[-1,-1,-3],[0,1,-1]]
rhs_ineq = [-3,-4,-5,-2] # linprog requires constraints in form of <=, so need to reverse rhs_ineq and lhs_ineq
opt_1 = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq, method="interior-point")

# Example 2, dual problem of example 1
# max 3u + 4x + 5y + 2z
# s.t. u + 2x + y <= 3
#       -3u + x + y - z <= -2
#       u - x + 3y + z <= 4
#       u,x,y,z >= 0
obj = [-3,-4,-5,-2] # linprog returns the minimum, so need to reverse the obj to make max become min
lhs_ineq = [[1,2,1,0],[-3,1,1,-1],[1,-1,3,1]]
rhs_ineq = [3,-2,4]
opt_2 = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq, method="interior-point")

print(abs(opt_1.fun - (-opt_2.fun)) < 0.000001)