#include <cmath>
#include <iostream>

#include "Complex.h"

using namespace std;

/**
 * @brief 
 * @param actualPart 
 * @param imaginaryPart 
*/
Complex::Complex(double actualPart, double imaginaryPart)
{
    actual = actualPart;
    imaginary = imaginaryPart;
}

/**
 * @brief 
 * @param temporaryComplex 
*/
Complex::Complex(const Complex &temporaryComplex)
{
    actual = temporaryComplex.actual;
    imaginary = temporaryComplex.imaginary;
}

/**
 * @brief 
*/
Complex::~Complex()
{
    actual = 0.0;
    imaginary = 0.0;
}

/**
 * @brief 
 * @param actualPart 
 * @param imaginaryPart 
*/
void Complex::set(double actualPart, double imaginaryPart)
{
    actual = actualPart;
    imaginary = imaginaryPart;
}

/**
 * @brief 
*/
Complex::operator double()
{
    return abs();
}

/**
 * @brief 
 * @return 
*/
double Complex::abs()
{
    return sqrt(actual * actual + imaginary * imaginary);
}

/**
 * @brief 
 * @param temporaryComplex 
 * @return 
*/
Complex Complex::operator +(const Complex &temporaryComplex)
{
    Complex result;

    result.actual = actual + temporaryComplex.actual;
    result.imaginary = imaginary + temporaryComplex.imaginary;

    return result;
}

/**
 * @brief 
 * @param temporaryComplex 
 * @return 
*/
Complex Complex::operator -(const Complex &temporaryComplex)
{
    Complex result;

    result.actual = actual - temporaryComplex.actual;
    result.imaginary = imaginary - temporaryComplex.imaginary;

    return result;
}

/**
 * @brief 
 * @param actualPart 
 * @return 
*/
Complex Complex::operator +(const double &actualPart)
{
    Complex result;

    result.actual = actual + actualPart;
    result.imaginary = imaginary;

    return result;
}

/**
 * @brief 
 * @param actualPart 
 * @return 
*/
Complex Complex::operator -(const double &actualPart)
{
    Complex result(*this);

    result.actual = actual - actualPart;

    return result;
}

/**
 * @brief 
 * @param temporaryComplex 
 * @return 
*/
Complex Complex::operator *(const Complex &temporaryComplex)
{
    Complex result;

    result.actual = actual * temporaryComplex.actual - imaginary * temporaryComplex.imaginary;
    result.imaginary = actual * temporaryComplex.imaginary + imaginary * temporaryComplex.actual;

    return result;
}

/**
 * @brief 
 * @param multiplicationValue 
 * @return 
*/
Complex Complex::operator *(const double &multiplicationValue)
{
    Complex result;

    result.actual = actual * multiplicationValue;
    result.imaginary = imaginary * multiplicationValue;

    return result;
}

/**
 * @brief 
 * @param divisionValue 
 * @return 
*/
Complex Complex::operator /(const double &divisionValue)
{
    Complex result;

    result.actual = actual / divisionValue;
    result.imaginary = imaginary / divisionValue;

    return result;
}

/**
 * @brief 
 * @param summaryValue 
 * @return 
*/
Complex& Complex::operator +=(const Complex &summaryValue)
{
    actual += summaryValue.actual;
    imaginary += summaryValue.imaginary;

    return *this;
}

/**
 * @brief 
 * @param differenceValue 
 * @return 
*/
Complex& Complex::operator -=(const Complex &differenceValue)
{
    actual -= differenceValue.actual;
    imaginary -= differenceValue.imaginary;

    return *this;
}

/**
 * @brief 
 * @param multiplicationValue 
 * @return 
*/
Complex& Complex::operator *=(const Complex &multiplicationValue)
{
    double temporaryImaginaryPart = actual;

    actual
			= actual * multiplicationValue.actual - imaginary
			* multiplicationValue.imaginary;
	
    imaginary
			= imaginary * multiplicationValue.actual + temporaryImaginaryPart
			* multiplicationValue.imaginary;

    return *this;
}

/**
 * @brief 
 * @param actualPart 
 * @return 
*/
Complex& Complex::operator +=(const double &actualPart)
{
    actual += actualPart;

    return *this;
}

/**
 * @brief 
 * @param differenceValue 
 * @return 
*/
Complex& Complex::operator -=(const double &differenceValue)
{
    actual -= differenceValue;

    return *this;
}

/**
 * @brief 
 * @param multiplicationValue 
 * @return 
*/
Complex& Complex::operator *=(const double &multiplicationValue)
{
    actual *= multiplicationValue;
    imaginary *= multiplicationValue;

    return *this;
}

/**
 * @brief 
 * @param divisionValue 
 * @return 
*/
Complex& Complex::operator /=(const double &divisionValue)
{
    actual /= divisionValue;
    imaginary /= divisionValue;

    return *this;
}

/**
 * @brief 
 * @param newComplex 
 * @return 
*/
Complex& Complex::operator =(const Complex &newComplex)
{
    actual = newComplex.actual;
    imaginary = newComplex.imaginary;

    return *this;
}

/**
 * @brief 
 * @param newActualPart 
 * @return 
*/
Complex& Complex::operator =(const double &newActualPart)
{
    actual = newActualPart;
    imaginary = 0.0;

    return *this;
}

/**
 * @brief 
 * @param inputStream 
 * @param setComplex 
 * @return 
*/
istream& operator >>(istream &inputStream, Complex &setComplex)
{
    char temporaryBuffer[256];

    inputStream >> setComplex.actual >> setComplex.imaginary >> temporaryBuffer;

    return inputStream;
}

/**
 * @brief 
 * @param outputStream 
 * @param getComplex 
 * @return 
*/
ostream& operator <<(ostream &outputStream, Complex &getComplex)
{
    outputStream << getComplex.actual;

    if (!(getComplex.imaginary < 0)) {
        outputStream << '+';
    }

    outputStream << getComplex.imaginary << 'i';

    return outputStream;
}

/**
 * @brief 
 * @param actualPart 
 * @param temporaryComplex 
 * @return 
*/
Complex operator +(const double &actualPart, const Complex &temporaryComplex)
{
    Complex result;

    result.actual = actualPart + temporaryComplex.actual;
    result.imaginary = temporaryComplex.imaginary;

    return result;
}

/**
 * @brief 
 * @param actualPart 
 * @param temporaryComplex 
 * @return 
*/
Complex operator -(const double &actualPart, const Complex &temporaryComplex)
{
    Complex result;

    result.actual = actualPart - temporaryComplex.actual;
    result.imaginary = -temporaryComplex.imaginary;

    return result;
}

/**
 * @brief 
 * @param multiplicationValue 
 * @param multiplicationComplex 
 * @return 
*/
Complex operator *(const double &multiplicationValue, const Complex &multiplicationComplex)
{
    Complex temporary;
	
	temporary.actual = multiplicationValue * multiplicationComplex.actual;
	temporary.imaginary = multiplicationValue * multiplicationComplex.imaginary;

    return R;
}
