#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @namespace gh
 * The namespace containing the BigInteger class and related utilities.
 */
namespace gh {

/**
 * @brief The base for the BigInteger class, which is 10 (decimal).
 */
const auto BASE = 10;

/**
 * @brief Enumeration representing the sign of a BigInteger.
 */
enum class Sign { POSITIVE, NEGATIVE };

/**
 * @class BigInteger
 * @brief A class to represent arbitrary-precision integers.
 */
class BigInteger {
  private:
    Sign m_sign;
    vector<char> m_data;

  private:
    /**
     * @brief Parse a character array into a vector of digits.
     * @param str The character array to parse.
     * @return A vector of digits representing the parsed integer.
     */
    vector<char> parse(const char *str);

    /**
     * @brief Get the count of digits in the BigInteger.
     * @return The number of digits.
     */
    int count() const;

    /**
     * @brief Add a digit to the end of the BigInteger.
     * @param val The digit to add.
     */
    void push_digit(const int &val);

    /**
     * @brief Change a digit at a specific position in the BigInteger.
     * @param pos The position to change.
     * @param val The new value for the digit.
     */
    void change_digit(const int &pos, const int &val);

    /**
     * @brief Get a digit at a specific position in the BigInteger.
     * @param pos The position to retrieve.
     * @return The digit at the specified position.
     */
    int get_digit(const int &pos) const;

    /**
     * @brief Convert the BigInteger to a string representation.
     * @return The string representation of the BigInteger.
     */
    string to_string() const;

    /**
     * @brief Normalize the BigInteger, removing leading zeros.
     */
    void normalize();

    /**
     * @brief Check if the BigInteger is equal to another BigInteger.
     * @param rhs The other BigInteger to compare.
     * @return True if they are equal, false otherwise.
     */
    bool equal(const BigInteger &rhs) const;

    /**
     * @brief Check if the BigInteger is less than another BigInteger.
     * @param rhs The other BigInteger to compare.
     * @return True if the current BigInteger is less than rhs, false otherwise.
     */
    bool less_than(const BigInteger &rhs) const;

    /**
     * @brief Check if the BigInteger is positive.
     * @return True if the BigInteger is positive, false otherwise.
     */
    bool is_positive() const;

    /**
     * @brief Check if the BigInteger is negative.
     * @return True if the BigInteger is negative, false otherwise.
     */
    bool is_negative() const;

  public:
    /**
     * @brief Default constructor for BigInteger.
     */
    BigInteger();

    /**
     * @brief Constructor that initializes a BigInteger with an integer value.
     * @param num The integer value to initialize the BigInteger.
     */
    BigInteger(int num);

    /**
     * @brief Constructor that initializes a BigInteger from a character array.
     * @param num The character array representing the integer value.
     */
    BigInteger(const char *num);

    /**
     * @brief Constructor that initializes a BigInteger from a string.
     * @param num The string representing the integer value.
     */
    BigInteger(const string &num);

    /**
     * @brief Copy constructor for BigInteger.
     * @param rhs The BigInteger to copy from.
     */
    BigInteger(const BigInteger &rhs);

    /**
     * @brief Move constructor for BigInteger.
     * @param rhs The BigInteger to move from.
     */
    BigInteger(BigInteger &&rhs);

    /**
     * @brief Copy assignment operator for BigInteger.
     * @param rhs The BigInteger to copy from.
     * @return A reference to the assigned BigInteger.
     */
    BigInteger &operator=(const BigInteger &rhs);

    /**
     * @brief Move assignment operator for BigInteger.
     * @param rhs The BigInteger to move from.
     * @return A reference to the assigned BigInteger.
     */
    BigInteger &operator=(BigInteger &&rhs);

    /**
     * @brief Destructor for BigInteger.
     */
    ~BigInteger();

    /**
     * @brief Addition operator to add two BigIntegers.
     * @param rhs The BigInteger to add.
     * @return The result of the addition.
     */
    BigInteger operator+(const BigInteger &rhs) const;

    /**
     * @brief In-place addition operator to add another BigInteger.
     * @param rhs The BigInteger to add.
     * @return A reference to the modified BigInteger.
     */
    BigInteger &operator+=(const BigInteger &rhs);

    /**
     * @brief Subtraction operator to subtract another BigInteger.
     * @param rhs The BigInteger to subtract.
     * @return The result of the subtraction.
     */
    BigInteger operator-(const BigInteger &rhs) const;

