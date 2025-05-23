#ifndef OPERACION_POLIMORFISMO_H
#define OPERACION_POLIMORFISMO_H

#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

class OperacionPolimorfismo
{
protected:
    double a, b;

public:
    OperacionPolimorfismo(double x = 0, double y = 0) : a(x), b(y) {}
    virtual ~OperacionPolimorfismo() = default;
    virtual double calcular() const = 0;
    virtual std::string getTipo() const = 0;

    virtual void mostrarOperacion() const
    {
        std::cout << getTipo() << "(" << a << ", " << b << ") = " << calcular() << std::endl;
    }

    virtual bool esValida() const
    {
        return true;
    }

    void setOperandos(double x, double y)
    {
        a = x;
        b = y;
    }

    double getA() const { return a; }
    double getB() const { return b; }
};

class SumaPolimorfismo : public OperacionPolimorfismo
{
public:
    SumaPolimorfismo(double x = 0, double y = 0) : OperacionPolimorfismo(x, y) {}

    double calcular() const override
    {
        return a + b;
    }

    std::string getTipo() const override
    {
        return "Suma";
    }

    void mostrarOperacion() const override
    {
        std::cout << "Suma polimórfica: " << a << " + " << b << " = " << calcular() << std::endl;
    }
};

class RestaPolimorfismo : public OperacionPolimorfismo
{
public:
    RestaPolimorfismo(double x = 0, double y = 0) : OperacionPolimorfismo(x, y) {}

    double calcular() const override
    {
        return a - b;
    }

    std::string getTipo() const override
    {
        return "Resta";
    }

    void mostrarOperacion() const override
    {
        std::cout << "Resta polimórfica: " << a << " - " << b << " = " << calcular() << std::endl;
    }
};

class MultiplicacionPolimorfismo : public OperacionPolimorfismo
{
public:
    MultiplicacionPolimorfismo(double x = 0, double y = 0) : OperacionPolimorfismo(x, y) {}

    double calcular() const override
    {
        return a * b;
    }

    std::string getTipo() const override
    {
        return "Multiplicación";
    }

    void mostrarOperacion() const override
    {
        std::cout << "Multiplicación polimórfica: " << a << " × " << b << " = " << calcular() << std::endl;
    }
};

class DivisionPolimorfismo : public OperacionPolimorfismo
{
public:
    DivisionPolimorfismo(double x = 0, double y = 0) : OperacionPolimorfismo(x, y) {}

    double calcular() const override
    {
        if (!esValida())
        {
            throw std::runtime_error("División por cero");
        }
        return a / b;
    }

    std::string getTipo() const override
    {
        return "División";
    }

    bool esValida() const override
    {
        return b != 0;
    }

    void mostrarOperacion() const override
    {
        if (esValida())
        {
            std::cout << "División polimórfica: " << a << " ÷ " << b << " = " << calcular() << std::endl;
        }
        else
        {
            std::cout << "División polimórfica: " << a << " ÷ " << b << " = ERROR (división por cero)" << std::endl;
        }
    }
};

class CalculadoraPolimorfica
{
private:
    std::vector<std::unique_ptr<OperacionPolimorfismo>> operaciones;

public:
    void agregarOperacion(std::unique_ptr<OperacionPolimorfismo> op)
    {
        operaciones.push_back(std::move(op));
    }

    void ejecutarTodas() const
    {
        std::cout << "\nDemostración de Polimorfismo" << std::endl;
        for (const auto &op : operaciones)
        {
            op->mostrarOperacion();
        }
    }

    void ejecutarOperacion(size_t indice, double a, double b)
    {
        if (indice < operaciones.size())
        {
            operaciones[indice]->setOperandos(a, b);
            operaciones[indice]->mostrarOperacion();
        }
    }
};

#endif