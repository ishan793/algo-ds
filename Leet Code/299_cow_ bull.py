def isTrue(arr,su):
    left = 0
    n = len(arr)
    right = n-1

    if n < 2:
        return None,"b"

    temp = 0
    while left>-1 and right<n and left<right:
        temp = arr[left] + arr[right]
        if temp > su:
            right -= 1
        elif temp < su:
            left += 1
        elif temp == su:
            print arr[left],arr[right]
            left += 1
            right -= 1
    return None,"b"

def tsum(arr):
    arr.sort()
    n = len(arr)
    if n < 3:
        return None,"b"
    print arr
    res = []
    for i in range(n):
        current = i
        left = 0
        right = n-1
        
        su = -arr[i]
        
        temp = 0
        while left>-1 and right<n and left<right:
            temp = arr[left] + arr[right]
            if temp > su:
                right -= 1
            elif temp < su:
                left += 1
            elif temp == su:
                if left != i and right != i:
                    one_ans = [arr[current],arr[left],arr[right]]
                    one_ans.sort()
                    res.append(one_ans)
                break
    for i in res:
        print i
    
a = [1,2,3,4,4,5,6,7,8]
print isTrue(a,8)
