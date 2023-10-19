#include <iostream>
#include <vector>

#include "BigInteger.hpp"

using namespace std;
using namespace gh;

int main() {
    BigInteger x = "100_200_100";
    BigInteger y = "300_200_100";

    cout << "binary plus says: " << x + y << '\n';
    cout << "binary minus says: " << x - y << '\n';
    cout << "binary start says: " << x * y << '\n';

    return 0;
}