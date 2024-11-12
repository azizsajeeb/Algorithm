// C++ program to compute exponential value using (2^k)
// -ary method.
#include<bits/stdc++.h>
using namespace std;

#define N 1000000007L; // prime modulo value

long exponentiation(long base, long exp)
{
	long t = 1L;
	while (exp > 0) 
	{

		// for cases where exponent
		// is not an even value
		if (exp % 2 != 0)
			t = (t * base) % N;/*this line can be written as
            t=((t%n) * (base%n))%n */

		base = (base * base) % N;
		exp /= 2;
	}
	return t % N;
}

// Driver code
int main()
{
	long base = 5;
	long exp = 100000;

	long modulo = exponentiation(base, exp);
	cout << (modulo);
	return 0;
}

// This code is contributed by Rajput-Ji
