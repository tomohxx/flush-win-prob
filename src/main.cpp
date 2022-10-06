#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <boost/container_hash/hash.hpp>

struct Hash {
  std::size_t operator()(const std::vector<int>& hand) const
  {
    return boost::hash_range(hand.begin(), hand.end());
  }
};

using Hands = std::unordered_map<std::vector<int>, std::vector<double>, Hash>;

bool iswh0(const int* h)
{
  int a = h[0], b = h[1];

  for (int i = 0; i < 7; ++i) {
    if (int r = a % 3; b >= r && h[i + 2] >= r) {
      a = b - r;
      b = h[i + 2] - r;
    }
    else return false;
  }
  return a % 3 == 0 && b % 3 == 0;
}

bool iswh2(int* h)
{
  int s = 0;

  for (int i = 0; i < 9; ++i) {
    s += i * h[i];
  }

  for (int p = s * 2 % 3; p < 9; p += 3) {
    if (h[p] >= 2) {
      h[p] -= 2;

      if (iswh0(h)) {
        h[p] += 2;
        return true;
      }
      else h[p] += 2;
    }
  }
  return false;
}

bool issp(const int* h)
{
  for (int i = 0; i < 9; ++i) {
    if (h[i] != 0 && h[i] != 2) {
      return false;
    }
  }
  return true;
}

void generate(int n, int m, std::function<void(std::vector<int>&)> func)
{
  static std::vector<int> h(9);

  if (n == 9) {
    func(h);
  }
  else {
    for (int i = std::max(0, m - 4 * (8 - n)); i <= std::min(4, m); ++i) {
      h[n] = i;
      generate(n + 1, m - i, func);
    }
  }
}

std::string print(const std::vector<int>& hand)
{
  std::string ret;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < hand[i]; ++j) {
      ret += i + '1';
    }
  }
  return ret;
}

int main()
{
  constexpr int T_MIN = 0;
  constexpr int T_MAX = 18;
  constexpr int SUM = 123;

  Hands nodes1; // 3N + 1
  Hands nodes2; // 3N + 2

  std::ofstream fout("prob.csv");

  generate(0, 14, [&nodes2](std::vector<int>& h) {
    if (issp(h.data()) || iswh2(h.data())) {
      nodes2.insert(std::make_pair(h, std::vector<double>(T_MAX + 1, 1.)));
    }
    else {
      nodes2.insert(std::make_pair(h, std::vector<double>(T_MAX + 1, 0.)));
    }
  });

  generate(0, 13, [&nodes1](std::vector<int>& h) {
    nodes1.insert(std::make_pair(h, std::vector<double>(T_MAX + 1, 0.)));
  });

  for (int t = T_MAX - 1; t >= T_MIN; --t) {
    for (auto& [hand, prob] : nodes1) {
      auto tmp = hand;

      for (int i = 0; i < 9; ++i) {
        if (tmp[i] < 4) {
          ++tmp[i];
          prob[t] += std::max(nodes2[tmp][t + 1] - prob[t + 1], 0.) * (4 - hand[i]);
          --tmp[i];
        }
      }

      prob[t] = prob[t + 1] + prob[t] / (SUM - t);
    }

    for (auto& [hand, prob] : nodes2) {
      auto tmp = hand;

      for (int i = 0; i < 9; ++i) {
        if (tmp[i] > 0) {
          --tmp[i];
          prob[t] = std::max(prob[t], nodes1[tmp][t]);
          ++tmp[i];
        }
      }
    }
  }

  for (const auto& [hand, prob] : nodes1) {
    const auto tmp = print(hand);

    for (int t = T_MIN; t <= T_MAX; ++t) {
      fout << tmp << "," << t << "," << prob[t] << "\n";
    }
  }

  return 0;
}
