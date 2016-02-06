times=[]
for i in range(1185):
	inp = input()
	times.append(inp)

n=len(times)
mean = sum(times)/n

sdev = 0.0

for i in times:
	temp = mean - i
	if temp<0:
		temp = temp*(-1)
	sdev += temp

sdev = sdev/n
print "mean is ", mean
print "standard deviation is ", sdev
