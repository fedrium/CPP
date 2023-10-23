#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
        std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; argv[i] != NULL; i++)
    {
        for (int x = 0; x < (int)strlen(argv[i]); x++)
        {
            if (argv[i][x] >= 97 && argv[i][x] <= 122)
                argv[i][x] = argv[i][x] - 32;
        }
        std:: cout << argv[i];
    }
}