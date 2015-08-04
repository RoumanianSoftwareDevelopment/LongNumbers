#include "LongInteger.h"

using namespace std;

#ifdef TEST 

bool LongInteger::GetSignForTests() const
{
    return sign;
}

string& LongInteger::GetDigitsForTests()
{
    return digits;
}

#endif

LongInteger::LongInteger()
{
    sign = true;
    digits = "0";
}

LongInteger::LongInteger(int number)
{
    if (number < 0)
    {
        sign = false;
        number *= -1;
    }
    else
        sign = true;

    digits = to_string(number);
}

LongInteger::LongInteger(long number)
{
    if (number < 0)
    {
        sign = false;
        number *= -1;
    }
    else
        sign = true;

    digits = to_string(number);
}

LongInteger::LongInteger(long long number)
{
    if (number < 0)
    {
        sign = false;
        number *= -1;
    }
    else
        sign = true;

    digits = to_string(number);
}

LongInteger::LongInteger(unsigned number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(unsigned long number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(unsigned long long number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(const LongInteger& number)
{
    digits = number.GetDigits();
    sign = number.GetSign();
}

LongInteger::LongInteger(const string&& number)
{
    if (number.size() == 0)
    {
        sign = true;
        digits = "0";
    }
    else
    {
        sign = true;
        digits = number;
        if (number[0] == '+' || number[0] == '-')
        {
            if (number.size() == 1)
            {
                digits = "0";
                return;
            }

            if (number[0] == '-')
                sign = false;

            digits.erase(digits.begin());
        }

        unsigned int size = digits.size();
        for (unsigned int i = 0; i < size; i++)
            if (digits[i] < '0' || digits[i] > '9')
            {
                sign = true;
                digits = "0";
                return;
            }

        unsigned i = 0, zerosNumber = 0;
        while (i < size)
        {
            if (digits[i] != '0')
                break;
            i++;
            zerosNumber++;
        }

        if (zerosNumber != 0)
        {
            if (zerosNumber == size)
            {
                digits.erase(0, zerosNumber - 1);
                sign = true;
            }
            else
                digits.erase(0, zerosNumber);
        }
    }
}

LongInteger::LongInteger(const string& number)
{
    if (number.size() == 0)
    {
        sign = true;
        digits = "0";
    }
    else
    {
        sign = true;
        digits = number;
        if (number[0] == '+' || number[0] == '-')
        {
            if (number.size() == 1)
            {
                digits = "0";
                return;
            }

            if (number[0] == '-')
                sign = false;

            digits.erase(digits.begin());
        }

        unsigned int size = digits.size();
        for (unsigned int i = 0; i < size; i++)
            if (digits[i] < '0' || digits[i] > '9')
            {
                sign = true;
                digits = "0";
                return;
            }

        unsigned i = 0, zerosNumber = 0;
        while (i < size)
        {
            if (digits[i] != '0')
                break;
            i++;
            zerosNumber++;
        }

        if (zerosNumber != 0)
        {
            if (zerosNumber == size)
            {
                digits.erase(0, zerosNumber - 1);
                sign = true;
            }
            else
                digits.erase(0, zerosNumber);
        }
    }
}

const string& LongInteger::GetDigits() const
{
    return digits;
}

bool LongInteger::GetSign() const
{
    return sign;
}

LongInteger& LongInteger::operator=(const LongInteger& number)
{
    this->digits = number.GetDigits();
    this->sign = number.GetSign();

    return *this;
}

bool LongInteger::operator==(const LongInteger& number) const
{
    if (sign != number.GetSign())
        return false;

    if (digits.size() != number.GetDigits().size())
        return false;

    unsigned int size = digits.size();
    const string& d = number.GetDigits();
    for (unsigned int i = 0; i < size; i++)
        if (digits[i] != d[i])
            return false;

    return true;
}

bool LongInteger::operator!=(const LongInteger& number) const
{
    return !(*this == number);
}

bool LongInteger::operator>(const LongInteger& number) const
{
    if (sign && !number.GetSign())
        return true;
    if (!sign && number.GetSign())
        return false;

    if (digits.size() > number.GetDigits().size())
    {
        if (sign)
            return true;
        else
            return false;
    }

    if (digits.size() < number.GetDigits().size())
    {
        if (sign)
            return false;
        else
            return true;
    }

    unsigned int size = digits.size();
    const string& d = number.GetDigits();
    for (int i = 0; i < size; ++i)
        if (digits[i] != d[i])
        {
            if (digits[i] > d[i])
                if (sign)
                    return true;
                else
                    return false;
            else
                if (sign)
                    return false;
                else
                    return true;
        }

    return false;
}

bool LongInteger::operator<(const LongInteger& number) const
{
    return !(*this > number);
}

bool LongInteger::operator>=(const LongInteger& number) const
{
    if (*this > number)
    {
        return true;
    }
    else
    {
        return *this == number;
    }
}

bool LongInteger::operator<=(const LongInteger& number) const
{
    if (*this < number)
    {
        return true;
    }
    else
    {
        return *this == number;
    }
}

void LongInteger::SetSign(bool value)
{
    sign = value;
}

LongInteger LongInteger::operator-() const
{
    LongInteger a(*this);
    a.SetSign(!sign);

    return a;
}

LongInteger::operator bool() const
{
    if (*this != 0)
        return true;
    else
        return false;
}

bool LongInteger::operator!() const
{
    if (*this == 0)
        return true;
    else
        return false;
}

