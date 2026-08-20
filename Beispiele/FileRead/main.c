#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *file;
    char buffer[256];

    // Datei öffnen
    file = fopen("Beispiele/FileRead/beispiel.txt", "r");
    if (file == NULL) {
        perror("Fehler beim Öffnen der Datei");
    }

    // Zeilenweise lesen und ausgeben
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Datei schließen
    fclose(file);

}
