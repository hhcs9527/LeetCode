class Solution:
    def longestWPI(self, hours) -> int:
        new_h,check,maxinterval = [1] * len(hours), {}, 0
        for i in range(len(hours)):
            if i == 0: 
                new_h[i] = -1 if hours[i] <= 8 else 1 
            else:
                if hours[i] <= 8:
                    new_h[i] = new_h[i-1] - 1
                else:
                    new_h[i] = new_h[i-1] + 1
            if new_h[i] <= 0:
                # check 是否有此key? 
                check.setdefault(new_h[i], i)
                if(new_h[i]-1 in check.keys()):
                    maxinterval = max(maxinterval, i - check[new_h[i]-1])
            else:
                maxinterval = max(maxinterval, i + 1)
        print(maxinterval)
        return maxinterval

a = Solution()
inputt = [9,9,6,0,6,6,9]
a.longestWPI(inputt)




