#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define AC return 0;
//#define int long long
//#define int unsigned long long
constexpr int MOD = 998'244'353;
constexpr int MOD_P = MOD - 1;
constexpr int mod = 1e9+7;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f'3f3f3f3f;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr char dc[] = {'U', 'D', 'L', 'R'};

const double PI = acos(-1.0);
const int MAXN = 1'000'005;

struct Card {
    int rank;
    int suit;
    int id;
};

using Score = array<int, 6>;

int getRank(char ch) {
    if (ch >= '2' && ch <= '9') return ch - '0';
    if (ch == 'T') return 10;
    if (ch == 'J') return 11;
    if (ch == 'Q') return 12;
    if (ch == 'K') return 13;
    if (ch == 'A') return 14;
    return -1;
}

int getSuit(char ch) {
    if (ch == 'C') return 0;
    if (ch == 'D') return 1;
    if (ch == 'H') return 2;
    return 3; // 'S'
}

Card parseCard(const string& s) {
    int rank = getRank(s[0]);
    int suit = getSuit(s[1]);
    int id = (rank - 2) * 4 + suit;
    return {rank, suit, id};
}

Score evaluateHand(const array<Card, 5>& cards) {
    array<int, 15> rankCount{};
    array<int, 4> suitCount{};
    vector<int> ranks;
    ranks.reserve(5);
    for (const Card& card : cards) {
        rankCount[card.rank] ++;
        suitCount[card.suit] ++;
        ranks.push_back(card.rank);
    }
    sort(ranks.begin(), ranks.end(), greater<int>());
    bool isFlush = false;
    for (int suit = 0; suit < 4; suit ++) {
        if (suitCount[suit] == 5) isFlush = true;
    }
    vector<int> uniqueRanks = ranks;
    uniqueRanks.erase(
        unique(uniqueRanks.begin(), uniqueRanks.end()), 
        uniqueRanks.end()
    );
    int straightHigh = -1;
    if (uniqueRanks.size() == 5) {
        if (uniqueRanks[0] == 14 &&
            uniqueRanks[1] == 5 &&
            uniqueRanks[2] == 4 &&
            uniqueRanks[3] == 3 &&
            uniqueRanks[4] == 2
        ) straightHigh = 5; else {
            bool consecutive = true;
            rep(i, 1, 5) {
                if (uniqueRanks[i] != uniqueRanks[i - 1] - 1)
                    consecutive = false;
            }
            if (consecutive) straightHigh = uniqueRanks[0];
        }
    }
    bool isStraight = (straightHigh != -1);
    int fourRank = -1;
    int tripleRank = -1;
    vector<int> pairRanks;
    vector<int> singleRanks;
    rrep(rank, 14, 2) {
        if (rankCount[rank] == 4) fourRank = rank;
        else if (rankCount[rank] == 3) tripleRank = rank;
        else if (rankCount[rank] == 2) pairRanks.push_back(rank);
        else if (rankCount[rank] == 1) singleRanks.push_back(rank);
    }
    Score score{};
    if (isFlush && isStraight && straightHigh == 14) {
        score[0] = 9;
        return score;
    }
    if (isFlush && isStraight) {
        score[0] = 8;
        score[1] = straightHigh;
        return score;
    }
    if (fourRank != -1) {
        score[0] = 7;
        score[1] = fourRank;
        score[2] = singleRanks[0];
        return score;
    }
    if (tripleRank != -1 && !pairRanks.empty()) {
        score[0] = 6;
        score[1] = tripleRank;
        score[2] = pairRanks[0];
        return score;
    }
    if (isFlush) {
        score[0] = 5;
        rep(i, 0, 5) score[i + 1] = ranks[i];
        return score;
    }
    if (isStraight) {
        score[0] = 4;
        score[1] = straightHigh;
        return score;
    }
    if (tripleRank != -1) {
        score[0] = 3;
        score[1] = tripleRank;
        score[2] = singleRanks[0];
        score[3] = singleRanks[1];
        return score;
    }
    if (pairRanks.size() == 2) {
        score[0] = 2;
        score[1] = pairRanks[0];
        score[2] = pairRanks[1];
        score[3] = singleRanks[0];
        return score;
    }
    if (pairRanks.size() == 1) {
        score[0] = 1;
        score[1] = pairRanks[0];
        rep(i, 0, 3) score[i + 2] = singleRanks[i];
        return score;
    }
    score[0] = 0;
    rep(i, 0, 5) score[i + 1] = ranks[i];
    return score;
}

array<Card, 52> deck;
void init() {
    rep1(rank, 2, 14) rep(suit, 0, 4) {
        int id = (rank - 2) * 4 + suit;
        deck[id] = {rank, suit, id};
    }
}

void solve() {
    array<Card, 4> yourFaceUp;
    array<Card, 4> pierreFaceUp;
    array<bool, 52> used{};
    string s;
    rep(i, 0, 4) {
        cin >> s;
        yourFaceUp[i] = parseCard(s);
        used[yourFaceUp[i].id] = true;
    }
    rep(i, 0, 4) {
        cin >> s;
        pierreFaceUp[i] = parseCard(s);
        used[pierreFaceUp[i].id] = true;
    }
    vector<int> candidates;
    candidates.reserve(44);
    rep(id, 0, 52) if (!used[id]) candidates.push_back(id);
    array<Score, 52> yourValue;
    array<Score, 52> pierreValue;
    for (int id : candidates) {
        array<Card, 5> yourHand;
        array<Card, 5> pierreHand;
        rep(i, 0, 4) {
            yourHand[i] = yourFaceUp[i];
            pierreHand[i] = pierreFaceUp[i];
        }
        yourHand[4] = deck[id];
        pierreHand[4] = deck[id];
        yourValue[id] = evaluateHand(yourHand);
        pierreValue[id] = evaluateHand(pierreHand);
    }
    bool youCanForceWin = true;
    bool pierreCanForceWin = false;
    for (int pierreId : candidates) {
        bool youHaveWinningReply = false;
        bool pierreWinsAgainstEveryReply = true;
        for (int yourId : candidates) {
            if (yourId == pierreId) continue;
            if (yourValue[yourId] > pierreValue[pierreId]) 
                youHaveWinningReply = true;
            if (!(pierreValue[pierreId] > yourValue[yourId]))
                pierreWinsAgainstEveryReply = false;
        }
        if (!youHaveWinningReply) youCanForceWin = false;
        if (pierreWinsAgainstEveryReply) pierreCanForceWin = true;
    }
    if (youCanForceWin) cout << "WoYaoYanPai";
    else if (pierreCanForceWin) cout << "GeiWoCaPiXie";
    else cout << "PaiMeiYouWenTi";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    cout << fixed << setprecision(15);
    while (T--) {
        solve();
        if (T) {
            cout << '\n';
        }
    }
    AC
}
