# Makefile para Dungeon Killer - OOP Edition (Completo)
# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = dungeon_killer_oo

# Arquivos fonte (sistema OOP completo)
SRC_FILES = \
	main.cpp \
	GameManager.cpp \
	GameObject.cpp \
	Personagem.cpp \
	Efeito.cpp \
	EfeitoForca.cpp \
	PersonagemJogavel.cpp \
	PersonagemInimigo.cpp \
	ASCII_Engine/Sprite.cpp \
	ASCII_Engine/SpriteAnimado.cpp \
	ASCII_Engine/TextSprite.cpp \
	ASCII_Engine/SpriteBuffer.cpp \
	ASCII_Engine/Fase.cpp \
	ASCII_Engine/ObjetoDeJogo.cpp

# Arquivos objeto
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Regra principal
all: $(TARGET)

# Compilar o executável
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)
	@echo "Compilacao concluida! Executavel: $(TARGET)"

# Regras para compilar arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependências específicas
GameManager.o: GameManager.hpp PersonagemJogavel.hpp PersonagemInimigo.hpp EfeitoForca.hpp
GameObject.o: GameObject.hpp
Personagem.o: Personagem.hpp GameObject.hpp Efeito.hpp
Efeito.o: Efeito.hpp
EfeitoForca.o: EfeitoForca.hpp Efeito.hpp Personagem.hpp
PersonagemJogavel.o: PersonagemJogavel.hpp Personagem.hpp
PersonagemInimigo.o: PersonagemInimigo.hpp Personagem.hpp

# Limpar arquivos compilados
clean:
	rm -f $(OBJ_FILES) $(TARGET)
	@echo "Arquivos de compilacao removidos!"

# Executar o jogo
run: $(TARGET)
	@echo "Executando Dungeon Killer - OOP Edition..."
	./$(TARGET)

# Mostrar informações do projeto
info:
	@echo "DUNGEON KILLER - OOP Edition (Completo)"
	@echo "Diretorio fonte: . + ASCII_Engine/"
	@echo "Compilador: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@echo "Executavel: $(TARGET)"
	@echo "Arquivos fonte: $(words $(SRC_FILES))"
	@echo ""
	@echo "Arquitetura OOP implementada:"
	@echo "   • ENCAPSULAMENTO: Atributos privados, metodos publicos"
	@echo "   • HERANCA: GameObject → Personagem → PersonagemJogavel/PersonagemInimigo"
	@echo "   • POLIMORFISMO: Metodos virtuais e sistema de efeitos"
	@echo "   • ABSTRACAO: Classes abstratas e interfaces"
	@echo ""
	@echo "Utilizando ASCII_ENGINE para renderizacao!"
	@echo "Jogo de combate por turnos funcional e jogavel!"

# Ajuda
help:
	@echo "DUNGEON KILLER - Makefile (OOP Completo)"
	@echo ""
	@echo "Comandos disponiveis:"
	@echo "  make        - Compilar o projeto"
	@echo "  make clean  - Limpar arquivos compilados"
	@echo "  make run    - Compilar e executar o jogo"
	@echo "  make info   - Mostrar informacoes do projeto"
	@echo "  make help   - Mostrar esta ajuda"
	@echo ""
	@echo "Requisitos:"
	@echo "  • Compilador C++17 (g++)"
	@echo "  • Sistema Unix/Linux ou Windows com MinGW"
	@echo ""
	@echo "Arquitetura:"
	@echo "  • Sistema OOP completo com 4 pilares"
	@echo "  • ASCII_ENGINE integrada"
	@echo "  • Jogo de combate por turnos funcional"

# Regra .PHONY para comandos que não geram arquivos
.PHONY: all clean run info help
