class Solution:
    # def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
    #     while sx < tx and sy < ty:
    #         tx, ty = tx % ty, ty % tx
    #     return sx == tx and sy <= ty and (ty - sy) % sx == 0 or \
    #            sy == ty and sx <= tx and (tx - sx) % sy == 0
    
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool: 
        while tx >= sx and ty >= sy:
            if tx == ty: # 相等了不能再进行取余了，直接break看看是不是和初始相等即可
                break
            elif tx > ty: # tx大，减tx
                if ty > sy:
                    tx %= ty
                else:
                    return (tx - sx) % sy == 0 # 此时ty == sy了，到边界了，不可以减了，只需要看tx和边界的差值能不能整除sy了
            else:
                if tx > sx:
                    ty %= tx
                else:
                    return (ty - sy) % sx == 0
        return tx == sx and ty == sy # 上面搞完没return，看看是不是和初始相等即可