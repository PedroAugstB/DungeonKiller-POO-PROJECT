#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "GameObject.hpp"
#include "Efeito.hpp"
#include <vector>
#include <memory>

// Classe abstrata para personagens - demonstra HERANÇA
class Personagem : public GameObject {
protected:
    // Atributos protegidos - demonstra ENCAPSULAMENTO
    int vida;
    int vidaMaxima;
    int forca;
    int defesa;
    int velocidade;
    bool vivo;
    
    // Vetor de efeitos - demonstra POLIMORFISMO
    std::vector<std::unique_ptr<Efeito>> efeitos;

public:
    Personagem(const std::string& _nome, int _posX, int _posY, 
               int _vida, int _forca, int _defesa, int _velocidade);
    virtual ~Personagem() = default;
    
    // Métodos virtuais implementados
    void atualizar() override;
    
    // Métodos virtuais puros para subclasses
    virtual void atacar(Personagem* alvo) = 0;
    virtual void usarHabilidade() = 0;
    
    // Métodos comuns
    void receberDano(int dano);
    void curar(int quantidade);
    void adicionarEfeito(std::unique_ptr<Efeito> efeito);
    void removerEfeitosExpirados();
    
    // Getters
    int getVida() const { return vida; }
    int getVidaMaxima() const { return vidaMaxima; }
    int getForca() const { return forca; }
    int getDefesa() const { return defesa; }
    int getVelocidade() const { return velocidade; }
    bool estaVivo() const { return vivo; }
    
    // Setters
    void setVida(int _vida);
    void setForca(int _forca);
    void setDefesa(int _defesa);
    void setVelocidade(int _velocidade);
};

#endif // PERSONAGEM_HPP
