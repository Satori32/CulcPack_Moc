#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <random>

typedef std::vector<std::uintmax_t> DType;

DType Fib(std::uintmax_t N) {
	std::uintmax_t A = 1;
	std::uintmax_t B = 1;
	DType R;
	while (N>A)
	{
		R.push_back(A);
		std::uintmax_t C = A + B;
		A = B;
		B = C;
	}

	return R;
}

DType Prime(std::uintmax_t N) {
	DType R;
	R.push_back(2);
	bool F;
	for (std::uintmax_t i = 3; i <= N; i++) {
		F = true;
		for (std::size_t j = 0; j < R.size(); j++) {
			if (!(i % R[j])) {
				F = false;
				break;
			}
		}
		if (F) { 
			R.push_back(i);
		}
	}

	return R;
}
DType Fact(std::uintmax_t N) {
	DType R;
	
	std::uintmax_t S = std::sqrt(N);
	for (std::uintmax_t i = 1; i < (S+2); i++) {
		if (!(N % i)) {
			R.push_back(N / i);
			R.push_back(N / (N / i));
		}
	}

	//std::sort(R.begin(), R.end());

	return R;
}

DType PrimeDisassembly(std::uintmax_t N, const DType& P) {
	DType R;
	std::size_t i = 0;

	while (N && !(P[i] > N)) {
		if (!(N % P[i])) {
			R.push_back(P[i]);
			N -= P[i];
		}
		else {
			i++;
		}
	}
	if (N) { R.push_back(N); }

	return R;
}

DType FibDisassembly(std::uintmax_t Fib, const DType& F) {
	DType R;
	std::size_t i = F.size()-1;

	while (Fib) {
		if ((Fib > F[i])) {
			R.push_back(F[i]);
			Fib -= F[i];
		}
		else {
			if (i == 0) {
				break;
			}
			else {
				i--;
			}
		}
	}
	if (Fib) { R.push_back(Fib); }

	return R;
}

int main() {

	std::uintmax_t N = 10000;

	auto Fibo = Fib(N);
	auto Pr = Prime(N);
	auto Facter = Fact(N);

	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<std::uintmax_t> ui(0, Facter.size() - 1);
	std::uintmax_t X = mt();
	auto PD = PrimeDisassembly(Pr[50], Pr);
	auto FD = FibDisassembly(Pr[51], Fibo);

	return 0;
}