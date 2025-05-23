CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2

DEMO_OOP = act_7.cpp
MAIN_ORIGINAL = main.cpp

DEMO_OOP_EXE = act_7
MAIN_ORIGINAL_EXE = main_original

HEADERS = operacion_abstracta.h operacion_herencia.h operacion_polimorfismo.h

.PHONY: all clean demo original help

all: demo

demo: $(DEMO_OOP_EXE)

$(DEMO_OOP_EXE): $(DEMO_OOP) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $<

original: $(MAIN_ORIGINAL_EXE)

$(MAIN_ORIGINAL_EXE): $(MAIN_ORIGINAL)
	$(CXX) $(CXXFLAGS) -o $@ $<

run-demo: demo
	@echo "Ejecutando demostración de Programación Orientada a Objetos..."
	./$(DEMO_OOP_EXE)

run-original: original
	@echo "Ejecutando programa original..."
	./$(MAIN_ORIGINAL_EXE)

clean:
	rm -f $(DEMO_OOP_EXE) $(MAIN_ORIGINAL_EXE)

help:
	@echo "Objetivos disponibles:"
	@echo "  demo       - Compilar la demostración de POO"
	@echo "  run-demo   - Compilar y ejecutar la demostración"
	@echo "  clean      - Limpiar archivos compilados" 