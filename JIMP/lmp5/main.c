#include <stdio.h>

double load_vector(FILE *file, double* v, int n) {

    int n2;
    fscanf(file, "%d", &n2);

    if (n2 > n) {
        fprintf(stderr, "za duzio");
        return 0;
    }

    for (int i = 0; i < n2; i++) {
        fscanf(file, "%lf", &v[i]);
    }
    
    return n;
    
}

int main() {
    FILE *plik = fopen("dat.txt", "r");
    if (!plik) {
        perror("Nie udało się otworzyć pliku");
        return 1;
    }

    double liczby[100];
    int n = load_vector(plik, liczby, 5);

    printf("Wczytano %d elementów:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%lf ", liczby[i]);
    }
    printf("\n");

    fclose(plik);
    return 0;
}