#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <iomanip>

inline const int seqToInt(const std::string& seq) {
    int val = 0;
    for (const char& c : seq) {
        val = (val << 1) | (c == 'H' ? 1 : 0);
    }
    return val;
}

constexpr int SIMULATIONS = 10'000'000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string p1_str, p2_str;
    std::cin >> p1_str;
    p2_str = (p1_str[1] == 'H' ? "T" : "H") + p1_str.substr(0, 2);
    std::cout << "p1: " << p1_str << '\n';
    std::cout << "p2: " << p2_str << '\n';
    const int p1_int = seqToInt(p1_str);
    const int p2_int = seqToInt(p2_str);
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> coin_flip(0, 1);

    int p1_wins = 0, p2_wins = 0;

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIMULATIONS; ++i) {
        int tmp = coin_flip(rng) << 1 | coin_flip(rng);
        while (true) {
            tmp = tmp << 1 | coin_flip(rng);
            tmp = tmp & 0b111;
            if (tmp == p1_int) {p1_wins ++; break;}
            if (tmp == p2_int) {p2_wins ++; break;}
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "p1_wins: " << p1_wins << '\n';
    std::cout << "p2_wins: " << p2_wins << '\n';
    std::cout << "p1_win_rate: " << 100.0 * p1_wins / SIMULATIONS << '%' << '\n';
    std::cout << "p2_win_rate: " << 100.0 * p2_wins / SIMULATIONS << '%' << '\n';
    std::cout << "run_time: " << elapsed.count() << " seconds\n";
}