    /**
     * @brief In-place subtraction operator to subtract another BigInteger.
     * @param rhs The BigInteger to subtract.
     * @return A reference to the modified BigInteger.
     */
    BigInteger &operator-=(const BigInteger &rhs);

    /**
     * @brief Multiplication operator to multiply two BigIntegers.
     * @param rhs The BigInteger to multiply.
     * @return The result of the multiplication.
     */
    BigInteger operator*(const BigInteger &rhs) const;

    /**
     * @brief In-place multiplication operator to multiply by another
     * BigInteger.
     * @param rhs The BigInteger to multiply by.
     * @return A reference to the modified BigInteger.
     */
    BigInteger &operator*=(const BigInteger &rhs);

    /**
     * @brief Multiplication operator to multiply by an integer.
     * @param num The integer to multiply by.
     * @return The result of the multiplication.
     */
    BigInteger operator*(const int &num) const;

    /**
     * @brief In-place multiplication operator to multiply by an integer.
     * @param num The integer to multiply by.
     * @return A reference to the modified BigInteger.
     */
    BigInteger &operator*=(const int &num);

    /**
     * @brief Equality operator to check if two BigIntegers are equal.
     * @param lhs The left-hand side BigInteger.
     * @param rhs The right-hand side BigInteger.
     * @return True if they are equal, false otherwise.
     */
    friend bool operator==(const BigInteger &lhs, const BigInteger &rhs);

    /**
     * @brief Inequality operator to check if two BigIntegers are not equal.
     * @param lhs The left-hand side BigInteger.
     * @param rhs The right-hand side BigInteger.
     * @return True if they are not equal, false otherwise.
     */
    friend bool operator!=(const BigInteger &lhs, const BigInteger &rhs);

    /**
     * @brief Less than operator to check if one BigInteger is less than
     * another.
     * @param lhs The left-hand side BigInteger.
     * @param rhs The right-hand side BigInteger.
     * @return True if lhs is less than rhs, false otherwise.
     */

    friend bool operator<(const BigInteger &lhs, const BigInteger &rhs);

    /**
     * @brief Less than or equal to operator to check if one BigInteger is less
     * than or equal to another.
     * @param lhs The left-hand side BigInteger.
     * @param rhs The right-hand side BigInteger.
     * @return True if lhs is less than or equal to rhs, false otherwise.
     */
    friend bool operator<=(const BigInteger &lhs, const BigInteger &rhs);

    /**
     * @brief Greater than operator to check if one BigInteger is greater than
     * another.
     * @param lhs The left-hand side BigInteger.
     * @param rhs The right-hand side BigInteger.
     * @return True if lhs is greater than rhs, false otherwise.
     */
    friend bool operator>(const BigInteger &lhs, const BigInteger &rhs);

    /**
     * @brief Greater than or equal to operator to check if one BigInteger is
     * greater than or equal to another.
     * @param lhs The left-hand side BigInteger.
     * @param rhs The right-hand side BigInteger.
     * @return True if lhs is greater than or equal to rhs, false otherwise.
     */
    friend bool operator>=(const BigInteger &lhs, const BigInteger &rhs);

    /**
     * @brief Overloaded output stream operator to print the BigInteger.
     * @param os The output stream.
     * @param rhs The BigInteger to output.
     * @return The output stream.
     */
    friend ostream &operator<<(ostream &os, const BigInteger &rhs);

