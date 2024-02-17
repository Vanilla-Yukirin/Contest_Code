def gcd(a, b):
while b:
	a, b = b, a % b
	return a
	
	def lcm(a, b):
	"""计算 a 和 b 的最小公倍数。"""
	return a * b // gcd(a, b)
	
	def count_divisibles(x, n, m, lcm_nm):
	"""计算小于等于 x 的数中，只能被 n 或 m 整除的数的数量。"""
	return x // n + x // m - 2 * (x // lcm_nm)
	
	def find_kth_number(n, m, k):
	"""找出第 K 个只能被 N 或 M 中的一个整除的最小正整数。"""
	lcm_nm = lcm(n, m)  # 计算 N 和 M 的最小公倍数
	low, high = 1, k * max(n, m)  # 设置上界
	
	while low < high:
		mid = (low + high) // 2
		if count_divisibles(mid, n, m, lcm_nm) < k:
			low = mid + 1
			else:
				high = mid
				
				return low
				
# 使用 input() 接收一行输入，并用 split() 分割字符串
				inputs = input().split()
				
# 将分割后的字符串列表转换为整数
				N, M, K = map(int, inputs)
# 调用函数并打印结果
				result = find_kth_number(N, M, K)
				print(f"{result}")

