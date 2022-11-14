#include <iostream>
#include <fstream>

int is_digit(char s) {
    if (s >= '0' && s <= '9')
        return 1;
    return 0;
}

int is_sym(char s) {
    if (s == '+' || s == '-' || s == '/' || s == '*')
        return 1;
    return 0;
}

int calculate(int x, int y, char op) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '/':
            return x / y;
        case '*':
            return x * y;
        default:
            return -1;
    }
}

int prior(char a, char b) {
    if ((a == '*' || a == '/') &&
        (b == '*' || b == '/'))
        return 1;
    else if ((b == '*' || b == '/') &&
             (a == '+' || a == '-'))
        return 1;
    else if ((a == '+' || a == '-') &&
             (b == '+' || b == '-'))
        return 1;
    return 0;
}


int forward() {
    int a, b;
    char oper;
    int nums[100];
    char syms[100];
    int n = 0; int s = 0;
    char token;
    while (std::cin >> token) {
        if (token == '\0') break;
        if (is_digit(token))
            nums[n++] = token - '0';
        if (token == '(')
            syms[s++] = '(';
        if (token == ')') {
            while (syms[s - 1] != '(') {
                a = nums[--n];
                b = nums[--n];
                oper = syms[--s];
                nums[n++] = calculate(b, a, oper);
            }
            s--;
        }
        if (is_sym(token)) {
            if ((s != 0) && (prior(token,  syms[s - 1]))) {
                a = nums[--n];
                b = nums[--n];
                oper = syms[--s];
                nums[n++] = calculate(b, a, oper);
            }
            syms[s++] = token;
        }
    }
    while (s > 0) {
        a = nums[--n];
        b = nums[--n];
        oper = syms[--s];
        nums[n++] = calculate(b, a, oper);
    }
    std::cout << nums[--n] << std::endl;
    return 0;
}

int forward_f(char * namefile) {
    std::ifstream myfile;
    myfile.open(namefile);
    int a, b;
    char oper;
    int nums[100];
    char syms[100];
    int n = 0;
    int s = 0;
    char token;
    if (myfile.is_open()) {
        while (myfile >> token) {
            if (token == '_') break;
            if (is_digit(token))
                nums[n++] = token - '0';
            if (token == '(')
                syms[s++] = '(';
            if (token == ')') {
                while (syms[s - 1] != '(') {
                    a = nums[--n];
                    b = nums[--n];
                    oper = syms[--s];
                    nums[n++] = calculate(b, a, oper);
                }
                s--;
            }
            if (is_sym(token)) {
                if ((s != 0) && (prior(token, syms[s - 1]))) {
                    a = nums[--n];
                    b = nums[--n];
                    oper = syms[--s];
                    nums[n++] = calculate(b, a, oper);
                }
                syms[s++] = token;
            }
        }
        while (s > 0) {
            a = nums[--n];
            b = nums[--n];
            oper = syms[--s];
            nums[n++] = calculate(b, a, oper);
        }
        std::cout << nums[--n] << std::endl;
        return 0;
    }
    return 1;
}


int rpn()
{
    int x, y;
    char operation;
    std::cin >> x;
    while(std::cin >> y)
    {
        std::cin >> operation;
        x = calculate(x, y, operation);
    }
    std::cout << x << std::endl;
    return 0;
}

int rpn_f(char * name_of_file)
{
    std::ifstream fl;
    fl.open(name_of_file);
    if(fl.is_open())
    {
        int x, y;
        char operation;
        fl >> x;
        while(fl >> y)
        {
            fl >> operation;
            x = calculate(x, y, operation);
        }
        std::cout << x << std::endl;
        return 0;
    }
    return 1;
}
