#include <iostream>
#include <sstream>
#include "Complex.h"
using namespace std;

Complex::Complex() 
  : m_real(1.0), m_imag(0.0)
{ /* Empty constructor body */ }

// ------- NON-DEFAULT CONSTRUCTOR --------
Complex::Complex(double re, double im){
  m_real = re;
  m_imag = im;
}

double Complex::GetReal() const {
  return m_real;
}

double Complex::GetImag() const {
  return m_imag;
}

Complex Complex::Add(Complex a) const {
  return Complex(m_real + a.GetReal(), m_imag + a.GetImag());
}

// -------- IMPLEMENTATIONS OF Multiply() GO HERE --------

// Mutiply() - Multiply two complex numbers together
Complex Complex::Multiply(Complex a) const {
  return Complex(m_real * a.GetReal() - m_imag * a.GetImag(), m_real * a.GetImag() + m_imag * a.GetReal());  
}

// Multiply() - Multiply complex number by a double
Complex Complex::Multiply(double re) const {
  return Complex(m_real * re, m_imag * re);
}

string Complex::ToString() const {
  stringstream ss;
  if (m_imag > 0) 
    ss << m_real << " + " << m_imag << " i";
  else if (m_imag < 0)
    ss << m_real << " - " << -m_imag << " i";
  else
    ss << m_real;
  return ss.str();
}
