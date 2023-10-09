#include <iostream>
int main()
{
    int t[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

    for (int i = 8; i >= 0; --i) {
        t[i] = t[i + 1];
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
}