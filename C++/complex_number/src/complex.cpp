#include <iostream>
#include <math.h>
#include "complex.h"

Complex::Complex()
{
    real_part = 0;
    imag_part = 0;
    polar_magnitude = 0;
    polar_angle = 0;
}

Complex::Complex(double arg_r_m, double arg_i_a, 
                 TYPE const &type = TYPE::RECTANGULAR_FORM)
{
    if(TYPE::POLAR_FORM == type)
    {
        polar_magnitude = arg_r_m;
        polar_angle = correct_angle(arg_i_a);
        calc_rect();
    }
    else
    {
        real_part = arg_r_m;
        imag_part = arg_i_a;
        calc_polar();
    }
}

void Complex::get_value
(double arg_r_m, double arg_i_a, TYPE const &type = TYPE::RECTANGULAR_FORM)
{
    if(TYPE::POLAR_FORM == type)
    {
        polar_magnitude = arg_r_m;
        polar_angle = correct_angle(arg_i_a);
        calc_rect();
    }
    else
    {
        real_part = arg_r_m;
        imag_part = arg_i_a;
        calc_polar();
    }
}

double Complex::correct_angle(double arg_angle)
{
    while((arg_angle < -360.0) && (arg_angle > 360.0))
    {
        arg_angle /= 360.0;
    }
    if(arg_angle < 0)
    {
        return (360.0 - arg_angle);
    }
    else
    {
        return arg_angle;
    }

}

void Complex::calc_polar()
{
    polar_magnitude = sqrt((real_part * real_part) + (imag_part * imag_part));
    double radians = acos(real_part / polar_magnitude);
    polar_angle = (radians * 180.0) / M_PI;
}

void Complex::calc_rect()
{
    double radians = (polar_angle * M_PI)/ 180.0;
    real_part = polar_magnitude * cos(radians);
    imag_part = polar_magnitude * sin(radians);
}

Complex Complex::operator+(Complex const &other)
{
    double result_real = real_part + other.real_part;
    double result_imag = imag_part + other.imag_part;

    std::cout << "real: " << result_real << "\n";
    std::cout << "imag: " << result_imag << "\n";

    return Complex(result_real, result_imag, TYPE::RECTANGULAR_FORM);
}

Complex Complex::operator-(Complex const &other)
{
    double result_real = real_part - other.real_part;
    double result_imag = imag_part - other.imag_part;

    return Complex(result_real, result_imag, TYPE::RECTANGULAR_FORM);
}

Complex Complex::operator*(Complex const &other)
{
    double result_mag = polar_magnitude * other.polar_magnitude;
    double result_angle = polar_angle + other.polar_angle;

    return Complex(result_mag, result_angle, TYPE::POLAR_FORM);
}

Complex Complex::operator/(Complex const &other)
{
    double result_mag = polar_magnitude / other.polar_magnitude;
    double result_angle = polar_angle - other.polar_angle;

    return Complex(result_mag, result_angle, TYPE::POLAR_FORM);
}

bool Complex::operator==(Complex const &other)
{
    if((real_part == other.real_part) && (imag_part == other.imag_part))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream & operator<<(std::ostream &out, Complex const &other)
{
    if(0 <= other.imag_part)
    {
        out << other.real_part << "+j" << other.imag_part;
    }
    else
    {
        out << other.real_part << "-j" << other.imag_part;
    }

    return out;
}

std::istream & operator>>(std::istream &in, Complex &other)
{
    in >> other.real_part >> other.imag_part;

    return in;
}