class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        def find1(a,b,m):
            for i in range(a,b - 1):
                if (i - 1) > 0:
                    if nums[i] == nums[i - 1]:continue 
                for j in range(i + 1,b):
                    if (j + 1)<n:
                        if nums[j] == nums[j + 1]:continue
                    #print(((i,j,m),(nums[i],nums[j],nums[m])))
                    if nums[i] + nums[j] + nums[m] == 0:
                        if nums[i] < nums[m]:
                            k.append([nums[i],nums[j],nums[m]])
                        else:
                            k.append([nums[m],nums[i],nums[j]])
        
        def find2(m):
            for i in range(m):
                if (i - 1) > 0:
                    if nums[i] == nums[i - 1]:continue 
                for j in range(m + 1,n):
                    if (j + 1)<n:
                        if nums[j] == nums[j + 1]:continue
                    #print(1,((i,j,m),(nums[i],nums[j],nums[m])))
                    if nums[i] + nums[j] == 0:
                        k.append([nums[i],nums[m],nums[j]])

        nums = sorted(nums)
        flag = 1

        #print(nums)
        
        k = []
        
        for i in range(len(nums)):
            n = len(nums)
            if i >= n:break
            if nums[i] == 0:
                if i + 3<n:
                    if nums[i] == 0 and nums[i + 1] == 0 and nums[i + 2]==0 and nums[i + 3]==0:
                        k.append([0,0,0]) 
                        for i in range(n):
                            if 0 not in nums:break
                            nums.remove(0)
                        flag = 0
                        break
                for j in range(i + 1,n):
                    find1(0,i,j)
                for j in range(0,i):
                    find1(i+1,n,j)
                if flag:find2(i)
            elif (nums[i] > 0 and nums[i-1] < 0):
                for j in range(i+1,n):
                    find1(0,i,j)
                for j in range(0,i):
                    find1(i,n,j)

        return k
        

