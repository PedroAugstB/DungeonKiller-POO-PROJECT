#ifndef EFEITO_HPP
#define EFEITO_HPP

#include <string>

// Classe base abstrata para efeitos - demonstra POLIMORFISMO
class Efeito {
protected:
    std::string nome;
    std::string descricao;
    int duracao;
    int duracaoMaxima;
    bool ativo;

public:
    Efeito(const std::string& _nome, const std::string& _descricao, int _duracao);
    virtual ~Efeito() = default;
    
    // Método virtual puro - cada tipo de efeito tem comportamento diferente
    virtual void aplicar(class Personagem* alvo) = 0;
    virtual void remover(class Personagem* alvo) = 0;
    virtual void atualizar(class Personagem* alvo) = 0;
    
    // Métodos comuns
    void diminuirDuracao();
    bool estaAtivo() const { return ativo; }
    int getDuracao() const { return duracao; }
    std::string getNome() const { return nome; }
    std::string getDescricao() const { return descricao; }
    
    // Método para verificar se o efeito expirou
    bool expirou() const { return duracao <= 0; }
};

#endif // EFEITO_HPP
