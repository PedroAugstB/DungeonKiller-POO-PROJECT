#include "Personagem.hpp"
#include "Efeito.hpp"
#include <iostream>
#include <algorithm>

Personagem::Personagem(const std::string& _nome, int _posX, int _posY, 
                       int _vida, int _forca, int _defesa, int _velocidade)
    : GameObject(_nome, _posX, _posY), 
      vida(_vida), vidaMaxima(_vida), forca(_forca), defesa(_defesa), 
      velocidade(_velocidade), vivo(true) {
}

void Personagem::atualizar() {
    if (!ativo || !vivo) return;
    
    // Atualizar efeitos
    removerEfeitosExpirados();
    
    // Aplicar efeitos ativos
    for (auto& efeito : efeitos) {
        if (efeito->estaAtivo()) {
            efeito->atualizar(this);
        }
    }
}

void Personagem::receberDano(int dano) {
    if (!vivo) return;
    
    int danoFinal = std::max(1, dano - defesa);
    vida -= danoFinal;
    
    if (vida <= 0) {
        vida = 0;
        vivo = false;
        std::cout << nome << " foi derrotado!" << std::endl;
    } else {
        std::cout << nome << " recebeu " << danoFinal << " pontos de dano!" << std::endl;
    }
}

void Personagem::curar(int quantidade) {
    if (!vivo) return;
    
    vida = std::min(vidaMaxima, vida + quantidade);
    std::cout << nome << " foi curado em " << quantidade << " pontos de vida!" << std::endl;
}

void Personagem::adicionarEfeito(std::unique_ptr<Efeito> efeito) {
    efeitos.push_back(std::move(efeito));
}

void Personagem::removerEfeitosExpirados() {
    efeitos.erase(
        std::remove_if(efeitos.begin(), efeitos.end(),
            [](const std::unique_ptr<Efeito>& efeito) {
                return efeito->expirou();
            }),
        efeitos.end()
    );
}

void Personagem::setVida(int _vida) {
    vida = std::max(0, std::min(vidaMaxima, _vida));
    if (vida <= 0) {
        vivo = false;
    }
}

void Personagem::setForca(int _forca) {
    forca = std::max(1, _forca);
}

void Personagem::setDefesa(int _defesa) {
    defesa = std::max(0, _defesa);
}

void Personagem::setVelocidade(int _velocidade) {
    velocidade = std::max(1, _velocidade);
}
