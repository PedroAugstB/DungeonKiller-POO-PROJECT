# DUNGEON KILLER - OOP Edition (Completo)

**Um jogo de RPG por turnos desenvolvido em C++ para demonstrar os 4 pilares da Orientação a Objetos de forma prática e interativa, utilizando a ASCII_ENGINE para renderização!**

## 🏗️ **ARQUITETURA OOP IMPLEMENTADA**

### 1. **ENCAPSULAMENTO** 🛡️
- **Atributos privados**: Todos os dados dos personagens são protegidos
- **Métodos públicos controlados**: Acesso através de getters e setters
- **Controle de estado**: Validação de dados e proteção contra modificações inválidas
- **Exemplo**: `Personagem::vida` é privado, acessível apenas via `getVida()` e `setVida()`

### 2. **HERANÇA** 👑
- **Hierarquia de classes**: `GameObject` → `Personagem` → `PersonagemJogavel`/`PersonagemInimigo`
- **Reutilização de código**: Funcionalidades comuns na classe base
- **Especialização**: Cada subclasse adiciona comportamentos específicos
- **Exemplo**: `PersonagemJogavel` herda de `Personagem` e adiciona sistema de mana

### 3. **POLIMORFISMO** 🔄
- **Métodos virtuais**: Comportamentos diferentes para diferentes tipos
- **Interfaces comuns**: Mesma interface, implementações diferentes
- **Runtime binding**: Seleção de método em tempo de execução
- **Sistema de efeitos**: `Efeito` base com implementações específicas como `EfeitoForca`
- **Exemplo**: `Personagem::atacar()` tem implementações diferentes para jogador e inimigos

### 4. **ABSTRAÇÃO** 🎯
- **Classes abstratas**: `GameObject`, `Personagem`, `Efeito`
- **Interfaces**: Métodos virtuais puros forçam implementação
- **Separação de conceitos**: Lógica de jogo separada da lógica de personagens
- **Exemplo**: `GameManager` coordena o jogo, `Personagem` gerencia atributos

## 🎮 **FUNCIONALIDADES DO JOGO**

### **Sistema de Personagens**
- **3 Classes Jogáveis**: Guerreiro, Mago, Arqueiro
- **Sistema de Atributos**: Vida, Força, Velocidade, Defesa, Mana
- **Progressão**: Sistema de experiência e níveis
- **Habilidades Únicas**: Cada classe tem habilidades específicas

### **Sistema de Combate**
- **Combate por Turnos**: Baseado na velocidade dos personagens
- **Ações Disponíveis**: Atacar, Usar Habilidade, Defender, Curar
- **IA dos Inimigos**: Comportamento automático inteligente
- **Sistema de Efeitos**: Buffs, debuffs e status temporários

### **Sistema de Efeitos**
- **Efeitos Temporários**: Poções de força, cura, etc.
- **Duração**: Efeitos expiram automaticamente
- **Aplicação/Remoção**: Sistema polimórfico de efeitos
- **Exemplo**: `EfeitoForca` aumenta temporariamente a força do personagem

### **Interface ASCII**
- **ASCII_ENGINE Integrada**: Renderização usando sprites de texto
- **Sprites Dinâmicos**: Personagens representados por caracteres ASCII
- **Posicionamento**: Sistema de coordenadas X,Y para posicionamento
- **Renderização**: Cada tipo de personagem tem sprite único

## 🚀 **COMO JOGAR**

### **1. Iniciar o Jogo**
```bash
# Compilar
make

# Executar
make run
```

### **2. Menu Principal**
- **Novo Jogo**: Criar personagem e começar aventura
- **Iniciar Combate**: Começar batalha com personagem existente
- **Mostrar Status**: Ver informações do jogo atual
- **Créditos**: Ver informações do projeto
- **Sair**: Finalizar o jogo

### **3. Criação de Personagem**
- **Escolha sua Classe**: Guerreiro (tank), Mago (dano mágico), Arqueiro (dano à distância)
- **Atributos Balanceados**: Cada classe tem pontos fortes e fracos
- **Habilidades Iniciais**: Conjunto básico de habilidades para começar

### **4. Combate**
- **Seu Turno**: Escolha entre 4 ações disponíveis
- **Ações dos Inimigos**: IA executa automaticamente
- **Estratégia**: Use habilidades, cure quando necessário, defenda em momentos críticos
- **Efeitos**: Use poções e itens para vantagens temporárias

## 🛠️ **COMPILAÇÃO E EXECUÇÃO**

### **Requisitos**
- **Compilador**: GCC/G++ com suporte a C++17
- **Sistema**: Windows, Linux ou macOS
- **Dependências**: Apenas bibliotecas padrão do C++

