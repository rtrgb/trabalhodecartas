# Compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Arquivos
SRC = main.cpp
OUT = main

# Compilação padrão
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

# Limpar o executável
clean:
	rm -f $(OUT)
