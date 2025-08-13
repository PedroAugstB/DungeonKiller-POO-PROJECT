#include "GameObject.hpp"

GameObject::GameObject(const std::string& _nome, int _posX, int _posY)
    : nome(_nome), posX(_posX), posY(_posY), ativo(true) {
}

void GameObject::setPosicao(int x, int y) {
    posX = x;
    posY = y;
}

void GameObject::setAtivo(bool _ativo) {
    ativo = _ativo;
}
