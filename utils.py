def Gcd(m, n) -> int:
    return m if n == 0 else Gcd(n, m % n)
