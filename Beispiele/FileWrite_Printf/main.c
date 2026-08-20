#include <stdio.h>

int main() {
    FILE *file = fopen("Beispiele/FileWrite_Printf/output.txt", "w");
    if (file != NULL) {
        fprintf(file, "Name: %s\n", "Roman");
        fprintf(file, "Alter: %d\n", 30);
        fprintf(file, "Punktzahl: %.2f\n", 95.75);
        fclose(file);
    }
    return 0;
}
