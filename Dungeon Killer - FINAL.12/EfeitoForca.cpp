#include "EfeitoForca.hpp"
#include "Personagem.hpp"
#include <iostream>

EfeitoForca::EfeitoForca(int _bonusForca, int _duracao)
    : Efeito("Pocao de Forca", "Aumenta a forca temporariamente", _duracao),
      bonusForca(_bonusForca), forcaOriginal(0) {
}

void EfeitoForca::aplicar(Personagem* alvo) {
    if (!alvo) return;
    
    forcaOriginal = alvo->getForca();
    alvo->setForca(forcaOriginal + bonusForca);
    
    std::cout << alvo->getNome() << " ganhou " << bonusForca << " pontos de forca!" << std::endl;
}

void EfeitoForca::remover(Personagem* alvo) {
    if (!alvo) return;
    
    alvo->setForca(forcaOriginal);
    std::cout << alvo->getNome() << " perdeu o bonus de forca!" << std::endl;
}

void EfeitoForca::atualizar(Personagem* alvo) {
    // Diminuir duração a cada turno
    diminuirDuracao();
    
    // Se expirou, remover o efeito
    if (expirou()) {
        remover(alvo);
    }
}
