#ifndef OPERACION_HERENCIA_H
#define OPERACION_HERENCIA_H

#include <iostream>
#include <stdexcept>
#include <string>

class OperacionBase
{
protected:
    std::string nombreOperacion;
    double operandoA;
    double operandoB;

public:
    OperacionBase(const std::string &nombre) : nombreOperacion(nombre) {}

    void setOperandos(double a, double b)
    {
        operandoA = a;
        operandoB = b;
    }

    double getOperandoA() const { return operandoA; }
    double getOperandoB() const { return operandoB; }
    std::string getNombre() const { return nombreOperacion; }

    virtual bool validarOperandos() const
    {
        return true;
    }

    void mostrarInfo() const
    {
        std::cout << "Operación: " << nombreOperacion
                  << ", Operandos: " << operandoA << " y " << operandoB << std::endl;
    }

    virtual ~OperacionBase() = default;
};

class SumaHerencia : public OperacionBase
{
public:
    SumaHerencia() : OperacionBase("Suma") {}

    double calcular() const
    {
        return operandoA + operandoB;
    }

    void ejecutar()
    {
        if (validarOperandos())
        {
            double resultado = calcular();
            std::cout << nombreOperacion << "(" << operandoA << " + " << operandoB
                      << ") = " << resultado << std::endl;
        }
    }
};

class RestaHerencia : public OperacionBase
{
public:
    RestaHerencia() : OperacionBase("Resta") {}

    double calcular() const
    {
        return operandoA - operandoB;
    }

    void ejecutar()
    {
        if (validarOperandos())
        {
            double resultado = calcular();
            std::cout << nombreOperacion << "(" << operandoA << " - " << operandoB
                      << ") = " << resultado << std::endl;
        }
    }
};

class MultiplicacionHerencia : public OperacionBase
{
public:
    MultiplicacionHerencia() : OperacionBase("Multiplicación") {}

    double calcular() const
    {
        return operandoA * operandoB;
    }

    void ejecutar()
    {
        if (validarOperandos())
        {
            double resultado = calcular();
            std::cout << nombreOperacion << "(" << operandoA << " * " << operandoB
                      << ") = " << resultado << std::endl;
        }
    }
};

class DivisionHerencia : public OperacionBase
{
public:
    DivisionHerencia() : OperacionBase("División") {}

    bool validarOperandos() const override
    {
        if (operandoB == 0)
        {
            std::cout << "Error: División por cero no permitida" << std::endl;
            return false;
        }
        return true;
    }

    double calcular() const
    {
        return operandoA / operandoB;
    }

    void ejecutar()
    {
        if (validarOperandos())
        {
            double resultado = calcular();
            std::cout << nombreOperacion << "(" << operandoA << " / " << operandoB
                      << ") = " << resultado << std::endl;
        }
    }
};

#endif