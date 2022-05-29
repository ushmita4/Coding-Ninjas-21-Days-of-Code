
int sieve(int n) {
    // Define a boolean vector to keep track of prime numbers.
    vector<bool> prime(n + 1, true);

    // Declare a variable to store the count of prime numbers.
    int count = 0;

    for (int num = 2; num * num <= n; num++) {
        if (prime[num] == true) {
            for (int i = num * num; i <= n; i += num) {
                prime[i] = false;
            }
        }
    }

    // If a number is a prime number, incraese the value of count by 1.
    for (int num = 2; num <= n; num++) {
        if (prime[num] == true) {
            count++;
        }
    }

    return count;
}

int findPrimePermutations(int n) {

    // Define a variable to store the count of prime numbers in the given range.
    int primeCount = sieve(n);

    long mod = 1e9 + 7;

    // Define a variable to store the number of different arrangements.
    long permutationsCount = 1;

    for (int i = 2; i <= primeCount; i++) {
        permutationsCount *= i;
        permutationsCount %= mod;
    }

    for (int i = 2; i <= n - primeCount; i++) {
        permutationsCount *= i;
        permutationsCount %= mod;
    }

    return (int)permutationsCount;
}
