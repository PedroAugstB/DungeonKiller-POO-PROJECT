#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "PersonagemJogavel.hpp"
#include "PersonagemInimigo.hpp"
#include "EfeitoForca.hpp"
#include "ASCII_Engine/Fase.hpp"
#include <vector>
#include <memory>
#include <string>

// Gerenciador principal do jogo - demonstra ABSTRAÇÃO
class GameManager {
private:
    // Estados do jogo
    enum class GameState {
        MENU_PRINCIPAL,
        CRIAR_PERSONAGEM,
        GERENCIAR_TIME,
        MOSTRAR_TIME,
        EM_COMBATE,
        PAUSA,
        GAME_OVER,
        VITORIA
    };
    
    GameState estadoAtual;
    bool jogoRodando;
    
    // Sistema de jogo - MODIFICADO para suportar múltiplos heróis
    std::vector<std::unique_ptr<PersonagemJogavel>> timeHerois;  // ✅ TIME DE HERÓIS
    std::vector<std::unique_ptr<PersonagemInimigo>> inimigos;
    std::unique_ptr<Fase> faseAtual;
    
    // Dados do jogo
    int turno;
    int nivel;
    int ouro;
    
    // Configurações visuais
    int larguraTela;
    int alturaTela;

public:
    GameManager();
    ~GameManager() = default;
    
    // Métodos principais
    void executar();
    void inicializar();
    void finalizar();
    
    // Gerenciamento de estado
    void mudarEstado(GameState novoEstado);
    void processarEstadoAtual();
    
    // Menus e interface
    void mostrarMenuPrincipal();
    void mostrarMenuCriarPersonagem();
    void mostrarMenuGerenciarTime();
    void mostrarTime();
    void mostrarMenuPausa();
    void mostrarGameOver();
    void mostrarVitoria();
    void mostrarStatusJogo();
    
    // Sistema de jogo
    void criarPersonagem();
    void adicionarHeroiAoTime(std::unique_ptr<PersonagemJogavel> heroi);
    void removerHeroiDoTime(int indice);
    void iniciarCombate();
    void processarTurno();
    void finalizarCombate();
    
    // Utilitários
    void limparTela();
    void mostrarTitulo();
    void mostrarCreditos();
    void pausar();
    
    // Getters
    GameState getEstadoAtual() const { return estadoAtual; }
    bool isJogoRodando() const { return jogoRodando; }
    int getNivel() const { return nivel; }
    int getTurno() const { return turno; }
    int getOuro() const { return ouro; }
    const std::vector<std::unique_ptr<PersonagemJogavel>>& getTimeHerois() const { return timeHerois; }
    bool temHerois() const { return !timeHerois.empty(); }
};

#endif // GAMEMANAGER_HPP
