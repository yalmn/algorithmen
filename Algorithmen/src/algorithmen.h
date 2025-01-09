/* algorithmen.h */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>

typedef unsigned long long int int64;

int main(int,char**);

/*
 * Algorithmen:
 * 	- Schnelle Exponentation (ITS S. 7)
 *	- Miller-Rabin-Test (100 Durchläufe) (ITS S. 8)
 *	- Euklidischer Algorithmus | Erweiterter Euklidischer Algorithmus (ITS S. 9)
 */

// Schnelle Exponentiation | Testfälle
int64 schnelle_exponentation(int64,int64,int64);

// Miller-Rabin-Test
/*
 * Benötigen:
 * 	- Schnelle Exponentation [siehe oben]
 * 	- miller_rabin_test(int64 n, int64 a)
 * 	- is_prime(int64 n, int iteration)
 * 	- miller_rabin_testfalle(int64 zahl, int iteration)
 */
bool miller_rabin_test(int64,int64);
bool is_prime(int64,int);
void miller_rabin(int64,int);

// (Erweiterter) Euklidischer Algorithmus
/*
 * 	- int ggt(int64 a, int64 b)
 * 	- int erweiterter_ggt(int a, int b, int *x, int *y) (Koeeffizieten x und y, damit die Diophantische Gleichung ax + by = ggt(a,b) erfüllt wird
 * 	- euklidischer_algorithmus_test()
 */
int ggt(int64, int64);
int erweiterter_ggt(int64,int64,int64*,int64*);



