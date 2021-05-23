# Given an absolute path for a file (Unix-style), simplify it.
#
# For example,
# path = "/home/", => "/home"
# path = "/a/./b/../../c/", => "/c"
#
# Corner Cases:
# Did you consider the case where path = "/../"?
# In this case, you should return "/".
# Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
# In this case, you should ignore redundant slashes and return "/home/foo".

def sim_path(path):
    items = path.split('/')
    stack = []
    length = len(items)
    ans = "/"
    for i in range(length):
        if items[i] == '.' or items[i] == '':
            continue
        elif items[i] != '..':
            stack.append(items[i])
        elif items[i] == '..' and not stack:
            continue
        elif items[i] == '..':
            stack.pop()
    for rest in stack:
        ans += rest + '/'
    if ans == "/":
        return ans
    return ans[:-1]

print sim_path("/home/")
print sim_path("/a/./b/../../c/")
print sim_path("/../")
print sim_path("/home//foo/")

