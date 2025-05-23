/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include <memory>
#include <vector>

#include "operacion_abstracta.h"
#include "operacion_herencia.h"
#include "operacion_polimorfismo.h"

using namespace std;

void demostracionAbstraccion()
{
    cout << "\n Abastraccion" << endl;
    cout << "La abstracción oculta los detalles de implementación y" << endl;
    cout << "proporciona una interfaz común através de clases abstractas." << endl;

    SumaAbstracta suma;
    DivisionAbstracta div;

    double a = 10, b = 3;

    suma.mostrarResultado(a, b);
    div.mostrarResultado(a, b);
}

void demostracionHerencia()
{
    cout << "\n Herencia" << endl;
    cout << "La herencia permite que las clases derivadas hereden" << endl;
    cout << "propiedades y métodos de una clase base." << endl;

    SumaHerencia suma;
    RestaHerencia resta;
    MultiplicacionHerencia mult;
    DivisionHerencia div;

    double a = 15, b = 4;

    cout << "\nConfigurando operandos " << a << " y " << b << " en todas las operaciones:" << endl;

    suma.setOperandos(a, b);
    resta.setOperandos(a, b);
    mult.setOperandos(a, b);
    div.setOperandos(a, b);

    suma.ejecutar();
    resta.ejecutar();
    mult.ejecutar();
    div.ejecutar();

    cout << "\nProbando división por cero (método sobrescrito):" << endl;
    div.setOperandos(10, 0);
    div.ejecutar();

    cout << "\nUsando métodos heredados de la clase base:" << endl;
    suma.setOperandos(7, 3);
    suma.mostrarInfo();
}

void demostracionPolimorfismo()
{
    cout << "\n Polimorfismo" << endl;
    cout << "El polimorfismo permite que objetos de diferentes clases" << endl;
    cout << "respondan de manera diferente al mismo mensaje." << endl;

    CalculadoraPolimorfica calculadora;

    calculadora.agregarOperacion(make_unique<SumaPolimorfismo>(8, 2));
    calculadora.agregarOperacion(make_unique<RestaPolimorfismo>(8, 2));
    calculadora.agregarOperacion(make_unique<MultiplicacionPolimorfismo>(8, 2));
    calculadora.agregarOperacion(make_unique<DivisionPolimorfismo>(8, 2));

    calculadora.ejecutarTodas();

    cout << "\nPolimorfismo con diferentes valores:" << endl;

    vector<unique_ptr<OperacionPolimorfismo>> operaciones;
    operaciones.push_back(make_unique<SumaPolimorfismo>());
    operaciones.push_back(make_unique<RestaPolimorfismo>());
    operaciones.push_back(make_unique<MultiplicacionPolimorfismo>());
    operaciones.push_back(make_unique<DivisionPolimorfismo>());

    for (auto &op : operaciones)
    {
        op->setOperandos(12, 4);
        op->mostrarOperacion();
    }

    cout << "\nPolimorfismo con manejo de errores:" << endl;
    auto divPolim = make_unique<DivisionPolimorfismo>();
    divPolim->setOperandos(10, 0);
    divPolim->mostrarOperacion();
}

int main()
{
    cout << "Implementación de operaciones matemáticas usando:" << endl;
    cout << "1. Abstracción" << endl;
    cout << "2. Herencia" << endl;
    cout << "3. Polimorfismo" << endl;

    try
    {
        demostracionAbstraccion();
        demostracionHerencia();
        demostracionPolimorfismo();

        cout << "\n¡DEMOSTRACIÓN COMPLETADA!" << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error durante la demostración: " << e.what() << endl;
        return 1;
    }

    return 0;
}