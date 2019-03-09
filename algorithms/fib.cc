#include <iostream>
#include <map>

int fibonacci(int num)
{
  static std::map<int, int> cache{{0, 0}, {1, 1}};

  auto found = cache.find(num);
  if (found != std::end(cache)) {
    // For debugging purposes, to check that the cache is doing something
    std::cout << "Found in cache: " << num << " -> " << found->second << '\n';
    return found->second;
  }

  int result = fibonacci(num - 1) + fibonacci(num - 2);
  cache[num] = result;
  return result;
}

int main()
{
  int num;
  std::cout << "i: ";
  // TODO: input validation
  std::cin >> num;

  int res = fibonacci(num);
  std::cout << num << "th fibonacci number: " << res << std::endl;
}