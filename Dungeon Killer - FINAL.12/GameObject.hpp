#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "ASCII_Engine/SpriteBase.hpp"
#include <memory>
#include <string>

// Classe base abstrata - demonstra ABSTRAÇÃO
class GameObject {
protected:
    std::string nome;
    int posX, posY;
    std::unique_ptr<SpriteBase> sprite;
    bool ativo;

public:
    GameObject(const std::string& _nome, int _posX, int _posY);
    virtual ~GameObject() = default;
    
    // Métodos virtuais puros - forçam implementação nas subclasses
    virtual void atualizar() = 0;
    
    // Métodos concretos comuns
    void setPosicao(int x, int y);
    void setAtivo(bool _ativo);
    
    // Getters
    std::string getNome() const { return nome; }
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }
    bool isAtivo() const { return ativo; }
    SpriteBase* getSprite() const { return sprite.get(); }
};

#endif // GAMEOBJECT_HPP
