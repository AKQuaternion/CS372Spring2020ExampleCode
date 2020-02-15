#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::string_view;
#include <future>
using std::async;
using std::future;
#include <mutex>
using std::mutex;
using std::unique_lock;
#include <algorithm>
using std::all_of;
#include <array>
#include <numeric>
#include <tuple>
#include <utility>
#include <functional>

auto magicNumber(string_view word) {
  unsigned long answer = 0;
  for (auto ii = 0; ii < 20000; ++ii)
    answer += ii % word[ii % word.length()];
  return answer;
}

void checkAWord(string_view word) {
  if (magicNumber(word) % 1000 == 0) {
    cout << word << " " << magicNumber(word) << endl;
  }
}

template <typename Iter> void checkSomeWords(Iter first, Iter last) {
  for (Iter i = first; i != last; ++i)
    checkAWord(*i);
}

void async_main() {
  auto startTime = std::chrono::steady_clock::now();

  ifstream ifile("/usr/share/dict/words");
  vector<string> dictionary;
  string word;
  while (ifile >> word)
    dictionary.push_back(word);

  //  vector<std::future<void>> results;
  //  const int numThreads = 60;
  //  for (int i = 0; i < numThreads; ++i) {
  //    auto numWords = dictionary.size();
  //    auto start = i / double(numThreads) * numWords + begin(dictionary);
  //    auto finish = (i + 1) / double(numThreads) * numWords +
  //    begin(dictionary);
  //
  //    results.push_back(std::async(std::launch::async,
  //                                 checkSomeWords<vector<string>::const_iterator>,
  //                                 start, finish));
  //  }
  //
  //  for (auto &f : results)
  //    f.get();

  //  std::for_each(std::execution::par,
  //  dictionary.begin(),dictionary.end(),checkAWord);
  auto endTime = std::chrono::steady_clock::now();
  auto diff = endTime - startTime;
  cout << std::chrono::duration<double>(diff).count() << "s" << endl;
}

class Foo {
public:
  Foo(int x) : _x(x)
  {}

  [[nodiscard]] std::string operator()() {
    return "This is Foo::operator()";
  }
  [[nodiscard]] auto operator()(int i) {
    return i*_x;
  }
private:
  int _x;
};

int bar(int) {
  return 13;
}

int main() {
  Foo f{5};

  cout << f(3) << endl;

  std::function<int(int)> g = f;
  g = bar;
  g = [](int x) {return x*x;};

  auto isOdd = [](int x) {return x%2==1;};

  if (isOdd(5)) cout << "5 is odd";

  using namespace std::string_literals;
//  vector<int> v(10);
//  std::iota(v.begin(), v.end(), 1);
//  auto fac = (std::accumulate(
//      v.begin() + 1, v.end(), std::to_string(v.front()),
//      [](auto i, auto j) { return i + " " + std::to_string(j); }));
//  cout << fac << fac << endl;

  //  auto [inserted,iterToIt] = rp();
  //  cout << inserted << iterToIt;
  //  int x= foo(13);
  //  async_main();

  return 0;
}
