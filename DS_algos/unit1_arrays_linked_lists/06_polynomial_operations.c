/**
 * Unit 1 — Polynomial Operations Using Linked List
 * Operations:
 *   - Polynomial Representation (coeff, exp, next)
 *   - Addition O(m + n)
 *   - Subtraction O(m + n)
 *   - Multiplication O(m * n)
 *   - Differentiation (power rule)
 *   - Evaluation (direct + Horner's Rule)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode *next;
} PolyNode;

PolyNode* create_term(int coeff, int exp) {
    if (coeff == 0) return NULL;
    PolyNode *term = (PolyNode *)malloc(sizeof(PolyNode));
    if (term == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    term->coeff = coeff;
    term->exp = exp;
    term->next = NULL;
    return term;
}

/**
 * Inserts a term keeping the list sorted in descending order of exponents.
 * Merges coefficients if an exponent already exists.
 */
void insert_term(PolyNode **poly, int coeff, int exp) {
    if (coeff == 0) return;

    if (*poly == NULL || exp > (*poly)->exp) {
        PolyNode *newNode = create_term(coeff, exp);
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    if ((*poly)->exp == exp) {
        (*poly)->coeff += coeff;
        if ((*poly)->coeff == 0) {
            PolyNode *toDelete = *poly;
            *poly = (*poly)->next;
            free(toDelete);
        }
        return;
    }

    PolyNode *curr = *poly;
    while (curr->next != NULL && curr->next->exp > exp) {
        curr = curr->next;
    }

    if (curr->next != NULL && curr->next->exp == exp) {
        curr->next->coeff += coeff;
        if (curr->next->coeff == 0) {
            PolyNode *toDelete = curr->next;
            curr->next = curr->next->next;
            free(toDelete);
        }
        return;
    }

    PolyNode *newNode = create_term(coeff, exp);
    newNode->next = curr->next;
    curr->next = newNode;
}

void print_poly(const char *name, const PolyNode *poly) {
    printf("  %s(x) = ", name);
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    const PolyNode *ptr = poly;
    int first = 1;
    while (ptr != NULL) {
        if (!first && ptr->coeff > 0) printf("+ ");
        if (ptr->coeff < 0) printf("- ");

        int abs_c = abs(ptr->coeff);
        if (ptr->exp == 0) {
            printf("%d ", abs_c);
        } else if (ptr->exp == 1) {
            if (abs_c == 1) printf("x ");
            else printf("%dx ", abs_c);
        } else {
            if (abs_c == 1) printf("x^%d ", ptr->exp);
            else printf("%dx^%d ", abs_c, ptr->exp);
        }

        first = 0;
        ptr = ptr->next;
    }
    printf("\n");
}

/**
 * Polynomial Addition: O(m + n) merge
 */
PolyNode* poly_add(const PolyNode *p1, const PolyNode *p2) {
    PolyNode *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insert_term(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            insert_term(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                insert_term(&result, sum, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert_term(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert_term(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

/**
 * Polynomial Subtraction: O(m + n)
 */
PolyNode* poly_subtract(const PolyNode *p1, const PolyNode *p2) {
    PolyNode *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insert_term(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            insert_term(&result, -p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int diff = p1->coeff - p2->coeff;
            if (diff != 0) {
                insert_term(&result, diff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert_term(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert_term(&result, -p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

/**
 * Polynomial Multiplication: O(m * n)
 */
PolyNode* poly_multiply(const PolyNode *p1, const PolyNode *p2) {
    PolyNode *result = NULL;
    for (const PolyNode *ptr1 = p1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (const PolyNode *ptr2 = p2; ptr2 != NULL; ptr2 = ptr2->next) {
            int c = ptr1->coeff * ptr2->coeff;
            int e = ptr1->exp + ptr2->exp;
            insert_term(&result, c, e);
        }
    }
    return result;
}

/**
 * Polynomial Differentiation: d/dx (c * x^e) = (c * e) * x^(e-1)
 */
PolyNode* poly_differentiate(const PolyNode *p) {
    PolyNode *result = NULL;
    for (const PolyNode *ptr = p; ptr != NULL; ptr = ptr->next) {
        if (ptr->exp > 0) {
            int c = ptr->coeff * ptr->exp;
            int e = ptr->exp - 1;
            insert_term(&result, c, e);
        }
    }
    return result;
}

/**
 * Evaluate polynomial for a given x
 */
double poly_evaluate(const PolyNode *p, double x) {
    double sum = 0.0;
    for (const PolyNode *ptr = p; ptr != NULL; ptr = ptr->next) {
        sum += ptr->coeff * pow(x, ptr->exp);
    }
    return sum;
}

/**
 * Horner's Method for Dense Polynomial: a_n * x^n + ... + a_0
 */
double horner_eval(const double *coeffs, int n, double x) {
    double res = coeffs[n];
    for (int i = n - 1; i >= 0; i--) {
        res = res * x + coeffs[i];
    }
    return res;
}

void free_poly(PolyNode **poly) {
    PolyNode *curr = *poly;
    while (curr != NULL) {
        PolyNode *next = curr->next;
        free(curr);
        curr = next;
    }
    *poly = NULL;
}

int main(void) {
    printf("=== UNIT 1: Polynomial Operations Tests ===\n\n");

    /* P1 = 5x^2 + 4x + 2 */
    PolyNode *p1 = NULL;
    insert_term(&p1, 5, 2);
    insert_term(&p1, 4, 1);
    insert_term(&p1, 2, 0);
    print_poly("P1", p1);

    /* P2 = 3x^3 + 2x^2 + 1 */
    PolyNode *p2 = NULL;
    insert_term(&p2, 3, 3);
    insert_term(&p2, 2, 2);
    insert_term(&p2, 1, 0);
    print_poly("P2", p2);

    /* Addition */
    PolyNode *p_add = poly_add(p1, p2);
    print_poly("P1 + P2", p_add);
    /* Expect: 3x^3 + 7x^2 + 4x + 3 */
    assert(poly_evaluate(p_add, 1.0) == 17.0);

    /* Subtraction */
    PolyNode *p_sub = poly_subtract(p1, p2);
    print_poly("P1 - P2", p_sub);

    /* Multiplication: (x + 2) * (x - 2) = x^2 - 4 */
    PolyNode *q1 = NULL, *q2 = NULL;
    insert_term(&q1, 1, 1);
    insert_term(&q1, 2, 0);
    insert_term(&q2, 1, 1);
    insert_term(&q2, -2, 0);
    PolyNode *q_mult = poly_multiply(q1, q2);
    print_poly("(x+2)(x-2)", q_mult);
    assert(q_mult->exp == 2 && q_mult->coeff == 1);
    assert(q_mult->next->exp == 0 && q_mult->next->coeff == -4);

    /* Differentiation: d/dx (5x^2 + 4x + 2) = 10x + 4 */
    PolyNode *p_diff = poly_differentiate(p1);
    print_poly("d/dx(P1)", p_diff);
    assert(p_diff->coeff == 10 && p_diff->exp == 1);
    assert(p_diff->next->coeff == 4 && p_diff->next->exp == 0);

    /* Horner's Evaluation: P(x) = 2 + 4x + 5x^2 at x = 2 -> 2 + 8 + 20 = 30 */
    double dense[3] = {2.0, 4.0, 5.0};
    double h_res = horner_eval(dense, 2, 2.0);
    printf("  Horner's Eval of P1 at x=2: %.1f (Expected: 30.0)\n", h_res);
    assert(h_res == 30.0);

    /* Free all lists */
    free_poly(&p1);
    free_poly(&p2);
    free_poly(&p_add);
    free_poly(&p_sub);
    free_poly(&q1);
    free_poly(&q2);
    free_poly(&q_mult);
    free_poly(&p_diff);

    printf(">>> All Polynomial Operations tests passed successfully!\n\n");
    return 0;
}
