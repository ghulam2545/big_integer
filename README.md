## Big Integer

The `BigInteger` class is a header-only class designed to represent arbitrary-precision integers in C++.
It allows you to work with large integers that may not fit within the built-in integer
types provided by C++.

It encapsulates integer values as a collection of digits and provides methods and operators
for performing arithmetic operations, comparisons, and I/O operations.

<b>For more look at</b> `docs`. <a>https://ghulam2545.github.io/big_integer/classgh_1_1_big_integer.html</a>

example:

```cpp
#include <iostream>
#include <vector>

#include "BigInteger.hpp"

using namespace std;
using namespace gh;

int main() {
    // single underscore seperated numbers are allowed
    BigInteger x = "100_200_100";
    BigInteger y = "300_200_100";

    cout << "binary plus says: " << x + y << '\n';
    cout << "binary minus says: " << x - y << '\n';
    cout << "binary start says: " << x * y << '\n';

    return 0;
}
```

</br>
</br>
Todos:</br>

- Overload more members for `BigInteger` and `int`
