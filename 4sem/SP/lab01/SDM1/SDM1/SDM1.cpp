#include "mlisp.h"

double smallest__divisor(double n);
double SDMsquare(double n);
double find__divisor(double n, double test__divisor);
bool divides_Q(double a, double b);
bool prime_Q(double n);

double smallest__divisor(double n) {
    return find__divisor(n, 2.);
}

double SDMsquare(double n) {
    return n * n;
}

double find__divisor(double n, double test__divisor) {
    return (SDMsquare(test__divisor) > n ? n
            : divides_Q(test__divisor, n) ? test__divisor
            : find__divisor(n, ++test__divisor));
}

bool divides_Q(double a, double b) {
    return remainder(b, a) == 0.;
}

bool prime_Q(double n) {
    return (n == smallest__divisor(n));
}

int main() {
    display("Primes or not:"); newline();
    display(prime_Q(1)); newline();
    display(prime_Q(2)); newline();
    display(prime_Q(3)); newline();
    display(prime_Q(4)); newline();
    display(prime_Q(5)); newline();
    display(prime_Q(6)); newline();
    display(prime_Q(7)); newline();
    display(prime_Q(8)); newline();
    display(prime_Q(9)); newline();
    display(prime_Q(010.)); newline();

    std::cin.get();
}