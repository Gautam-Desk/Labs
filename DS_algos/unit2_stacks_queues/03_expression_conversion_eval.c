/**
 * Unit 2 — Expression Conversion & Evaluation
 * Topics:
 *   - Infix to Postfix Conversion
 *   - Postfix Expression Evaluation
 *   - Infix to Prefix Conversion (Reverse -> Postfix -> Reverse)
 *   - Prefix Expression Evaluation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define MAX_EXP_LEN 256

/* ========================================================================= */
/* Operator Precedence and Helper Functions                                  */
/* ========================================================================= */

int precedence(char op) {
    switch (op) {
        case '^':
        case '$':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '$');
}

int is_right_associative(char op) {
    return (op == '^' || op == '$');
}

/* ========================================================================= */
/* Infix to Postfix                                                          */
/* ========================================================================= */

void infix_to_postfix(const char *infix, char *postfix) {
    char stack[MAX_EXP_LEN];
    int top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isspace((unsigned char)ch)) continue;

        if (isalnum((unsigned char)ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') {
                top--; /* Discard '(' */
            }
        } else if (is_operator(ch)) {
            while (top != -1 && is_operator(stack[top])) {
                int p_top = precedence(stack[top]);
                int p_curr = precedence(ch);

                if ((!is_right_associative(ch) && p_top >= p_curr) ||
                    (is_right_associative(ch) && p_top > p_curr)) {
                    postfix[k++] = stack[top--];
                } else {
                    break;
                }
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        if (stack[top] != '(') {
            postfix[k++] = stack[top];
        }
        top--;
    }
    postfix[k] = '\0';
}

/* ========================================================================= */
/* Postfix Evaluation                                                        */
/* ========================================================================= */

double evaluate_postfix(const char *postfix) {
    double stack[MAX_EXP_LEN];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isspace((unsigned char)ch)) continue;

        if (isdigit((unsigned char)ch)) {
            stack[++top] = (double)(ch - '0');
        } else if (is_operator(ch)) {
            assert(top >= 1);
            double op2 = stack[top--];
            double op1 = stack[top--];
            double res = 0.0;

            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': assert(op2 != 0.0); res = op1 / op2; break;
                case '^':
                case '$': res = pow(op1, op2); break;
                default: break;
            }
            stack[++top] = res;
        }
    }

    assert(top == 0);
    return stack[top];
}

/* ========================================================================= */
/* Infix to Prefix                                                           */
/* ========================================================================= */

void reverse_string(char *str) {
    int len = (int)strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

void infix_to_prefix(const char *infix, char *prefix) {
    char rev[MAX_EXP_LEN];
    strncpy(rev, infix, MAX_EXP_LEN - 1);
    rev[MAX_EXP_LEN - 1] = '\0';

    reverse_string(rev);

    /* Swap '(' and ')' */
    for (int i = 0; rev[i] != '\0'; i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    char postfix[MAX_EXP_LEN];
    infix_to_postfix(rev, postfix);

    reverse_string(postfix);
    strcpy(prefix, postfix);
}

/* ========================================================================= */
/* Prefix Evaluation                                                         */
/* ========================================================================= */

double evaluate_prefix(const char *prefix) {
    double stack[MAX_EXP_LEN];
    int top = -1;
    int len = (int)strlen(prefix);

    /* Scan from right to left */
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isspace((unsigned char)ch)) continue;

        if (isdigit((unsigned char)ch)) {
            stack[++top] = (double)(ch - '0');
        } else if (is_operator(ch)) {
            assert(top >= 1);
            double op1 = stack[top--];
            double op2 = stack[top--];
            double res = 0.0;

            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': assert(op2 != 0.0); res = op1 / op2; break;
                case '^':
                case '$': res = pow(op1, op2); break;
                default: break;
            }
            stack[++top] = res;
        }
    }

    assert(top == 0);
    return stack[top];
}

int main(void) {
    printf("=== UNIT 2: Expression Conversion & Evaluation Tests ===\n\n");

    /* 1. Infix to Postfix: A + (B * C + D) / E -> ABC*D+E/+ */
    const char *infix1 = "A + (B * C + D) / E";
    char postfix1[MAX_EXP_LEN];
    infix_to_postfix(infix1, postfix1);
    printf("1. Infix:   %s\n   Postfix: %s (Expected: ABC*D+E/+)\n", infix1, postfix1);
    assert(strcmp(postfix1, "ABC*D+E/+") == 0);

    /* 2. Infix to Prefix: (A + B^C) * D + E^5 */
    const char *infix2 = "(A + B^C) * D + E^5";
    char prefix2[MAX_EXP_LEN];
    infix_to_prefix(infix2, prefix2);
    printf("\n2. Infix:  %s\n   Prefix: %s (Expected: +*+A^BCD^E5)\n", infix2, prefix2);
    assert(strcmp(prefix2, "+*+A^BCD^E5") == 0);

    /* 3. Postfix Evaluation: 5 6 2 + * 12 4 / - (single-digit sequence without spaces or spaced) */
    /* 6+2=8, 5*8=40, 12/4=3, 40-3=37 */
    /* To test with single digits: "5 6 2 + * 9 3 / -" -> (6+2)*5 - (9/3) = 40 - 3 = 37 */
    const char *eval_post = "562+*93/-";
    double post_res = evaluate_postfix(eval_post);
    printf("\n3. Postfix Eval of '562+*93/-': %.1f (Expected: 37.0)\n", post_res);
    assert(post_res == 37.0);

    /* 4. Prefix Evaluation: - * 5 + 6 2 / 9 3 -> 5*(6+2) - 9/3 = 40 - 3 = 37 */
    const char *eval_pre = "-*5+62/93";
    double pre_res = evaluate_prefix(eval_pre);
    printf("4. Prefix Eval of '-*5+62/93': %.1f (Expected: 37.0)\n", pre_res);
    assert(pre_res == 37.0);

    printf("\n>>> All Expression Conversion & Evaluation tests passed successfully!\n\n");
    return 0;
}