    /**
     * @brief Overloaded input stream operator to read a BigInteger from an
     * input stream.
     * @param is The input stream.
     * @param rhs The BigInteger to read into.
     * @return The input stream.
     */
    friend istream &operator>>(istream &is, const BigInteger &rhs);
};

/*************************************************
 * implementation
 *
 *
 *
 */

BigInteger::BigInteger() : m_sign(Sign::POSITIVE), m_data{} {}

BigInteger::BigInteger(int num) : m_sign(Sign::POSITIVE), m_data{} {
    if (num < 0) {
        this->m_sign = Sign::NEGATIVE;
        num *= -1;
    }

    while (num) {
        const auto rem = num % BASE;
        push_digit(rem);

        num /= 10;
    }
}

BigInteger::BigInteger(const char *num) : m_sign(Sign::POSITIVE), m_data{} {
    const auto filtered = parse(num);
    for (int i = filtered.size() - 1; i >= 0; --i) {
        const auto digit = filtered[i] - '0';
        push_digit(digit);
    }
}

BigInteger::BigInteger(const string &num) : m_sign(Sign::POSITIVE), m_data{} {
    const auto filtered = parse(num.c_str());
    for (int i = filtered.size() - 1; i >= 0; --i) {
        const auto digit = filtered[i] - '0';
        push_digit(digit);
    }
}

BigInteger::BigInteger(const BigInteger &rhs)
    : m_sign(rhs.m_sign), m_data(rhs.m_data) {}

BigInteger::BigInteger(BigInteger &&rhs)
    : m_sign(rhs.m_sign), m_data(std::move(rhs.m_data)) {}

BigInteger &BigInteger::operator=(const BigInteger &rhs) {
    if (this == &rhs)
        return *this;

    m_data.clear();
    m_data.resize(rhs.m_data.size());

    std::copy(rhs.m_data.begin(), rhs.m_data.end(), m_data.begin());

    m_sign = rhs.m_sign;

    return *this;
}

BigInteger &BigInteger::operator=(BigInteger &&rhs) {
    if (this == &rhs) {
        return *this;
    }

    m_data = rhs.m_data;
    rhs.m_data = {};

    m_sign = rhs.m_sign;

    return *this;
}

BigInteger::~BigInteger() {
    // cout << "dtor, see you later\n";
}

vector<char> BigInteger::parse(const char *str) {
    vector<char> res;
    int len = strlen(str);
    int iter = 0;

    if (str[0] == '-') {
        m_sign = Sign::NEGATIVE;
        iter = 1;
    }

    for (; iter < len; ++iter) {
        if (str[iter] == '_') {
            // ignore
        } else {
            res.push_back(str[iter]);
        }
    }

    return res;
}

BigInteger BigInteger::operator+(const BigInteger &rhs) const {
    auto res = *this;
    res += rhs;
    return res;
}

BigInteger &BigInteger::operator+=(const BigInteger &rhs) {
    if (this == &rhs) {
        *this *= 2;
        return *this;
    }

    if (is_positive() != rhs.is_positive()) {
        *this -= (rhs * -1);
        return *this;
    }

    const auto l_size = this->count();
    const auto r_size = rhs.count();

    int sum = 0;
    int carry = 0;
    for (int i = 0; i < std::max(l_size, r_size); ++i) {
        sum = get_digit(i) + rhs.get_digit(i) + carry;
        carry = sum / BASE;
        sum = sum % BASE;

        if (i < l_size) {
            change_digit(i, sum);
        } else {
            push_digit(sum);
        }
    }

    if (carry)
        push_digit(carry);

    return *this;
}

BigInteger BigInteger::operator-(const BigInteger &rhs) const {
    auto res = *this;
    res -= rhs;
    return res;
}

BigInteger &BigInteger::operator-=(const BigInteger &rhs) {
    if (this == &rhs) {
        *this = 0;
        return *this;
    }

    if (is_negative() != rhs.is_negative()) {
        *this += (rhs * -1);
        return *this;
    }

    if (is_positive() && (*this) < rhs || is_negative() && (*this) > rhs) {
        *this = rhs - *this;
        if (is_positive())
            this->m_sign = Sign::NEGATIVE;
        else
            this->m_sign = Sign::POSITIVE;

        return *this;
    }

    int diff = 0;
    int borrow = 0;

    for (int i = 0; i < count(); ++i) {
        diff = get_digit(i) - rhs.get_digit(i) - borrow;
        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }

        change_digit(i, diff);
    }
    normalize();

    return *this;
}

BigInteger BigInteger::operator*(const BigInteger &rhs) const {
    auto res = *this;
    res *= rhs;
    return res;
}

BigInteger &BigInteger::operator*=(const BigInteger &rhs) {
    bool negate_it = false;
    if (this->m_sign != rhs.m_sign)
        negate_it = true;

    BigInteger lhs = *this;
    BigInteger sum = 0;
    const auto len = rhs.count();

    for (int i = 0; i < len; ++i) {
        sum += lhs * rhs.get_digit(i);
        lhs *= 10;
    }

    *this = sum;

    if (negate_it)
        this->m_sign = Sign::NEGATIVE;

    return *this;
}

