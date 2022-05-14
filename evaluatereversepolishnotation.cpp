/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the length of expression.
*/

#include<stack>
#include<map>
long mod = 1000000007;

long gcdExtended(long a, long b) {

    // Base Case
    if (a == 0) {

        return b;
    }

    // To store results of recursive call
    return gcdExtended(b % a, a);
}

long power(long x, long y, long m) {

    if (y == 0) {

        return 1;
    }

    long p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    if (y % 2 == 0) {

        return p;
    }
    else {

        return (x * p) % m;
    }
}

long modInverse(long b, long m) {

    // used in extended GCD algorithm
    long g = gcdExtended(b, m);

    // Return -1 if b and m are not co-prime
    if (g != 1) {

        return -1;
    }
    // m is added to handle negative x
    return power(b, m - 2, m);
}

bool is_digits(string &str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}

int evaluateRPN(vector<string> &exp)
{
    stack<int> st;
    map<string, int> mp;
    mp["+"] = 1;
    mp["-"] = 2;
    mp["*"] = 3;
    mp["/"] = 4;
    
        for (string i : exp) {

            // If space is encountered.
            if (i == "") {

                continue;
            }

            // If a digit is encountered.
            if (is_digits(i)) {

                st.push(stoi(i));
            }

            // If an operator is encountered.
            else {

                long num1 = (long) st.top() % mod;
                st.pop();
                long num2 = (long) st.top() % mod;
                st.pop();
                switch (mp[i]) {

                case 1:

                    st.push((int) ((num2 + num1) % mod));
                    break;
                case 2:

                    st.push((int) ((num2 - num1 + mod) % mod));
                    break;
                case 3:

                    st.push((int) ((num2 * num1) % mod));
                    break;
                case 4:

                    num2 = num2 % mod;
                    long inv = modInverse(num1, mod);
                    st.push((int) ((inv * num2) % mod));
                    break;

                }
            }
        }
            return (st.top() % 1000000007);
}
