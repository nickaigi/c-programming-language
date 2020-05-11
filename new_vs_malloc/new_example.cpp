#include<iostream>

int main() {
    int* p;
    int i;

    p = new int[5]; /* allocate space for 5 integers */
    std::cout << "Enter elements :\n";
    for (i = 0; i < 5; i++)
        std::cin >> p[i];

    std::cout << "We entered :\n";
    for (i = 0; i < 5; i++)
        std::cout << p[i] << std::endl;

    delete(p);

    return 0;
}
