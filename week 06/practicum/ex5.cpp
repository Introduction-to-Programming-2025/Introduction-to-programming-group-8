#include <iostream>

const size_t MAX_SIZE = 1024;

size_t levenshteinDistance(const int a[], size_t n, const int b[], size_t m) {
    
    size_t dp[MAX_SIZE + 1][MAX_SIZE + 1];
    
    for (size_t i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (size_t j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            size_t cost = (a[i - 1] == b[j - 1]) ? 0 : 1;

            size_t deletion = dp[i - 1][j] + 1;
            size_t insertion = dp[i][j - 1] + 1;
            size_t substitution = dp[i - 1][j - 1] + cost;

            size_t best = deletion;
            if (insertion < best) {
                best = insertion;
            }
            if (substitution < best) {
                best = substitution;
            }

            dp[i][j] = best;
        }
    }

    return dp[n][m];
}

int main() {
    size_t n, m;
    std::cin >> n >> m;

    if (n > MAX_SIZE || m > MAX_SIZE) {
        return -1;
    }

    int a[MAX_SIZE];
    int b[MAX_SIZE];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (size_t i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    std::cout << levenshteinDistance(a, n, b, m) << std::endl;

    return 0;
}
