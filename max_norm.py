import random
import math as m
import matplotlib.pyplot as plt

def norm(x,p):
	n = len(x)
	res = 0
	for i in range(n):
		res += m.pow(x[i],p)
	res = m.pow(res,(1.0/p))
	return res

def test():
	n = 100
	x = random.sample(range(n),10)
	res = []
	for i in range(1,100):
		res.append(norm(x,i))
	print max(x)
	print res[-1]
	plt.figure()
	plt.plot(range(1,100),res)
	plt.show()
test()