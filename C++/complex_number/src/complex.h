#ifndef COMPLEX_H
#define COMPLEX_H

enum class TYPE {RECTANGULAR_FORM, POLAR_FORM};

class Complex
{
        double real_part;
        double imag_part;
        double polar_magnitude;
        double polar_angle;

        void calc_polar();
        void calc_rect();

        double correct_angle(double);

    public:
        Complex();
        Complex(double, double, TYPE const &);

        void get_value(double, double, TYPE const &);

        Complex operator+(Complex const &);
        Complex operator-(Complex const &);
        Complex operator*(Complex const &);
        Complex operator/(Complex const &);
        bool operator==(Complex const &);
        friend std::ostream & operator<<(std::ostream &, Complex const &);
        friend std::istream & operator>>(std::istream &, Complex &);

        void polar();
        void rect();
};

inline void Complex::polar()
{
    std::cout << polar_magnitude << "/_" << polar_angle;
}

inline void Complex::rect()
{
    if (imag_part >= 0)
    {
        std::cout << real_part << " + j" << imag_part;
    }
    else
    {
        std::cout << real_part << " - j" << -imag_part;
    }
}

#endif
