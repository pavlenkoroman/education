#include "is_prime.h"

static unsigned long long prime_number = 2;

unsigned long long next_prime() {

	while (!is_prime(prime_number))
	{
		prime_number++;
	}

	auto result = prime_number;
	prime_number++;

	return result;
}

void reset_prime() {
	prime_number = 2;
}