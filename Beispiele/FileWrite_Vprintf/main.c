#include <stdio.h>
#include <stdarg.h>

void write_log(const char *format, ...) {
    FILE *file = fopen("Beispiele/FileWrite_Vprintf/log.txt", "w");
    if (file != NULL) {
        va_list args;
        va_start(args, format);
        vfprintf(file, format, args);
        va_end(args);
        fclose(file);
    }
}

int main() {
    write_log("Name: %s\nAlter: %d\nPunktzahl: %.2f\n", "Roman", 30, 95.75);
    return 0;
}