BigInteger BigInteger::operator*(const int &num) const {
    auto res = *this;
    res *= num;
    return res;
}

BigInteger &BigInteger::operator*=(const int &num) {
    if (num == 0) {
        *this = 0;
        return *this;
    }

    if (num == 1)
        return *this;

    if (BASE < num || num < 0)
        return *this *= BigInteger(num);

    bool negate_it = false;
    if (this->is_negative() && num > 0)
        negate_it = true;

    // multiply a single positive digit to BigInteger
    int product = 0;
    int carry = 0;
    int len = count();
    for (int i = 0; i < len; ++i) {
        product = num * get_digit(i) + carry;
        carry = product / BASE;
        this->change_digit(i, product % BASE);
    }

    if (carry)
        push_digit(carry);

    if (negate_it)
        this->m_sign = Sign::NEGATIVE;

    return *this;
}

bool operator==(const BigInteger &lhs, const BigInteger &rhs) {
    return lhs.equal(rhs);
}

bool operator!=(const BigInteger &lhs, const BigInteger &rhs) {
    return !(lhs == rhs);
}

bool operator<(const BigInteger &lhs, const BigInteger &rhs) {
    return lhs.less_than(rhs);
}

bool operator<=(const BigInteger &lhs, const BigInteger &rhs) {
    return (lhs == rhs) || (lhs < rhs);
}

bool operator>(const BigInteger &lhs, const BigInteger &rhs) {
    return rhs < lhs;
}

bool operator>=(const BigInteger &lhs, const BigInteger &rhs) {
    return (lhs == rhs) || (rhs > rhs);
}

int BigInteger::count() const { return this->m_data.size(); }

void BigInteger::push_digit(const int &val) {
    this->m_data.push_back(char(val + '0'));
}

void BigInteger::change_digit(const int &pos, const int &val) {
    int len = count();
    if (pos >= 0 && pos < len) {
        this->m_data[pos] = char(val + '0');
        return;
    }

    throw "Invalid position : " + std::to_string(pos);
}

int BigInteger::get_digit(const int &pos) const {
    const auto len = count();

    if (pos >= 0 && pos < len)
        return (m_data[pos] - '0');

    return 0;
}

string BigInteger::to_string() const {
    string res = "";
    if (this->is_negative())
        res.push_back('-');

    int len = count();

    for (auto i = len - 1; i >= 0; --i) {
        const auto digit = char(get_digit(i) + '0');
        res.push_back(digit);
    }

    return res.size() ? res : "0";
}

void BigInteger::normalize() {
    const auto len = count();
    for (int i = len - 1; i >= 0; --i) {
        if (get_digit(i) != 0)
            break;
        else {
            if (m_data.size())
                m_data.pop_back();
        }
    }
}

bool BigInteger::equal(const BigInteger &rhs) const {
    const auto l_size = this->count();
    const auto r_size = rhs.count();
    const auto l_sign = this->m_sign;
    const auto r_sign = rhs.m_sign;

    if ((l_size != r_size) || (l_sign != r_sign))
        return false;

    for (auto i = 0; i < l_size; ++i) {
        if (this->get_digit(i) != rhs.get_digit(i))
            return false;
    }

    return true;
}

bool BigInteger::less_than(const BigInteger &rhs) const {
    const auto l_size = this->count();
    const auto r_size = rhs.count();
    const auto l_sign = this->m_sign;
    const auto r_sign = rhs.m_sign;

    if (l_sign != r_sign)
        return this->is_negative();

    if (l_size != r_size)
        return (l_size < r_size && this->is_positive()) ||
               (l_size > r_size && this->is_negative());

    for (auto i = l_size - 1; i >= 0; --i) {
        if (this->get_digit(i) < rhs.get_digit(i))
            return this->is_positive();
        if (this->get_digit(i) > rhs.get_digit(i))
            return this->is_negative();
    }

    return false;
}

bool BigInteger::is_positive() const { return this->m_sign == Sign::POSITIVE; }

bool BigInteger::is_negative() const { return this->m_sign == Sign::NEGATIVE; }

ostream &operator<<(ostream &os, const BigInteger &rhs) {
    os << rhs.to_string();
    return os;
}

istream &operator>>(istream &is, BigInteger &rhs) {
    string str;
    is >> str;

    rhs = BigInteger(str);
    return is;
}

} // namespace gh

#endif