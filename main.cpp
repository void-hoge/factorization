#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		std::cerr << "invalid arguments" << '\n';
		std::abort();
	}else {
		long long n = std::atoll(argv[1]);
		std::cout << n << '\n';
		for (long long i = 2; i*i <= n;) {
			if (n%i == 0) {
				std::cout << i << ' ';
				n /= i;
			}else {
				i++;
			}
		}
		std::cout << n << '\n';
	}
	return 0;
}
