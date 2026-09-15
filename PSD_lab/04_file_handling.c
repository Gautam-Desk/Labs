/**
 * Problem Solving in C (PSD Lab) — File Handling (Text & Binary Modes)
 * Topics:
 *   - File Pointers and Modes ("w", "r", "wb", "rb")
 *   - Text Stream I/O: fprintf, fscanf, fgets
 *   - Binary Stream I/O: fwrite, fread, sizeof
 *   - Safe File Closing & Error Handling
 *   - Clean Temporary File Removal
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int id;
    char code[8];
    double balance;
} AccountRecord;

int main(void) {
    printf("========================================================\n");
    printf("   PSD Lab: Text & Binary File I/O Operations\n");
    printf("========================================================\n\n");

    const char *text_filename = "temp_test_file.txt";
    const char *bin_filename = "temp_test_file.bin";

    /* ===================================================================== */
    /* 1. Text File I/O                                                      */
    /* ===================================================================== */
    FILE *ftext = fopen(text_filename, "w");
    assert(ftext != NULL);

    fprintf(ftext, "Item: %s Count: %d Price: %.2f\n", "Laptop", 5, 899.99);
    fprintf(ftext, "Item: %s Count: %d Price: %.2f\n", "Mouse", 20, 24.50);
    fclose(ftext);

    ftext = fopen(text_filename, "r");
    assert(ftext != NULL);

    char item1[32], item2[32];
    int count1, count2;
    double price1, price2;

    int read_count1 = fscanf(ftext, "Item: %31s Count: %d Price: %lf\n", item1, &count1, &price1);
    int read_count2 = fscanf(ftext, "Item: %31s Count: %d Price: %lf\n", item2, &count2, &price2);
    fclose(ftext);

    assert(read_count1 == 3);
    assert(read_count2 == 3);
    assert(strcmp(item1, "Laptop") == 0 && count1 == 5 && price1 > 899.0);
    assert(strcmp(item2, "Mouse") == 0 && count2 == 20 && price2 > 24.0);

    printf("Text file I/O verified: read '%s' and '%s'\n", item1, item2);

    /* ===================================================================== */
    /* 2. Binary File I/O                                                    */
    /* ===================================================================== */
    AccountRecord records_write[2] = {
        {1001, "USD", 15450.75},
        {1002, "EUR", 8920.50}
    };

    FILE *fbin = fopen(bin_filename, "wb");
    assert(fbin != NULL);

    size_t written = fwrite(records_write, sizeof(AccountRecord), 2, fbin);
    assert(written == 2);
    fclose(fbin);

    AccountRecord records_read[2];
    fbin = fopen(bin_filename, "rb");
    assert(fbin != NULL);

    size_t items_read = fread(records_read, sizeof(AccountRecord), 2, fbin);
    assert(items_read == 2);
    fclose(fbin);

    assert(records_read[0].id == 1001);
    assert(strcmp(records_read[0].code, "USD") == 0);
    assert(records_read[1].id == 1002);
    assert(strcmp(records_read[1].code, "EUR") == 0);

    printf("Binary file I/O verified: read %zu account records successfully\n", items_read);

    /* Cleanup temporary test files */
    remove(text_filename);
    remove(bin_filename);

    printf("\n[PASS] All File Handling tests passed successfully!\n");
    return 0;
}
