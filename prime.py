import timeit
import math

def disasterCode():
    prime = [True] * (1000)
    prime[0] = prime[1] = False
    listPrimes = [2]

    for p in range(3, int(math.sqrt(1000)) + 1, 2):
        if prime[p]:
            for factor in range(p * p, 1000, 2 * p):
                prime[factor] = False

    for i in range(3, 1000, 2):
        if prime[i]:
            listPrimes.append(i)


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
