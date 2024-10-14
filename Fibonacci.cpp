#include <iostream>

long Fibonacci(int n){
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n{0};
    std::cout <<"Le programme permet de calculer les termes de la suite de fibonacci d'un rang donné " << std::endl;
    std::cout <<"Entrer le rang que vous souhaitez calculer " << std::endl;
    std::cin >> n;
    std::cout << "F(" << n << ") = " << Fibonacci(n) << std::endl;
}
