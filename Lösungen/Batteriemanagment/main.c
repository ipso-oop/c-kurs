#include <stdio.h>

/* Kompakte Statusinformationen eines Batteriemoduls (Bitfelder) */
struct BatteryStatus {
    unsigned int active : 1;        /* 1 = Modul aktiv, 0 = inaktiv */
    unsigned int charging : 1;      /* 1 = Modul wird geladen */
    unsigned int overheating : 1;   /* 1 = Temperatur zu hoch */
    unsigned int undervoltage : 1;  /* 1 = Spannung zu tief */
    unsigned int errorCode : 4;     /* Fehlercode von 0 bis 15 */
};

/* Messwerte und Status eines einzelnen Batteriemoduls */
struct BatteryModule {
    int moduleId;
    float voltage;
    float temperature;
    unsigned int stateOfCharge;
    struct BatteryStatus status;
};

struct BatteryModule createModule(
    int moduleId,
    float voltage,
    float temperature,
    unsigned int stateOfCharge,
    unsigned int active,
    unsigned int charging,
    unsigned int errorCode
) {
    struct BatteryModule module;

    module.moduleId = moduleId;
    module.voltage = voltage;
    module.temperature = temperature;
    module.stateOfCharge = stateOfCharge;

    module.status.active = active;
    module.status.charging = charging;
    module.status.errorCode = errorCode;
    module.status.overheating = (temperature > 60.0) ? 1 : 0;
    module.status.undervoltage = (voltage < 3.2) ? 1 : 0;

    return module;
}

void printModule(struct BatteryModule module) {
    printf("Modul %d\n", module.moduleId);
    printf("Spannung: %.2f V\n", module.voltage);
    printf("Temperatur: %.2f C\n", module.temperature);
    printf("Ladezustand: %u %%\n", module.stateOfCharge);
    printf("Status: %s\n", module.status.active ? "Aktiv" : "Inaktiv");
    printf("Laden: %s\n", module.status.charging ? "Ja" : "Nein");
    printf("Warnung Temperatur: %s\n", module.status.overheating ? "Ja" : "Nein");
    printf("Warnung Unterspannung: %s\n", module.status.undervoltage ? "Ja" : "Nein");
    printf("Fehlercode: %u\n", module.status.errorCode);
}

int isCritical(struct BatteryModule module) {
    return module.status.overheating == 1
        || module.status.undervoltage == 1
        || module.status.errorCode != 0;
}

void printCriticalModules(struct BatteryModule modules[], int count) {
    int i;
    int found = 0;

    for (i = 0; i < count; i++) {
        if (isCritical(modules[i])) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Keine kritischen Module gefunden.\n");
        return;
    }

    printf("Kritische Module:\n");
    printf("-----------------\n");

    for (i = 0; i < count; i++) {
        if (isCritical(modules[i])) {
            printModule(modules[i]);
            printf("\n");
        }
    }
}

float calculateAverageVoltage(struct BatteryModule modules[], int count) {
    int i;
    int activeCount = 0;
    float sum = 0.0f;

    for (i = 0; i < count; i++) {
        if (modules[i].status.active == 1) {
            sum += modules[i].voltage;
            activeCount++;
        }
    }

    if (activeCount == 0) {
        return 0.0f;
    }

    return sum / activeCount;
}

int main(void) {
    struct BatteryModule modules[5];
    float avgVoltage;
    int i;

    modules[0] = createModule(1, 3.70, 42.0, 78, 1, 0, 0);
    modules[1] = createModule(2, 3.10, 39.5, 55, 1, 1, 0);
    modules[2] = createModule(3, 3.85, 67.0, 90, 1, 0, 2);
    modules[3] = createModule(4, 3.60, 30.0, 40, 0, 0, 0);
    modules[4] = createModule(5, 3.00, 72.0, 12, 1, 1, 7);

    printf("Alle Batteriemodule:\n");
    printf("--------------------\n\n");

    for (i = 0; i < 5; i++) {
        printModule(modules[i]);
        printf("\n");
    }

    printf("\n");
    printCriticalModules(modules, 5);

    avgVoltage = calculateAverageVoltage(modules, 5);
    printf("\nDurchschnittsspannung aktiver Module: %.2f V\n", avgVoltage);

    if (avgVoltage < 3.3f) {
        printf("Warnung: Durchschnittsspannung kritisch niedrig!\n");
    }

    return 0;
}
