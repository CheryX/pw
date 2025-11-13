#include <stdio.h>	// wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strstr

#define BUFSIZE 8192 // zakładamy, że linie będą krótsze niż 8kB

int main(int argc, char **argv)
{
	int ile_linii;
	char buf[BUFSIZE];

	FILE *in = argc > 2 ? fopen(argv[argc - 1], "r") : stdin;
	char *str = argc > 2 ? argv[1] : NULL;

	int mode = atoi(argv[1]);
    if (mode != 0 && mode != 1) {
        fprintf(stderr, "Błąd: Tryb musi być 0 lub 1.\n");
        return EXIT_FAILURE;
    }

	if (str == NULL) {
		fprintf(stderr, "%s: błąd: proszę podac napis do wyszukiwania\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (in == NULL) {
		fprintf(stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[2]);
		return EXIT_FAILURE;
	}

	int l = 0;
	int l2 = 0;

	while (fgets(buf, BUFSIZE, in) != NULL) {
		
		int matches;
		if (mode == 0) {
			matches = 0;
			for (int i = 2; i < argc - 1; i++) {
				if (strstr(buf, argv[i]) != NULL) {
					matches = 1;
					break;
				}
			}
		} else {
			matches = 1;
            for (int i = 2; i < argc - 1; i++) {
                if (strstr(buf, argv[i]) == NULL) {
                    matches = 0;
                    break;
                }
            }
		}
			
		l2++;
		if (matches) {
			printf("%i: %s", l2, buf);
			l++;
		}

	}
	printf("%i linijek\n", l);

	return EXIT_SUCCESS;
}

// # let file:
// ala ma kota
// ma psa
// ola kota ma

// > ./a.out [0] ma kota file.txt
// 0 -> wyprintuj linijki co maja ktorykolwiek z tych wzorow -> 0,1,2
// 1 -> to samo ale co maja wszystkie -> 0,2