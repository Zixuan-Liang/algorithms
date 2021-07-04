class Solution:
    def catMouseGame(self, graph):
        n = len(graph)
        # search(step,cat,mouse) 表示步数=step，猫到达位置cat，鼠到达位置mouse的情况下最终的胜负情况
        @lru_cache(None)
        def search(step, mouse, cat):
            # mouse到达洞最多需要n步(初始step=1) 说明mouse走n步还没达洞口 且cat也没抓住mouse
            if step==2*(n+1): return 0
            # cat抓住mouse
            if cat==mouse: return 2
            # mouse入洞
            if mouse==0: return 1
            # 奇数步：mouse走
            if step%2==1:
                # 对mouse最优的策略: 先看是否能mouse赢 再看是否能平 如果都不行则cat赢
                if any(search(step+1, mouse1, cat)==1 for mouse1 in graph[mouse]):
                    return 1
                if any(search(step+1, mouse1, cat)==0 for mouse1 in graph[mouse]):
                    return 0
                return 2
            # 偶数步: cat走
            if step%2==0:
                # 对cat最优的策略: 先看是否能cat赢 再看是否能平 如果都不行则mouse赢
                if any(search(step+1, mouse, cat1)==2 for cat1 in graph[cat] if cat1!=0):
                    return 2
                if any(search(step+1, mouse, cat1)==0 for cat1 in graph[cat] if cat1!=0):
                    return 0
                return 1
        return search(1, 1, 2)