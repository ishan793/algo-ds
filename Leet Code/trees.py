def num_trees(n):
	if n < 2:
		return 1
	res = [0]*(n+1)
	res[0] = 1
	res[1] = 1

	num_left = 0
	num_right = 0
	for i in range(2,n+1):
		num_left = i-1
		num_right = i - 1 - num_left
		
		while num_left > -1:
			res[i] += res[num_left]*res[num_right]
			num_left -= 1
			num_right += 1
	return res[n]
def maxSubArray(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    c_sum = 0
    max_sa = nums[0]
    i = 0
    
    n = len(nums)
    while(i<n):
        c_sum = c_sum + nums[i]
        
        max_sa = max(c_sum,max_sa)
        
        if c_sum < 0:
        
        	c_sum = 0
        
        i += 1
    return max_sa


def mySqrt(x):
    """
    :type x: int
    :rtype: int
    """
    tol = 0.001
    mi = 0
    ma = x
    mid = (mi+ma)/2
    ans = mid*mid
    
    while(abs(x-ans) > tol):
        if ans > x:
            ma = mid
        elif ans < x:
            mi = mid
        else:
            return mid
        mid = ma+(mi-ma)/2
        ans = mid*mid

    print mid-x
    return mid

# a = [1,2,5,0]
# print maxSubArray(a)
print mySqrt(2)