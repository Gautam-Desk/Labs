/**
 * Skill-Based C Programming — Command-Line Argument Processing & CLI Tools
 * Topics:
 *   - Processing argc and argv
 *   - Option & Flag Parsing (--add, --sub, --mul, --div)
 *   - Input Sanitization & String-to-Number Conversion (strtol, strtod)
 *   - CLI Simulator & Self-Contained Verification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef enum {
    OP_UNKNOWN,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV
} OperationType;

typedef struct {
    OperationType op;
    double a;
    double b;
    bool valid;
    char error_msg[64];
} CliCommand;

CliCommand parse_cli_args(int argc, char *argv[]) {
    CliCommand cmd;
    cmd.op = OP_UNKNOWN;
    cmd.a = 0.0;
    cmd.b = 0.0;
    cmd.valid = false;
    cmd.error_msg[0] = '\0';

    if (argc < 4) {
        strncpy(cmd.error_msg, "Usage: <operation> <a> <b>", sizeof(cmd.error_msg) - 1);
        return cmd;
    }

    /* Identify operation */
    if (strcmp(argv[1], "--add") == 0) cmd.op = OP_ADD;
    else if (strcmp(argv[1], "--sub") == 0) cmd.op = OP_SUB;
    else if (strcmp(argv[1], "--mul") == 0) cmd.op = OP_MUL;
    else if (strcmp(argv[1], "--div") == 0) cmd.op = OP_DIV;
    else {
        strncpy(cmd.error_msg, "Unknown operation flag", sizeof(cmd.error_msg) - 1);
        return cmd;
    }

    char *endptr1;
    char *endptr2;
    cmd.a = strtod(argv[2], &endptr1);
    cmd.b = strtod(argv[3], &endptr2);

    if (*endptr1 != '\0' || *endptr2 != '\0') {
        strncpy(cmd.error_msg, "Invalid numeric operands", sizeof(cmd.error_msg) - 1);
        return cmd;
    }

    if (cmd.op == OP_DIV && cmd.b == 0.0) {
        strncpy(cmd.error_msg, "Error: Division by zero", sizeof(cmd.error_msg) - 1);
        return cmd;
    }

    cmd.valid = true;
    return cmd;
}

double execute_command(const CliCommand *cmd) {
    assert(cmd->valid);
    switch (cmd->op) {
        case OP_ADD: return cmd->a + cmd->b;
        case OP_SUB: return cmd->a - cmd->b;
        case OP_MUL: return cmd->a * cmd->b;
        case OP_DIV: return cmd->a / cmd->b;
        default: return 0.0;
    }
}

int main(int argc, char *argv[]) {
    printf("========================================================\n");
    printf("   Skill-Based Lab: Command-Line Argument Processing\n");
    printf("========================================================\n\n");

    /* If run with user CLI arguments, execute them directly */
    if (argc >= 4) {
        CliCommand cmd = parse_cli_args(argc, argv);
        if (cmd.valid) {
            printf("Result: %.4f\n", execute_command(&cmd));
            return 0;
        } else {
            fprintf(stderr, "%s\n", cmd.error_msg);
            return 1;
        }
    }

    /* Automated Test Suite simulating various argv scenarios */
    printf("Simulating CLI inputs...\n");

    /* 1. Addition: program --add 15.5 4.5 -> 20.0 */
    char *test1[] = {"app", "--add", "15.5", "4.5"};
    CliCommand cmd1 = parse_cli_args(4, test1);
    assert(cmd1.valid);
    assert(execute_command(&cmd1) == 20.0);
    printf("  --add 15.5 4.5 = %.2f [PASS]\n", execute_command(&cmd1));

    /* 2. Subtraction: program --sub 50 12.5 -> 37.5 */
    char *test2[] = {"app", "--sub", "50", "12.5"};
    CliCommand cmd2 = parse_cli_args(4, test2);
    assert(cmd2.valid);
    assert(execute_command(&cmd2) == 37.5);
    printf("  --sub 50 12.5 = %.2f [PASS]\n", execute_command(&cmd2));

    /* 3. Multiplication: program --mul 6 7 -> 42.0 */
    char *test3[] = {"app", "--mul", "6", "7"};
    CliCommand cmd3 = parse_cli_args(4, test3);
    assert(cmd3.valid);
    assert(execute_command(&cmd3) == 42.0);
    printf("  --mul 6 7 = %.2f [PASS]\n", execute_command(&cmd3));

    /* 4. Division: program --div 100 4 -> 25.0 */
    char *test4[] = {"app", "--div", "100", "4"};
    CliCommand cmd4 = parse_cli_args(4, test4);
    assert(cmd4.valid);
    assert(execute_command(&cmd4) == 25.0);
    printf("  --div 100 4 = %.2f [PASS]\n", execute_command(&cmd4));

    /* 5. Error case: Division by zero */
    char *test5[] = {"app", "--div", "10", "0"};
    CliCommand cmd5 = parse_cli_args(4, test5);
    assert(!cmd5.valid);
    printf("  Division by zero caught: '%s' [PASS]\n", cmd5.error_msg);

    printf("\n[PASS] All CLI Argument Processing tests passed successfully!\n");
    return 0;
}
