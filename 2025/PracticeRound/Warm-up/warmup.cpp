#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

void solve(int test) {
    int N;
    
    std::cin >> N;
    std::vector<int> A(N);
    std::vector<std::array<int, 2>> B(N);
    std::vector<int> idx(N + 1, -1);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        idx[A[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> B[i][0];
        B[i][1] = i;
    }

    for (int i = 0; i < N; i++) {
        if (B[i][0] < A[i] || idx[B[i][0]] == -1) {
            std::cout << "Case #" << test << ": -1\n";
            return;
        }
    }

    std::vector<std::array<int, 2>> res;
    std::sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        int j = B[i][1];
        if (A[j] == B[i][0]) continue;
        res.push_back({j, idx[B[i][0]]});
    }

    std::cout << "Case #" << test << ": " << res.size() << '\n';
    for (auto [i, j] : res) std::cout << i + 1 << ' ' << j + 1 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

freopen("warm_up_input.txt","r",stdin);
    freopen("warm_up_output.txt","w",stdout);

    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(i);

    return 0;
}
