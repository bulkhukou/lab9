#include <iostream>
#include <fstream>

using std::cout;
using std::cin;

const int sz = 5;

template <typename T> // шаблон
void print(const std::string& sep, T arr[sz], std::ostream& out)  // sep - разделитель;  Т - массив размера sz
{
    for (int i = 0; i < sz - 1; ++i)
    {
        out << arr[i] << sep;
    }
    out << arr[sz - 1] << '\n';
}

int main(int argc, char **argv)
{
    if (argc == 1) // если не было введено имя файла
    {
        std::cerr << "Enter the file name";
        exit(EXIT_FAILURE);
    }
    else
    {
        int arr_int[sz] = {1, 2, 3, 4, 5};
        char arr_char[sz] = {'6', '7', '8', '9', '!'};

        std::ofstream file_out;
        file_out.open(argv[1]);

        print<int>(" . ", arr_int, file_out);
        print<char>("; ", arr_char, file_out);

        file_out.close();

    }
    return 0;
}