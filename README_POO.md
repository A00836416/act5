# Implementaciones de Programación Orientada a Objetos

Este proyecto demuestra la implementación de operaciones matemáticas básicas (suma, resta, multiplicación y división) utilizando tres conceptos fundamentales de la Programación Orientada a Objetos.

## Conceptos Implementados

### 3. Abstracción (`operacion_abstracta.h`)

La **abstracción** se demuestra através de:

- **Clase abstracta `OperacionAbstracta`**: Define la interfaz común para todas las operaciones
- **Métodos virtuales puros**: `ejecutar()` y `getNombre()` que deben ser implementados por las clases derivadas
- **Ocultación de detalles**: Las clases derivadas implementan los detalles específicos de cada operación
- **Interfaz común**: Todas las operaciones se pueden usar de la misma manera

**Características principales:**
- Clase base abstracta que no puede ser instanciada
- Métodos virtuales puros que definen el contrato
- Implementaciones concretas para cada operación matemática
- Manejo de errores para división por cero

### 4. Herencia (`operacion_herencia.h`)

La **herencia** se demuestra através de:

- **Clase base `OperacionBase`**: Contiene funcionalidad común a todas las operaciones
- **Clases derivadas**: Heredan propiedades y métodos de la clase base
- **Reutilización de código**: Los métodos comunes se definen una sola vez
- **Especialización**: Las clases derivadas pueden sobrescribir métodos según sus necesidades

**Características principales:**
- Herencia de atributos y métodos comunes
- Sobrescritura de métodos (`override`) en clases derivadas
- Constructores que llaman al constructor de la clase base
- Especialización del comportamiento en la clase `DivisionHerencia`

### 5. Polimorfismo (`operacion_polimorfismo.h`)

El **polimorfismo** se demuestra através de:

- **Métodos virtuales**: Permiten que cada clase implemente su propio comportamiento
- **Polimorfismo en tiempo de ejecución**: El mismo código puede trabajar con diferentes tipos de objetos
- **Interfaces consistentes**: Diferentes clases responden al mismo mensaje de manera diferente
- **Calculadora polimórfica**: Demuestra el uso práctico del polimorfismo

**Características principales:**
- Métodos virtuales para comportamientos específicos
- Polimorfismo através de punteros y referencias base
- Diferentes implementaciones del mismo método
- Manejo polimórfico de errores y validaciones

## Estructura de Archivos

```
operacion_abstracta.h     - Implementación con Abstracción
operacion_herencia.h      - Implementación con Herencia  
operacion_polimorfismo.h  - Implementación con Polimorfismo
demo_oop.cpp             - Programa de demostración
Makefile                 - Script de compilación
README_POO.md           - Este archivo de documentación
```

## Compilación y Ejecución

### Usando Makefile

```bash
# Compilar y ejecutar la demostración
make run-demo

# Compilar solamente
make demo

# Ver ayuda
make help

# Limpiar archivos compilados
make clean
```

### Compilación manual

```bash
# Compilar
g++ -std=c++14 -Wall -Wextra -O2 -o demo_oop demo_oop.cpp

# Ejecutar
./demo_oop
```

## Salida Esperada

El programa de demostración muestra:

1. **Abstracción**: Cómo diferentes clases implementan la misma interfaz
2. **Herencia**: Cómo las clases derivadas heredan y especializan funcionalidad
3. **Polimorfismo**: Cómo el mismo código puede trabajar con diferentes tipos de objetos

Cada sección incluye:
- Explicación del concepto
- Ejemplos prácticos con operaciones matemáticas
- Manejo de casos especiales (como división por cero)
- Demostración de las ventajas de cada concepto

## Conceptos Clave Demostrados

### Abstracción
- Oculta la complejidad de la implementación
- Proporciona una interfaz clara y consistente
- Permite trabajar con conceptos de alto nivel

### Herencia
- Facilita la reutilización de código
- Establece relaciones "es-un" entre clases
- Permite especialización y extensión de funcionalidad

### Polimorfismo
- Permite que el mismo código funcione con diferentes tipos
- Facilita la extensibilidad del sistema
- Reduce el acoplamiento entre componentes

## Ventajas de la Implementación

1. **Mantenibilidad**: Código organizado y fácil de modificar
2. **Reutilización**: Funcionalidad común compartida
3. **Extensibilidad**: Fácil agregar nuevas operaciones
4. **Flexibilidad**: Diferentes implementaciones de la misma interfaz
5. **Robustez**: Manejo adecuado de errores y casos especiales

Este proyecto demuestra cómo los principios de POO mejoran significativamente la estructura y calidad del código comparado con implementaciones procedurales simples. 