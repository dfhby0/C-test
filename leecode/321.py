class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        n1 = len(nums1)
        n2 = len(nums2)
        temp1 = []
        temp2 = []
        result = []
        result_num = 0
        for k1 in range(k):
            temp_k1,temp_k2 = k1,k-k1
            j1,j2 = 0,0
            while(temp_k1):
                max1 = max(nums1[j1+1:n1-temp_k1+1])
                j1 = nums1.index(max1)
                temp1.append(max1)
                temp_k1-=1
            while(temp_k2):
                max2 = max(nums2[j2+1:n1-temp_k2+1])
                j1 = nums2.index(max2)
                temp2.append(max2)
                temp_k2-=1
            j1,j2 = 0,0
            temp_result_num = 0
            temp_result = []
            while(k):
                a = temp1[j1]
                b = temp2[j2]
                if(a >= b):
                    temp_result_num += a * (10**(k-1))
                    temp_result.append(a)
                    j1+=1
                else:
                    temp_result_num += b * (10**(k-1))
                    temp_result.append(b)
                    j2+=1
            if(temp_result > result):
                result_num = temp_result_num
                result = temp_result
            

[3,3,3,2,3,7,3,8,6,0,5,0,7,8,9,2,9,6,6,9,9,7,9,7,6,1,7,2,7,5,5,1]
[5,6,4,9,6,9,2,2,7,5,4,3,0,0,1,7,1,8,1,5,2,5,7,0,4,3,8,7,3,8,5,3,8,3,4,0,2,3,8,2,7,1,2,3,8,7,6,7,1,1,3,9,0,5,2,8,2,8,7,5,0,8,0,7,2,8,5,6,5,9,5,1,5,2,6,2,4,9,9,7,6,5,7,9,2,8,8,3,5,9,5,1,8,8,4,6,6,3,8,4,6,6,1,3,4,1,6,7,0,8,0,3,3,1,8,2,2,4,5,7,3,7,7,4,3,7,3,0,7,3,0,9,7,6,0,3,0,3,1,5,1,4,5,2,7,6,2,4,2,9,5,5,9,8,4,2,3,6,1,9]
160
            



            

