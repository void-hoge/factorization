#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <numeric>

int base_gen(const int base_prime_num, const std::vector<uint64_t>& prime, std::vector<unsigned>& result) {
	uint64_t max = 1;
	for (int i = 0; i < base_prime_num; i++) {
		max *= prime[i];
	}
	result.clear();
	for (uint64_t i = 0; i < max; i++) {
		if (std::gcd(max, i) == 1) {
			result.push_back(i);
		}
	}
	return max;
}

inline uint64_t get_divisor(const uint64_t idx, const std::vector<unsigned>& base, const unsigned base_max) {
	return (idx/base.size())*base_max + base[(idx%base.size())];
}

std::vector<unsigned> factorize(uint64_t n, const int base_prime_num) {
	const static std::vector<uint64_t> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
	if (base_prime_num > (int)prime.size()) {
		std::cerr << "base_prime_num must be no more than " << prime.size() <<  "." << '\n';
		std::abort();
	}
	std::vector<unsigned> base;
	const unsigned base_max = base_gen(base_prime_num, prime, base);

	std::vector<unsigned> result;
	for (int i = 0; i < base_prime_num; i++) {
		while (n%prime[i] == 0 && n != 0) {
			n /= prime[i];
			result.push_back(prime[i]);
		}
	}

	if (n != 1) {
		uint64_t d = get_divisor(1, base, base_max);
		for (uint64_t i = 1; d*d <= n;) {
			if (n % d == 0) {
				n /= d;
				result.push_back(d);
			}else {
				i++;
				d = get_divisor(i, base, base_max);
			}
		}
		result.push_back(n);
	}
	return result;
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		std::cerr << "invalid arguments" << '\n';
		std::abort();
	}else {
		uint64_t n = atoll(argv[1]);
		std::cout << n << '\n';
		std::vector<unsigned> hoge = factorize(n, 5);
		for (auto a: hoge) {
			std::cout << a << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
