def find_comb(st):
	if len(st) == 0:
		return [""]
	elif len(st) == 1:
		return [st]
	res = []
	count = 0
	while count < len(st):
		n_st = st[0:count] + st[count+1:]
		a = find_comb(n_st)
		# print "complete result",a
		for i in a:
			# print "current element",st[count]
			# print "element of result",i
			temp = st[count] + i
			# print "addition gives",temp
			res.append(temp)
		count += 1
	return res


def perms(n,k):
	res = []
	base = range(n)
	if n == k:
		return base
	elif n < k:
		return -else
	1:
		res = []
		first = base[0]
		with_first = []

# a = find_comb("abc")
# print a
# print len(a)
# print "-"*10
# a = find_comb("ab")
# print a
# print len(a)
# print "-"*10
# a = find_comb("abcde")
# print a
# print len(a)