### **Compilação com Make**
```bash
make          # Compilar o projeto
make clean    # Limpar arquivos compilados
make run      # Compilar e executar
make info     # Mostrar informações do projeto
make help     # Mostrar ajuda
```

### **Compilação Manual**
```bash
g++ -std=c++17 -Wall -Wextra -O2 -o dungeon_killer_oo \
    main.cpp GameManager.cpp GameObject.cpp Personagem.cpp \
    Efeito.cpp EfeitoForca.cpp PersonagemJogavel.cpp PersonagemInimigo.cpp \
    ASCII_Engine/*.cpp
```

## 📁 **ESTRUTURA DO PROJETO**

```
Dungeon Killer - FINAL.7/
├── main.cpp                # Ponto de entrada do programa
├── GameManager.hpp/cpp     # Gerenciador principal do jogo
├── GameObject.hpp/cpp      # Classe base abstrata
├── Personagem.hpp/cpp      # Classe base para personagens
├── PersonagemJogavel.hpp/cpp  # Personagens controlados pelo jogador
├── PersonagemInimigo.hpp/cpp  # IA dos inimigos
├── Efeito.hpp/cpp          # Sistema base de efeitos
├── EfeitoForca.hpp/cpp     # Efeito concreto de força
├── ASCII_Engine/           # Engine ASCII e classes de renderização
│   ├── SpriteBase.hpp      # Classe base para sprites
│   ├── Sprite.hpp/cpp      # Sprite estático
│   ├── SpriteAnimado.hpp/cpp # Sprite animado
│   ├── TextSprite.hpp/cpp  # Sprite de texto
│   ├── SpriteBuffer.hpp/cpp # Buffer de sprites
│   ├── Fase.hpp/cpp        # Sistema de fases
│   └── ObjetoDeJogo.hpp/cpp # Objetos de jogo base
├── Makefile               # Sistema de build
├── README.md              # Esta documentação
└── dungeon_killer_oo.exe  # Executável compilado
```

## 🎯 **PADRÕES DE PROJETO IMPLEMENTADOS**

### **Strategy Pattern**
- Diferentes tipos de efeitos com mesma interface
- Fácil adição de novos efeitos sem modificar código existente

### **Template Method Pattern**
- Estrutura comum em classes base
- Subclasses implementam comportamentos específicos

### **Factory Pattern**
- Criação de personagens por tipo
- Encapsulamento da lógica de criação

### **Observer Pattern**
- Sistema de efeitos notifica personagens
- Atualização automática de status

## ✨ **BOAS PRÁTICAS IMPLEMENTADAS**

- **Separação de Responsabilidades**: Cada classe tem uma função específica
- **Baixo Acoplamento**: Classes dependem de interfaces, não implementações
- **Alta Coesão**: Métodos relacionados ficam na mesma classe
- **Open/Closed Principle**: Aberto para extensão, fechado para modificação
- **Smart Pointers**: Uso de `std::unique_ptr` para gerenciamento automático de memória
- **Const Correctness**: Métodos const onde apropriado
- **Exception Safety**: Tratamento adequado de erros

## 🚀 **POSSÍVEIS EXTENSÕES**

- **Sistema de Inventário**: Equipamentos e itens
- **Missões Personalizadas**: Editor de missões
- **Multiplayer Local**: Combate entre jogadores
- **Sistema de Crafting**: Criação de itens
- **Salvamento em Arquivo**: Persistência de dados
- **Interface Gráfica**: Versão com gráficos 2D
- **Sistema de Som**: Efeitos sonoros ASCII

## 🎓 **OBJETIVOS DE APRENDIZADO**

Este projeto demonstra:
- **Implementação prática** dos conceitos teóricos de OOP
- **Arquitetura de software** escalável e manutenível
- **Design patterns** comuns em desenvolvimento de jogos
- **Boas práticas** de programação C++ moderno
- **Sistema de jogo** completo e funcional
- **Integração com engine** de renderização
- **Uso de recursos C++17** como smart pointers e auto

## 🔧 **TECNOLOGIAS UTILIZADAS**

- **C++17**: Linguagem principal com recursos modernos
- **ASCII_ENGINE**: Sistema de renderização em texto
- **Smart Pointers**: Gerenciamento automático de memória
- **STL**: Containers e algoritmos da biblioteca padrão
- **Virtual Functions**: Sistema de polimorfismo
- **Inheritance**: Hierarquia de classes
- **Encapsulation**: Proteção de dados

## 📝 **LICENÇA**

Projeto desenvolvido para fins educacionais, demonstrando os conceitos de Orientação a Objetos de forma prática e interativa, com integração completa da ASCII_ENGINE.

---

**🎮 Divirta-se explorando os 4 pilares da OOP em um jogo real e funcional com ASCII_ENGINE!**

**Desenvolvido para demonstrar os 4 pilares da orientação a objetos de forma prática e interativa! 🎮✨**
