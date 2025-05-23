#ifndef OPERACION_ABSTRACTA_H
#define OPERACION_ABSTRACTA_H

#include <iostream>
#include <stdexcept>

class OperacionAbstracta
{
public:
    virtual double ejecutar(double a, double b) = 0;
    virtual const char *getNombre() const = 0;
    virtual ~OperacionAbstracta() = default;

    void mostrarResultado(double a, double b)
    {
        double resultado = ejecutar(a, b);
        std::cout << getNombre() << "(" << a << ", " << b << ") = " << resultado << std::endl;
    }
};

class SumaAbstracta : public OperacionAbstracta
{
public:
    double ejecutar(double a, double b) override
    {
        return a + b;
    }

    const char *getNombre() const override
    {
        return "Suma";
    }
};

class RestaAbstracta : public OperacionAbstracta
{
public:
    double ejecutar(double a, double b) override
    {
        return a - b;
    }

    const char *getNombre() const override
    {
        return "Resta";
    }
};

class MultiplicacionAbstracta : public OperacionAbstracta
{
public:
    double ejecutar(double a, double b) override
    {
        return a * b;
    }

    const char *getNombre() const override
    {
        return "Multiplicación";
    }
};

class DivisionAbstracta : public OperacionAbstracta
{
public:
    double ejecutar(double a, double b) override
    {
        if (b == 0)
        {
            throw std::invalid_argument("División por cero no permitida");
        }
        return a / b;
    }

    const char *getNombre() const override
    {
        return "División";
    }
};

#endif