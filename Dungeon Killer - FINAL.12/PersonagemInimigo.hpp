#ifndef PERSONAGEMINIMIGO_HPP
#define PERSONAGEMINIMIGO_HPP

#include "Personagem.hpp"

// Classe para inimigos - demonstra HERANÇA
class PersonagemInimigo : public Personagem {
private:
    std::string tipo;
    int recompensaExperiencia;
    int recompensaOuro;

public:
    PersonagemInimigo(const std::string& _nome, const std::string& _tipo,
                      int _posX, int _posY, int _vida, int _forca,
                      int _defesa, int _velocidade, int _recompensaExp, int _recompensaOuro);
    
    // Implementação dos métodos virtuais puros
    void atacar(Personagem* alvo) override;
    void usarHabilidade() override;
    
    // Métodos específicos dos inimigos
    void escolherAcao(Personagem* jogador);
    
    // Getters
    std::string getTipo() const { return tipo; }
    int getRecompensaExperiencia() const { return recompensaExperiencia; }
    int getRecompensaOuro() const { return recompensaOuro; }
};

#endif // PERSONAGEMINIMIGO_HPP
