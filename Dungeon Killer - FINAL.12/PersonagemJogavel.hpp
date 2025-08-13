#ifndef PERSONAGEMJOGAVEL_HPP
#define PERSONAGEMJOGAVEL_HPP

#include "Personagem.hpp"
#include "ASCII_Engine/Sprite.hpp"

// Classe para personagens controlados pelo jogador - demonstra HERANÇA
class PersonagemJogavel : public Personagem {
private:
    // Atributos específicos do jogador - demonstra ENCAPSULAMENTO
    int mana;
    int manaMaxima;
    int experiencia;
    int nivel;
    std::string classe;

public:
    PersonagemJogavel(const std::string& _nome, const std::string& _classe, 
                      int _posX, int _posY, int _vida, int _forca, 
                      int _defesa, int _velocidade, int _mana);
    
    // Implementação dos métodos virtuais puros
    void atacar(Personagem* alvo) override;
    void usarHabilidade() override;
    
    // Métodos específicos do jogador
    void ganharExperiencia(int quantidade);
    void subirNivel();
    void usarMana(int quantidade);
    void recuperarMana(int quantidade);
    
    // NOVAS HABILIDADES ÚNICAS PARA CADA CLASSE
    void usarHabilidadeGuerreiro();
    void usarHabilidadeMago();
    void usarHabilidadeArqueiro();
    void mostrarHabilidadesDisponiveis();
    
    // Habilidades que causam dano real
    void ataqueMagico(Personagem* alvo, int dano);
    void ataqueCritico(Personagem* alvo, int multiplicador);
    
    // Getters
    int getMana() const { return mana; }
    int getManaMaxima() const { return manaMaxima; }
    int getExperiencia() const { return experiencia; }
    int getNivel() const { return nivel; }
    std::string getClasse() const { return classe; }
    
    // Setters
    void setMana(int _mana);
    void setExperiencia(int _exp);
};

#endif // PERSONAGEMJOGAVEL_HPP
