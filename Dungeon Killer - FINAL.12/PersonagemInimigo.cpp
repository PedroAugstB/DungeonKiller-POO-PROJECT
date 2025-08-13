#include "PersonagemInimigo.hpp"
#include <iostream>

PersonagemInimigo::PersonagemInimigo(const std::string& _nome, const std::string& _tipo,
                                     int _posX, int _posY, int _vida, int _forca,
                                     int _defesa, int _velocidade, int _recompensaExp, int _recompensaOuro)
    : Personagem(_nome, _posX, _posY, _vida, _forca, _defesa, _velocidade),
      tipo(_tipo), recompensaExperiencia(_recompensaExp), recompensaOuro(_recompensaOuro) {
}

void PersonagemInimigo::atacar(Personagem* alvo) {
    if (!alvo || !alvo->estaVivo() || !vivo) return;
    
    int dano = forca;
    alvo->receberDano(dano);
    
    std::cout << nome << " atacou " << alvo->getNome() << " causando " << dano << " de dano!" << std::endl;
}

void PersonagemInimigo::usarHabilidade() {
    // Inimigos têm habilidades mais simples
    if (vida < vidaMaxima / 2) {
        // Curar quando vida baixa
        curar(15);
        std::cout << nome << " usou habilidade de cura!" << std::endl;
    }
}

void PersonagemInimigo::escolherAcao(Personagem* jogador) {
    if (!jogador || !jogador->estaVivo() || !vivo) return;
    
    // Decisão simples baseada na vida
    if (vida < vidaMaxima / 3) {
        // Vida baixa - tentar curar
        usarHabilidade();
    } else {
        // Vida ok - atacar
        atacar(jogador);
    }
}
