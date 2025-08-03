ll kthRoot(ll n, ll k) // return integer kth root for n
{ 
  double root = powl((double) n, 1.0 / (double) k);
  // will have percision errors
  ll realRoot = (ll) (root - 1);
  while (1) {
    ll a = realRoot + 1, p = 1;
    // compute a^k
    for (int j = 0; j < k; j++) {
      if (p > n / a) // we exceed n, this also detect overflow
        return realRoot;
      p *= a;
    }
    ++realRoot;
  }
}

// Also can be done by binary search for accurate results
ll kthRoot(ll n, ll k) {
  ll low = 1, high = n, ans = 1;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    __int128 p = 1;
    bool overflow = false;

    // Compute mid^k safely
    for (int i = 0; i < k; i++) {
      p *= mid;
      if (p > n) {
        overflow = true;
        break;
      }
    }

    if (!overflow) {
      ans = mid;     // mid^k ≤ n, try higher
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}
