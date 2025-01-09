/* algorithmen_test.c */

#include "algorithmen_test.h"

/* Testfälle-Implementierung für die Algorithmen. */


void test_schnelle_exponentation() {
	struct timespec start_time, end_time;
	double elapsed_time_ms;

	// Grenzwerttest 1: Sehr große Basis
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	assert(
			schnelle_exponentation(1234567890123456789, 2, 1000000007)
					== 700979034);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0
			+ (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
	printf(
			"1. Grenzwerttest: Sehr große Basis erfolgreich! Benötigte Zeit: %.10f ms\n",
			elapsed_time_ms);

	// Grenzwerttest 2: Sehr großer Exponent
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	assert(schnelle_exponentation(3, 1000000000, 1000000007) == 235939645);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0
			+ (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
	printf(
			"2. Grenzwerttest: Sehr großer Exponent erfolgreich! Benötigte Zeit: %.10f ms\n",
			elapsed_time_ms);

	// Grenzwerttest 4: Basis und Exponent sind gleich groß
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	assert(
			schnelle_exponentation(123456789, 123456789, 1000000007)
					== 907408795);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0
			+ (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
	printf(
			"3. Grenzwerttest: Basis und Exponent gleich groß erfolgreich! Benötigte Zeit: %.10f ms\n",
			elapsed_time_ms);

	// Grenzwerttest 5: Exponent ist eine Zweierpotenz
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	assert(schnelle_exponentation(2, 1048576, 1000000007) == 36221046);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0
			+ (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
	printf(
			"4. Grenzwerttest: Exponent als Zweierpotenz erfolgreich! Benötigte Zeit: %.10f ms\n",
			elapsed_time_ms);

	// Grenzwerttest 6: Kleinste Werte (Basis 1, Exponent 0, Modulo 2)
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	assert(schnelle_exponentation(1, 0, 2) == 1);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0
			+ (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
	printf(
			"5. Grenzwerttest: Kleinste Werte erfolgreich! Benötigte Zeit: %.10f ms\n",
			elapsed_time_ms);

	// Grenzwerttest 7: Maximale Werte (Maximaler Exponent und Modulo) 6,4 Fach schneller als in Java
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	assert(
			schnelle_exponentation(2, 9223372036854775807, 1000000007)
					== 529367677);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0
			+ (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
	printf(
			"6. Grenzwerttest: Maximale Werte erfolgreich! Benötigte Zeit: %.10f ms\n",
			elapsed_time_ms);
}

#define ITERATIONS 1000000
void test_ggt() {
	struct timespec start, end;

	// Testfall 1: GGT von zwei kleinen positiven Zahlen
	int a1 = 48, b1 = 18;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < ITERATIONS; i++) {
		ggt(a1, b1);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed1 = (end.tv_sec - start.tv_sec) * 1000.0
			+ (end.tv_nsec - start.tv_nsec) / 1e6;
	printf("Testfall 1: GGT(%d, %d), Zeit: %.10f ms (pro Iteration)\n", a1, b1,
			elapsed1 / ITERATIONS);

	// Testfall 2: GGT von einer großen und einer kleinen Zahl
	int a2 = 123456, b2 = 12;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < ITERATIONS; i++) {
		ggt(a2, b2);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed2 = (end.tv_sec - start.tv_sec) * 1000.0
			+ (end.tv_nsec - start.tv_nsec) / 1e6;
	printf("Testfall 2: GGT(%d, %d), Zeit: %.10f ms (pro Iteration)\n", a2, b2,
			elapsed2 / ITERATIONS);

	// Testfall 3: GGT von zwei sehr großen Zahlen
	int a3 = 987654321, b3 = 123456789;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < ITERATIONS; i++) {
		ggt(a3, b3);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed3 = (end.tv_sec - start.tv_sec) * 1000.0
			+ (end.tv_nsec - start.tv_nsec) / 1e6;
	printf("Testfall 3: GGT(%d, %d), Zeit: %.10f ms (pro Iteration)\n", a3, b3,
			elapsed3 / ITERATIONS);

	// Testfall 4: GGT mit einer Zahl als 0 (Grenzwert)
	int a4 = 0, b4 = 789;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < ITERATIONS; i++) {
		ggt(a4, b4);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed4 = (end.tv_sec - start.tv_sec) * 1000.0
			+ (end.tv_nsec - start.tv_nsec) / 1e6;
	printf("Testfall 4: GGT(%d, %d), Zeit: %.10f ms (pro Iteration)\n", a4, b4,
			elapsed4 / ITERATIONS);

	// Testfall 5: GGT mit beiden Zahlen als 0 (ungültiger Fall)
	int a5 = 0, b5 = 0;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < ITERATIONS; i++) {
		ggt(a5, b5);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed5 = (end.tv_sec - start.tv_sec) * 1000.0
			+ (end.tv_nsec - start.tv_nsec) / 1e6;
	printf("Testfall 5: GGT(%d, %d), Zeit: %.10f ms (pro Iteration)\n", a5, b5,
			elapsed5 / ITERATIONS);

	// Testfall 6: GGT von zwei extrem großen Zahlen
	int a6 = 2147483647, b6 = 2147483640;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < ITERATIONS; i++) {
		ggt(a6, b6);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed6 = (end.tv_sec - start.tv_sec) * 1000.0
			+ (end.tv_nsec - start.tv_nsec) / 1e6;
	printf("Testfall 6: GGT(%d, %d), Zeit: %.10f ms (pro Iteration)\n", a6, b6,
			elapsed6 / ITERATIONS);

	// Testfall 7: GGT von zwei großen Zahlen mit großem Abstand
	int a7 = 1000000000, b7 = 1;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < ITERATIONS; i++) {
		ggt(a7, b7);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed7 = (end.tv_sec - start.tv_sec) * 1000.0
			+ (end.tv_nsec - start.tv_nsec) / 1e6;
	printf("Testfall 7: GGT(%d, %d), Zeit: %.10f ms (pro Iteration)\n", a7, b7,
			elapsed7 / ITERATIONS);

}

void test_erweiterter_ggt() {
	struct {
		int64 a;
		int64 b;
		int64 expected_ggt;
		const char *description;
	} test_cases[] = { { 48, 18, 6, "Zwei kleine Zahlen mit GGT > 1" }, { 101,
			103, 1, "Zwei Primzahlen mit GGT = 1" }, { 0, 10, 10,
			"Eine Zahl ist 0 (b > 0)" },
			{ 10, 0, 10, "Eine Zahl ist 0 (a > 0)" }, { 0, 0, 0,
					"Beide Zahlen sind 0 (undefiniert)" }, { 2147483647,
					2147483640, 1, "Zwei große Zahlen mit GGT = 1" }, };

	printf("Teste erweiterter GGT mit Zeitmessung:\n\n");

	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		int64 x, y;
		int64 a = test_cases[i].a;
		int64 b = test_cases[i].b;
		int64 expected_ggt = test_cases[i].expected_ggt;

		struct timespec start, end;
		double elapsed_time_ms;

		printf("Testfall %d: %s\n", i + 1, test_cases[i].description);

		clock_gettime(CLOCK_MONOTONIC, &start);
		int64 ggt = erweiterter_ggt(a, b, &x, &y);
		clock_gettime(CLOCK_MONOTONIC, &end);

		elapsed_time_ms = (end.tv_sec - start.tv_sec) * 1000.0
				+ (end.tv_nsec - start.tv_nsec) / 1e6;

		printf("Eingabe: a = %lld, b = %lld\n", a, b);
		printf("Erwarteter GGT: %lld, Berechneter GGT: %lld\n", expected_ggt,
				ggt);
		if (a == 0 && b == 0) {
			printf("Ergebnis: Beide Zahlen sind 0, GGT undefiniert.\n\n");
			continue;
		}

		printf("Koeffizienten: x = %lld, y = %lld\n", x, y);
		printf("Validierung: %lld * %lld + %lld * %lld = %lld\n", a, x, b, y,
				a * x + b * y);
		printf("Verbrauchte Zeit: %.10f ms\n", elapsed_time_ms);

		if (ggt == expected_ggt && a * x + b * y == ggt) {
			printf("Ergebnis: OK\n\n");
		} else {
			printf("Ergebnis: FEHLER\n\n");
		}
	}
}

void test_miller_rabin() {
	int iterationen = 100; // Hr. Elsner wollte 100 Iterationen
	int64 testzahlen[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, // Kleine Primzahlen
				4, 6, 8, 9, 10, 12, 14, 15, 16, 18, // Kleine Nicht-Primzahlen
				1000003, 1000037, 1000039, // Große Primzahlen
				1000000, 1000002, 1000004, // Große-Nicht-Primzahlen
				0, 1, 2, 9223372036854775807ULL // 2^63-1 // Grenzwerte
				};
	int anzahl_testzahlen = sizeof(testzahlen) / sizeof(testzahlen[0]);
	for (int i = 0; i < anzahl_testzahlen; i++) {
			miller_rabin(testzahlen[i], iterationen);
	}
}

