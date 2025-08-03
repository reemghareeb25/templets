const int N = 1e6 + 9, oo = 1e17, MOD = 1e9+7;  
  
int f[N], inv[N], finv[N];  
void prec() {  
    f[0] = 1;  
    for (int i = 1; i < N; i++)  
        f[i] = 1LL * i * f[i - 1] % MOD;  
    inv[1] = 1;  
    for (int i = 2; i < N; i++ ) {  
        inv[i] = (-(1LL * MOD / i) * inv[MOD % i] ) % MOD;  
        inv[i] = (inv[i] + MOD) % MOD;  
    }  
    finv[0] = 1;  
    for (int i = 1; i < N; i++)  
        finv[i] = 1LL * inv[i] * finv[i - 1] % MOD;  
}  
int ncr(int n, int r) {  
    if (n < r || n < 0 || r < 0) return 0;  
    return 1LL * f[n] * finv[n - r] % MOD * finv[r] % MOD;  
}
int npr(int n, int r) {  
    if (n < r || n < 0 || r < 0)  
        return 0;  
    return 1LL * f[n] * finv[n - r] % MOD;  
}

int fastPower(int base, int pow){  
    base %= MOD;
    int res = 1;
    while(pow > 0){
        if(pow & 1) res = res * base % MOD;
        base = base * base % MOD;
        pow >>= 1;
    }
    return res;
}

------

1. **ترتيب مهم؟** → غالبًا Permutations (`nPr`)
    - لو المسألة بتتكلم عن ترتيب أو ترتيب مختلف كل مرة (زي المقاعد، الأدوار، أو السباقات).
    - Keywords: "arrange," "order matters," "sequence," "line up"
2. **ترتيب مش مهم؟** → غالبًا Combinations (`nCr`)
    - لو المسألة بتتكلم عن اختيار مجموعة من العناصر بدون ترتيب (زي اختيار فريق أو لجنة).
    - Keywords: "choose," "select," "pick," "group of"
3. **توزيع عناصر على مجموعات؟** → غالبًا Stars and Bars
    - لو في حاجة بتتوزع بين عدة خيارات (زي توزيع 10 كرات على 3 صناديق).
    - Keywords: "distribute," "partition," "ways to split"
4. **عدد الطرق لحصول شيء معين؟** → غالبًا Basic Counting Techniques
    - لو المسألة فيها أكثر من خطوة وكل خطوة ليها عدد خيارات مستقل.
    - Keywords: "how many ways," "possibilities," "different ways"

-----
## Pigeonhole Principle

The Pigeonhole Principle can be formally stated as follows:
 If n items are distributed among m containers and n > m, then at least one container must contain more than one item.