# Program to find the number of ways to divide an array 
# into three contiguous parts such that sum of each part is same.
 

def findEqualPartitionWays(a, n):
	ways = 0
	sums = sum(a)
	if sums%3 != 0:
		return 0
	sums //= 3
	suff_sum_count = [0]*n
	temp_sum = 0
	for i in range(n-1, -1, -1):
		temp_sum += a[i]
		suff_sum_count[i] = 1 if temp_sum == sums else 0

	for i in range(n-2, -1, -1):
		suff_sum_count[i] += suff_sum_count[i+1]
	temp_sum = 0

	for i in range(n-2):
		temp_sum += a[i]
		if temp_sum == sums:
			ways += suff_sum_count[i+2]
	return ways

# a = [4,5,8,4,0,2,4]
a = [1, 2, 3, 0, 3]
# a = [0, -1, 1, 0]

print(findEqualPartitionWays(a,len(a)))


