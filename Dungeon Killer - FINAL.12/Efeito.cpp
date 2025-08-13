#include "Efeito.hpp"

Efeito::Efeito(const std::string& _nome, const std::string& _descricao, int _duracao)
    : nome(_nome), descricao(_descricao), duracao(_duracao), duracaoMaxima(_duracao), ativo(true) {
}

void Efeito::diminuirDuracao() {
    if (ativo) {
        duracao--;
        if (duracao <= 0) {
            ativo = false;
        }
    }
}
