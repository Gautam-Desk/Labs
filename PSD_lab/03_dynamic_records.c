/**
 * Problem Solving in C (PSD Lab) — Structures & Dynamic Memory Allocation
 * Topics:
 *   - Struct Definition (Student Record)
 *   - Dynamic Memory Allocation (malloc, realloc, free)
 *   - Array of Dynamically Allocated Structs
 *   - Search & Statistical Aggregations (Class Average, Highest Marks)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int roll_no;
    char name[32];
    float marks;
} Student;

typedef struct {
    Student *students;
    int count;
    int capacity;
} StudentRegistry;

void init_registry(StudentRegistry *reg, int initial_capacity) {
    reg->students = (Student *)malloc(sizeof(Student) * initial_capacity);
    if (!reg->students) {
        fprintf(stderr, "Memory error\n");
        exit(EXIT_FAILURE);
    }
    reg->count = 0;
    reg->capacity = initial_capacity;
}

void add_student(StudentRegistry *reg, int roll, const char *name, float marks) {
    if (reg->count >= reg->capacity) {
        reg->capacity *= 2;
        reg->students = (Student *)realloc(reg->students, sizeof(Student) * reg->capacity);
        if (!reg->students) {
            fprintf(stderr, "Realloc failed\n");
            exit(EXIT_FAILURE);
        }
    }
    Student *s = &reg->students[reg->count++];
    s->roll_no = roll;
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    s->marks = marks;
}

float calculate_average_marks(const StudentRegistry *reg) {
    if (reg->count == 0) return 0.0f;
    float sum = 0;
    for (int i = 0; i < reg->count; i++) {
        sum += reg->students[i].marks;
    }
    return sum / reg->count;
}

const Student *find_highest_scorer(const StudentRegistry *reg) {
    if (reg->count == 0) return NULL;
    const Student *highest = &reg->students[0];
    for (int i = 1; i < reg->count; i++) {
        if (reg->students[i].marks > highest->marks) {
            highest = &reg->students[i];
        }
    }
    return highest;
}

void free_registry(StudentRegistry *reg) {
    free(reg->students);
    reg->students = NULL;
    reg->count = 0;
    reg->capacity = 0;
}

int main(void) {
    printf("========================================================\n");
    printf("   PSD Lab: Dynamic Records & Memory Management\n");
    printf("========================================================\n\n");

    StudentRegistry reg;
    init_registry(&reg, 2); /* Start with small capacity to test auto-resize */

    add_student(&reg, 101, "Alice Smith", 88.5f);
    add_student(&reg, 102, "Bob Jones", 92.0f);
    add_student(&reg, 103, "Charlie Brown", 79.5f);
    add_student(&reg, 104, "Diana Prince", 96.5f);

    printf("Total registered students: %d\n", reg.count);
    assert(reg.count == 4);
    assert(reg.capacity >= 4);

    float avg = calculate_average_marks(&reg);
    printf("Class Average Marks: %.2f\n", avg);
    assert(avg > 89.0f && avg < 90.0f);

    const Student *topper = find_highest_scorer(&reg);
    assert(topper != NULL);
    printf("Highest Scorer: %s (Roll %d) with %.1f marks\n", topper->name, topper->roll_no, topper->marks);
    assert(topper->roll_no == 104);
    assert(strcmp(topper->name, "Diana Prince") == 0);

    free_registry(&reg);
    printf("\n[PASS] All Dynamic Record tests passed successfully!\n");
    return 0;
}
