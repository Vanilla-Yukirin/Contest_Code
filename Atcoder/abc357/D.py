def qpow(a, b, p):
    """快速幂函数，计算 a^b % p"""
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % p
        b >>= 1
        a = a * a % p
    return ans

def inv(a, p):
    """模逆元，计算 a^(p-2) % p"""
    return qpow(a, p-2, p)

def main():
    N =  int(input())

    p = 998244353

    # 计算 w，w 是 N 的十进制位数
    w = len(str(N))

    # 计算 (10^(w*N) - 1) % p
    term1 = (qpow(10, w * N, p) - 1 + p) % p

    # 计算 (10^w - 1) % p
    term2 = (qpow(10, w, p) - 1 + p) % p

    # 计算 term2 的模逆元
    term2_inv = inv(term2, p)

    # 计算最终结果
    result = (term1 * term2_inv %p * N) % p

    print(result)

if __name__ == "__main__":
    main()
