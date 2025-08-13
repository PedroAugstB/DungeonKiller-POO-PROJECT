#ifndef EFEITOFORCA_HPP
#define EFEITOFORCA_HPP

#include "Efeito.hpp"

// Efeito concreto que aumenta a força - demonstra POLIMORFISMO
class EfeitoForca : public Efeito {
private:
    int bonusForca;
    int forcaOriginal;

public:
    EfeitoForca(int _bonusForca, int _duracao);
    
    // Implementação dos métodos virtuais
    void aplicar(class Personagem* alvo) override;
    void remover(class Personagem* alvo) override;
    void atualizar(class Personagem* alvo) override;
    
    // Getter
    int getBonusForca() const { return bonusForca; }
};

#endif // EFEITOFORCA_HPP
