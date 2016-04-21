#pragma once
#include <exception>

template <int d>
class Z
{
public:
    Z() : val{0}
    {
    }

    Z(int v)
    {
        if (v >= 0)
        {
            val = v % d;
        }
        else
        {
            while (v < 0) v += d;
            val = v;
        }
    }

    Z(const Z& z)
    {
        val = z.val;
    }

    Z(Z&& z)
    {
        val = z.val;
    }

    Z& operator=(const Z& rhs) = default;
    Z& operator=(Z&& rhs) = default;

    operator int ()
    {
        return val;
    }

    Z operator+(Z rhs)
    {
        return Z((val + rhs.val > d)? val + rhs.val - d : val + rhs.val);
    }

    Z operator*(Z rhs)
    {
        return Z(val * rhs.val);
    }

    Z operator-(Z rhs)
    {
        return Z(val - rhs.val);
    }

    Z operator/(Z rhs);

private:
    int val;
};

template <>
Z<2> Z<2>::operator/(Z<2> rhs)
{
    if (rhs.val == 0)
        throw std::logic_error{"division by 0"};
    else
        return Z<2>(1);
}

template<int d>
Z<d> Z<d>::operator/(Z<d> rhs)
{
    int i = 0;
    Z<d> inv{1};
    while (i++ < d - 2) inv = inv * rhs;
    return *this * inv;
}
