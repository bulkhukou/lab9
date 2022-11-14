#include <iostream>
#include <cstring>
#include "functions.h"

const char* flags[4] =
        {
        "--forward",
        "--reverse",
        "--file",
        "--help"
        };

int main(int value, char ** arg) {
    switch (value) {
        case 1:
            std::cerr << "##### Flags weren't read #####\n";
            exit(1);
        case 2:
            if (strcmp(arg[1], flags[3]) == 0) {
                exit(0);
            }
            if (strcmp(arg[1], flags[0]) == 0) {
                std::cout << "Enter a mathematical expression in normalized form:\n>> ";
                forward();
            }
            else if (strcmp(arg[1], flags[1]) == 0) {
                std::cout << "Enter a mathematical expression in reverse polish notation form:\n>> ";
                rpn();
            }
            else {
                std::cerr << "##### Wrong flags #####\n";
                exit(1);
            }
            break;
        case 4:
            if (strcmp(arg[1], flags[2]) == 0) {
                char *filename = arg[2];
                if (strcmp(arg[3], flags[0]) == 0) {
                    std::cout << "A mathematical expression in normalized form\n";
                    forward_f(filename);
                }
                else if (strcmp(arg[3], flags[1]) == 0) {
                    std::cout << "A mathematical expression in reverse polish notation form\n";
                    rpn_f(filename);
                }
            }
            else {
                std::cerr << "##### Wrong flags #####\n";
                exit(1);
            }
            break;
        default:
            std::cerr << "##### Wrong flags #####\n";
            exit(1);
    }
    exit(0);
}
