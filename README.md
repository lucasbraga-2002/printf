*This project has been created as part of the 42 curriculum by lbraga-m.*

# ft_printf

## Description

The **ft_printf** project consists of recreating a simplified version of the standard C `printf()` function.

The goal is to understand variadic functions, formatted output, type conversions, recursion, and the creation of a static library in C.

The implementation supports the following conversions:

- `%c` — Prints a character.
- `%s` — Prints a string.
- `%p` — Prints a pointer address in hexadecimal.
- `%d` and `%i` — Print signed decimal integers.
- `%u` — Prints an unsigned decimal integer.
- `%x` and `%X` — Print hexadecimal integers in lowercase or uppercase.
- `%%` — Prints a percent sign.

The project produces a static library named `libftprintf.a`.

## Instructions

### Compilation

Run the following command at the root of the project:

```bash
make
```

This compiles the source files and creates `libftprintf.a`.

Other available commands:

```bash
make clean     # Remove object files
make fclean    # Remove object files and the library
make re        # Rebuild the library
```

### Usage

Include the header in a C program:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Number: %d\n", "42", 42);
    return (0);
}
```

Compile the program by linking the library:

```bash
cc main.c -L. -lftprintf -o program
```

Then execute:

```bash
./program
```

## Algorithm and Data Structures

The implementation uses a **format-string parser**, a **variadic argument list**, and several helper functions.

### Format parsing

The main `ft_printf` function iterates through the format string character by character.

Ordinary characters are printed directly. When the function encounters `%`, it reads the next character and selects the corresponding conversion.

A dispatcher function handles this selection.

### Variadic arguments

The `<stdarg.h>` library provides the mechanisms needed to access a variable number of arguments.

- `va_list` stores the state of argument traversal.
- `va_start` initializes the argument list.
- `va_arg` retrieves an argument using its expected type.
- `va_end` finishes argument processing.

Passing a pointer to the argument list allows the dispatcher to consume arguments in sequence.

### Numeric conversions

Decimal and hexadecimal integers are printed using **recursion**.

For decimal output, a number is divided by 10 until individual digits can be printed. For hexadecimal output, the same principle is applied using division and modulo 16.

The modulo operation identifies the current digit, while recursive calls allow the digits to be printed in the correct order.

For hexadecimal conversions, a string containing the hexadecimal alphabet is used to map numeric remainders to characters. Different alphabets are supplied for lowercase and uppercase output.

### Pointer conversion

Pointer addresses are converted into an unsigned integer type capable of representing addresses on the target 64-bit environment.

The hexadecimal printing logic is then reused, preceded by the `0x` prefix.

### Data structure choices

No dynamic data structures were necessary.

The implementation primarily uses:

- A format string to describe the required output.
- A `va_list` to access variadic arguments.
- Integer variables to track positions and printed character counts.
- Constant hexadecimal digit sequences for number conversion.
- The call stack to handle recursive numeric printing.

This approach keeps the implementation small and avoids unnecessary dynamic memory allocation.

## Resources

- [printf(3) — Linux manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) — Linux manual](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [GNU Make documentation](https://www.gnu.org/software/make/manual/)
- The official 42 `ft_printf` subject.

### AI Usage

ChatGPT was used as a learning and debugging assistant throughout development.

Its assistance included:

- Explaining variadic functions, recursion, integer types, and pointer representation.
- Reviewing code written by the student and identifying mistakes.
- Helping design and interpret tests, including comparisons with the standard `printf`.
- Assisting with README documentation.

The project was implemented incrementally, with the student writing and adjusting the functions while using AI for explanations, feedback, and debugging support.

## Testing

The project was tested using:

- Compilation with `-Wall -Wextra -Werror`.
- Norminette.
- Custom tests comparing `ft_printf` with the standard `printf`.
- Francinette and its mandatory `printfTester` tests.

The implementation covers the mandatory project requirements. Bonus formatting features are not implemented.
