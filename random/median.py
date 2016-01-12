import random
# def bin_search(l,val):
# 	mi = 0
# 	ma = len(l) - 1
# 	mid = int((mi + ma)/2)
# 	while l[mid] != val:
# 		if l[mid] > val:
# 			ma = mid
# 		else :
# 			mi = mid
# 		mid = int((mi + ma)/2)
# 	return mid

# def med_two(l1,l2):
# 	n1 = len(l1)
# 	n2 = len(l2)

# 	if n1 > n2:
# 		
def get_res(l1,l2):
	n = len(l1)
	m = len(l2)
	if n + m < 5:
		a = l1 + l2
		a.sort()
		return a[(n+m)/2]
	else:
		l1_mid = l1[n/2]
		l2_mid = l2[m/2]
		if l1_mid == l2_mid:
			return l1_mid
		if l1_mid < l2_mid:
			return(get_res(l1[n/2:n],l2[:m/2]))
		else:
			return(get_res(l1[:n/2],l2[m/2:m]))

a = random.sample(range(0,10),8)
b = random.sample(range(0,10),4)
a.sort()
b.sort()
print get_res(a,b)
c = a+b
c.sort()
print c[len(c)/2]