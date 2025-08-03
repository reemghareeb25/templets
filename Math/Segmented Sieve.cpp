/*
  Usage: 
  - Call segmentedSieve(L, R) to get a boolean vector isPrime[] indicating which numbers in [L, R] are prime.
  - isPrime[i] == true means (L + i) is a prime number.
  - Works efficiently for large ranges where R can be up to 1e12 but R - L <= 1e6.
  - Useful in problems requiring primes in a specific interval.

  Ex:
   ll L = 10, R = 30;
  vector<char> isPrime = segmentedSieve(L, R);

  for (int i = 0; i <= R - L; ++i) {
    if (isPrime[i]) {
      cout << L + i << " ";
    }
  }
  // Output: 11 13 17 19 23 29
  
*/
vector<char> segmentedSieve(ll L, ll R) {
  // generate all primes up to sqrt(R)
  ll lim = sqrt(R);
  vector<char> mark(lim + 1, false);
  vector<ll> primes;
  for (ll i = 2; i <= lim; ++i) {
    if (!mark[i]) {
      primes.emplace_back(i);
      for (ll j = i * i; j <= lim; j += i)
        mark[j] = true;
    }
  }

  vector<char> isPrime(R - L + 1, true);
  for (ll i: primes)
    for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
      isPrime[j - L] = false;
  if (L == 1)
    isPrime[0] = false;
  return isPrime;
}
