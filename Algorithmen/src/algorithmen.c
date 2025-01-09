/*
 ============================================================================
 Name        : Algorithmen.c
 Author      : H.Yalman
 Version     : v0.0.1
 Copyright   : Not defined
 Description : Kryptografische Algorithmen
 ============================================================================
 */
#include "algorithmen.h"

// Schnelle Exponentiation
int64 schnelle_exponentation(int64 basis, int64 exponent, int64 mod) {
	int64 result = 1;

	basis = basis % mod;

	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result = (result * basis) % mod;
		}
		exponent = exponent / 2;
		basis = (basis * basis) % mod;
	}

	return result;
}

// Miller-Rabin-Test
bool miller_rabin_test(int64 n, int64 a) {
	if (n % a == 0)
		return false;

	int64 d = n - 1;
	int64 r = 0;

	while (d % 2 == 0) {
		d /= 2;
		r++;
	}

	int64 x = schnelle_exponentation(a, d, n);
	if (x == 1 || x == n - 1)
		return true;

	for (int i = 1; i < r; i++) {
		x = (x * x) % n;
		if (x == n - 1)
			return true;
	}

	return false;
}
bool is_prime(int64 n, int iterationen) {
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 0; i < iterationen; i++) {
		int64 a = 2 + rand() % (n - 3);
		if (!miller_rabin_test(n, a))
			return false;
	}
	return true;
}
void miller_rabin(int64 zahl, int iterationen) {
	struct timespec start, ende;
	double verbrauchte_zeit_ms;

	clock_gettime(CLOCK_MONOTONIC, &start);
	bool ergebnis = is_prime(zahl, iterationen);
	clock_gettime(CLOCK_MONOTONIC, &ende);

	verbrauchte_zeit_ms = (ende.tv_sec - start.tv_sec) * 1000.0
			+ (ende.tv_nsec - start.tv_nsec) / 1e6;

	printf("Zahl: %lld, ", zahl);
	if (ergebnis) {
		printf("ist wahrscheinlich eine Primzahl. ");
	} else {
		printf("ist keine Primzahl. ");
	}
	printf("Verbrauchte Zeit: %.10f ms\n", verbrauchte_zeit_ms);
}

// (Erweiterter) Euklidischer Algorithmus
int ggt(int64 a, int64 b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int erweiterter_ggt(int64 a, int64 b, int64 *x, int64 *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}

	int64 x_temp, y_temp;
	int ggt = erweiterter_ggt(b, a % b, &x_temp, &y_temp);

	*x = y_temp;
	*y = x_temp - (a / b) * y_temp;

	return ggt;
}
