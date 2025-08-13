#include "PersonagemJogavel.hpp"
#include <iostream>

// Criar sprite específico para jogador
PersonagemJogavel::PersonagemJogavel(const std::string& _nome, const std::string& _classe, 
                                     int _posX, int _posY, int _vida, int _forca, 
                                     int _defesa, int _velocidade, int _mana)
    : Personagem(_nome, _posX, _posY, _vida, _forca, _defesa, _velocidade),
      mana(_mana), manaMaxima(_mana), experiencia(0), nivel(1), classe(_classe) {
}

void PersonagemJogavel::atacar(Personagem* alvo) {
    if (!alvo || !alvo->estaVivo() || !vivo) return;
    
    int dano = forca - alvo->getDefesa();
    if (dano < 1) dano = 1;
    
    alvo->receberDano(dano);
    std::cout << nome << " atacou " << alvo->getNome() << " causando " << dano << " de dano!" << std::endl;
}

void PersonagemJogavel::usarHabilidade() {
    // Habilidade básica de cura para todas as classes
    if (mana >= 20) {
        int cura = 30 + (nivel * 5);
        curar(cura);
        usarMana(20);
        std::cout << nome << " usou Cura e recuperou " << cura << " de vida!" << std::endl;
    } else {
        std::cout << nome << " nao tem mana suficiente para usar Cura! (Necessario: 20, Disponivel: " << mana << ")" << std::endl;
    }
}

// NOVAS HABILIDADES ÚNICAS
void PersonagemJogavel::usarHabilidadeGuerreiro() {
    if (classe == "Guerreiro") {
        if (mana >= 30) {
            // Habilidade: Escudo Defensivo - Aumenta defesa temporariamente
            int bonusDefesa = 8 + (nivel * 2);
            setDefesa(getDefesa() + bonusDefesa);
            usarMana(30);
            std::cout << nome << " usou ESCUDO DEFENSIVO! Defesa aumentada em +" << bonusDefesa << "!" << std::endl;
        } else {
            std::cout << nome << " nao tem mana suficiente para usar Escudo Defensivo! (Necessario: 30, Disponivel: " << mana << ")" << std::endl;
        }
    }
}

void PersonagemJogavel::usarHabilidadeMago() {
    if (classe == "Mago") {
        if (mana >= 40) {
            // Habilidade: Bola de Fogo - Dano mágico alto
            int danoMagico = 25 + (nivel * 8);
            usarMana(40);
            std::cout << nome << " usou BOLA DE FOGO! Dano magico: " << danoMagico << "!" << std::endl;
            
            // Escolher alvo para o ataque mágico
            std::cout << "Selecione um alvo para atacar com magia (1-X): ";
            int alvo;
            std::cin >> alvo;
            
            // Aqui você implementaria a lógica para escolher o alvo
            // Por enquanto, vamos simular o ataque
            std::cout << "Bola de Fogo causou " << danoMagico << " de dano magico!" << std::endl;
        } else {
            std::cout << nome << " nao tem mana suficiente para usar Bola de Fogo! (Necessario: 40, Disponivel: " << mana << ")" << std::endl;
        }
    }
}

void PersonagemJogavel::usarHabilidadeArqueiro() {
    if (classe == "Arqueiro") {
        if (mana >= 25) {
            // Habilidade: Tiro Preciso - Dano crítico
            int danoCritico = (forca * 2) + (nivel * 3);
            usarMana(25);
            std::cout << nome << " usou TIRO PRECISO! Dano critico: " << danoCritico << "!" << std::endl;
            
            // Escolher alvo para o tiro preciso
            std::cout << "Selecione um alvo para atacar com precisao (1-X): ";
            int alvo;
            std::cin >> alvo;
            
            // Aqui você implementaria a lógica para escolher o alvo
            // Por enquanto, vamos simular o ataque
            std::cout << "Tiro Preciso causou " << danoCritico << " de dano critico!" << std::endl;
        } else {
            std::cout << nome << " nao tem mana suficiente para usar Tiro Preciso! (Necessario: 25, Disponivel: " << mana << ")" << std::endl;
        }
    }
}

// NOVOS MÉTODOS DE ATAQUE
void PersonagemJogavel::ataqueMagico(Personagem* alvo, int dano) {
    if (!alvo || !alvo->estaVivo() || !vivo) return;
    
    // Dano mágico ignora defesa física
    alvo->receberDano(dano);
    std::cout << nome << " causou " << dano << " de dano magico em " << alvo->getNome() << "!" << std::endl;
}

void PersonagemJogavel::ataqueCritico(Personagem* alvo, int multiplicador) {
    if (!alvo || !alvo->estaVivo() || !vivo) return;
    
    int dano = (forca * multiplicador) - alvo->getDefesa();
    if (dano < 1) dano = 1;
    
    alvo->receberDano(dano);
    std::cout << nome << " causou " << dano << " de dano critico em " << alvo->getNome() << "!" << std::endl;
}

void PersonagemJogavel::mostrarHabilidadesDisponiveis() {
    std::cout << "\n=== HABILIDADES DISPONIVEIS PARA " << nome << " (" << classe << ") ===" << std::endl;
    std::cout << "1. Cura - 20 mana (Recupera vida)" << std::endl;
    
    if (classe == "Guerreiro") {
        std::cout << "2. Escudo Defensivo - 30 mana (Aumenta defesa)" << std::endl;
    } else if (classe == "Mago") {
        std::cout << "2. Bola de Fogo - 40 mana (Dano magico alto)" << std::endl;
    } else if (classe == "Arqueiro") {
        std::cout << "2. Tiro Preciso - 25 mana (Dano critico)" << std::endl;
    }
    
    std::cout << "Mana atual: " << mana << "/" << manaMaxima << std::endl;
}

void PersonagemJogavel::ganharExperiencia(int quantidade) {
    experiencia += quantidade;
    
    // Verificar se subiu de nível
    int expNecessaria = nivel * 100;
    if (experiencia >= expNecessaria) {
        subirNivel();
    }
}

void PersonagemJogavel::subirNivel() {
    nivel++;
    experiencia = 0;
    
    // Aumentar atributos
    vidaMaxima += 20;
    vida = vidaMaxima; // Restaurar vida ao subir de nível
    manaMaxima += 15;
    mana = manaMaxima; // Restaurar mana ao subir de nível
    forca += 3;
    defesa += 2;
    
    std::cout << "\n🎉 " << nome << " SUBIU PARA O NIVEL " << nivel << "! 🎉" << std::endl;
    std::cout << "Atributos aumentados! Vida e mana restauradas!" << std::endl;
}

void PersonagemJogavel::usarMana(int quantidade) {
    mana -= quantidade;
    if (mana < 0) mana = 0;
}

void PersonagemJogavel::recuperarMana(int quantidade) {
    mana += quantidade;
    if (mana > manaMaxima) mana = manaMaxima;
}

void PersonagemJogavel::setMana(int _mana) {
    mana = std::max(0, std::min(manaMaxima, _mana));
}

void PersonagemJogavel::setExperiencia(int _exp) {
    experiencia = std::max(0, _exp);
}
