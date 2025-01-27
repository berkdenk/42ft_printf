ft_printf: Recreating printf() in C

This project is a custom implementation of the widely-used printf() function in C. It demonstrates advanced knowledge of variadic functions, memory management, and formatted output handling while adhering to the 42 Norm.
Features:

    Handles the following format specifiers:
    %c - Single character
    %s - String
    %p - Pointer address (hexadecimal format)
    %d / %i - Signed decimal integers
    %u - Unsigned decimal integers
    %x - Hexadecimal numbers (lowercase)
    %X - Hexadecimal numbers (uppercase)
    %% - Prints a percent sign
    Built as a static library: libftprintf.a
    Reusable for future projects within the 42 curriculum.

Getting Started:

To clone this repository and start using the project:

git clone https://github.com/berkdenk/42ft_printf.git
cd 42ft_printf
make

Usage:

Include the libftprintf.a library in your project and use the ft_printf() function as you would with the standard printf().
Example:

#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! This is a number: %d\n", "World", 42);
    return 0;
}

Feel free to explore, test, and provide feedback!
