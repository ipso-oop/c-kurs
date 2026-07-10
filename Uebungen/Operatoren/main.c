#include <stdio.h>


void main(void)
{
    // 1. Deklarieren und initialisieren von x und y
    int x = 15;
    int y = 4;
    
    // 2. Deklarieren von z
    int z;
    
    // 3. Operationen durchführen und Ergebnisse speichern/ausgeben
    
    // Addition
    z = x + y;
    printf("Addition (%d + %d) = %d\n", x, y, z);
    
    // Subtraktion (y von x)
    z = x - y;
    printf("Subtraktion (%d - %d) = %d\n", x, y, z);
    
    // Multiplikation
    z = x * y;
    printf("Multiplikation (%d * %d) = %d\n", x, y, z);
    
    // Ganzzahlige Division
    z = x / y;
    printf("Ganzzahlige Division (%d / %d) = %d\n", x, y, z);
    
    // Modulus
    z = x % y;
    printf("Modulus (%d %% %d) = %d\n", x, y, z);
    
    // Inkrementiere x und speichere in z
    z = ++x;  // Prä-Inkrement: x wird zuerst erhöht, dann der neue Wert in z gespeichert
    printf("Inkrement (++x) = %d (neuer Wert von x: %d)\n", z, x);
    
    // Dekrementiere y und speichere in z
    z = --y;  // Prä-Dekrement: y wird zuerst verringert, dann der neue Wert in z gespeichert
    printf("Dekrement (--y) = %d (neuer Wert von y: %d)\n", z, y);
    
    return 0;
    
}
