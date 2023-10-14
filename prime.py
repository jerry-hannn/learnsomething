import timeit

def disasterCode():
    for i in range(2, 2500):
        uniquePrimes = prime_factors(i)
        if not uniquePrimes:
            uniquePrimes.append(i)

def prime_factors(n):
    factors = []
    d = 2
    while d * d <= n:
        if (n % d) == 0:
            factors.append(d)
            n //= d
        else:
            d += 1
    if n > 1:
        factors.append(n)
    return factors

# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0,5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")
