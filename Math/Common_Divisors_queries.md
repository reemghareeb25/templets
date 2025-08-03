# Common_Divisors_queries
## question
- Given N, Q queries, you will be given a number K you have to find count of common divisors of N and K
- N < 1e12 , k < 1e12 , q < 5e5

## $O(Q*log(n) )$

## bad approach
- Step 1: Calculate GCD between N and K, let it be G
- Step 2: find Number of divisors of G
- Complexity per query: $O(LogN + SQRT(G))$

## good approach
- number of primes factors of number doesn't exceed log(number)
1) we obtain prime fact for N
   - ex : 1800 -> (2,3) (3,2) (5,2)
2) we use the primes of N only to prime fact K
   - ex : k = 200 -> using (2,3,5) "عددهم اخرة log(n)" 200 -> (2,3) (3,0) (5,2)
3) using the number of divisors rule the ans is ( 3+1 ) * ( 0+1) * (2+1) = 12

# Divisors / multiplier_queries
## question
- Given N, Q queries, you will be given a number K you have to find count of divisors of N that is multiple of K
- last question we got count of divisors of N that is also divisor of K
- N < 1e12 , k < 1e12 , q < 5e5

## approach
- the prime factors of K they appear in any multiple of it " the lower bound "
- the prime factors of N is " the upper bound "

