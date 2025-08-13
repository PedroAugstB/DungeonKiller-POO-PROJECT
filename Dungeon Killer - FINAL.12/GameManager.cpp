#include "GameManager.hpp"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

GameManager::GameManager() 
    : estadoAtual(GameState::MENU_PRINCIPAL), jogoRodando(true), turno(1), 
      nivel(1), ouro(0), larguraTela(80), alturaTela(25) {
    // Inicializar gerador de números aleatórios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void GameManager::executar() {
    inicializar();
    
    while (jogoRodando) {
        processarEstadoAtual();
    }
    
    finalizar();
}

void GameManager::inicializar() {
    limparTela();
    mostrarTitulo();
    std::cout << "\nInicializando Dungeon Killer - OOP Edition..." << std::endl;
    std::cout << "Demonstrando os 4 pilares da Orientacao a Objetos!" << std::endl;
    pausar();
}

void GameManager::finalizar() {
    limparTela();
    mostrarTitulo();
    std::cout << "\nObrigado por jogar Dungeon Killer!" << std::endl;
    std::cout << "Demonstracao dos 4 pilares da OOP concluida!" << std::endl;
    pausar();
}

void GameManager::mudarEstado(GameState novoEstado) {
    estadoAtual = novoEstado;
}

void GameManager::processarEstadoAtual() {
    switch (estadoAtual) {
        case GameState::MENU_PRINCIPAL:
            mostrarMenuPrincipal();
            break;
        case GameState::CRIAR_PERSONAGEM:
            mostrarMenuCriarPersonagem();
            break;
        case GameState::GERENCIAR_TIME:
            mostrarMenuGerenciarTime();
            break;
        case GameState::MOSTRAR_TIME:
            mostrarTime();
            break;
        case GameState::EM_COMBATE:
            processarTurno();
            break;
        case GameState::PAUSA:
            mostrarMenuPausa();
            break;
        case GameState::GAME_OVER:
            mostrarGameOver();
            break;
        case GameState::VITORIA:
            mostrarVitoria();
            break;
    }
}

void GameManager::mostrarTitulo() {
    std::cout << R"(
==================================================
           DUNGEON KILLER - OOP Edition           
    DEMONSTRACAO DOS 4 PILARES DA ORIENTACAO     
                    A OBJETOS                     
==================================================
)" << std::endl;
}

void GameManager::mostrarMenuPrincipal() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== MENU PRINCIPAL ===" << std::endl;
    std::cout << "1. NOVO JOGO (Criar Personagem)" << std::endl;
    std::cout << "2. INICIAR COMBATE" << std::endl;
    std::cout << "3. GERENCIAR TIME" << std::endl;
    std::cout << "4. MOSTRAR STATUS" << std::endl;
    std::cout << "5. CREDITOS" << std::endl;
    std::cout << "6. SAIR" << std::endl;
    std::cout << "\nEscolha uma opcao: ";
    
    int opcao;
    std::cin >> opcao;
    
    switch (opcao) {
        case 1:
            mudarEstado(GameState::CRIAR_PERSONAGEM);
            break;
        case 2:
            if (temHerois()) {
                iniciarCombate();
            } else {
                std::cout << "\nCrie pelo menos um personagem primeiro!" << std::endl;
                pausar();
            }
            break;
        case 3:
            if (temHerois()) {
                mudarEstado(GameState::GERENCIAR_TIME);
            } else {
                std::cout << "\nCrie pelo menos um personagem primeiro!" << std::endl;
                pausar();
            }
            break;
        case 4:
            mostrarStatusJogo();
            break;
        case 5:
            mostrarCreditos();
            break;
        case 6:
            jogoRodando = false;
            break;
        default:
            std::cout << "\nOpcao invalida!" << std::endl;
            pausar();
            break;
    }
}

void GameManager::mostrarMenuCriarPersonagem() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== CRIAR PERSONAGEM ===" << std::endl;
    std::cout << "Escolha sua classe:" << std::endl;
    std::cout << "1. Guerreiro - Vida: 120, Forca: 18, Defesa: 10, Mana: 50" << std::endl;
    std::cout << "2. Mago - Vida: 80, Forca: 20, Defesa: 5, Mana: 100" << std::endl;
    std::cout << "3. Arqueiro - Vida: 90, Forca: 16, Defesa: 8, Mana: 70" << std::endl;
    std::cout << "4. Ver Habilidades das Classes" << std::endl;
    std::cout << "\nEscolha (1-4): ";
    
    int classe;
    std::cin >> classe;
    
    std::string nomeClasse, nome;
    int vida, forca, defesa, mana;
    
    switch (classe) {
        case 1:
            nomeClasse = "Guerreiro";
            vida = 120;
            forca = 18;
            defesa = 10;
            mana = 50;
            break;
        case 2:
            nomeClasse = "Mago";
            vida = 80;
            forca = 20;
            defesa = 5;
            mana = 100;
            break;
        case 3:
            nomeClasse = "Arqueiro";
            vida = 90;
            forca = 16;
            defesa = 8;
            mana = 70;
            break;
        case 4:
            // Mostrar habilidades das classes
            limparTela();
            mostrarTitulo();
            std::cout << "\n=== HABILIDADES DAS CLASSES ===" << std::endl;
            std::cout << "\n--- GUERREIRO ---" << std::endl;
            std::cout << "• Cura - 20 mana (Recupera vida)" << std::endl;
            std::cout << "• Escudo Defensivo - 30 mana (Aumenta defesa)" << std::endl;
            std::cout << "• Especialidade: Tank e proteção" << std::endl;
            
            std::cout << "\n--- MAGO ---" << std::endl;
            std::cout << "• Cura - 20 mana (Recupera vida)" << std::endl;
            std::cout << "• Bola de Fogo - 40 mana (Dano mágico alto)" << std::endl;
            std::cout << "• Especialidade: Dano mágico e controle" << std::endl;
            
            std::cout << "\n--- ARQUEIRO ---" << std::endl;
            std::cout << "• Cura - 20 mana (Recupera vida)" << std::endl;
            std::cout << "• Tiro Preciso - 25 mana (Dano crítico)" << std::endl;
            std::cout << "• Especialidade: Dano à distância e precisão" << std::endl;
            
            pausar();
            mudarEstado(GameState::CRIAR_PERSONAGEM);
            return;
        default:
            std::cout << "\nClasse invalida!" << std::endl;
            pausar();
            return;
    }
    
    std::cout << "Digite seu nome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    
    if (nome.empty()) nome = "Heroi";
    
    // Criar personagem usando OOP - demonstra ENCAPSULAMENTO
    auto novoHeroi = std::make_unique<PersonagemJogavel>(nome, nomeClasse, 10, 10, vida, forca, defesa, 10, mana);
    
    // Adicionar ao time
    adicionarHeroiAoTime(std::move(novoHeroi));
    
    std::cout << "\nPersonagem criado e adicionado ao time com sucesso!" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Classe: " << nomeClasse << std::endl;
    std::cout << "Vida: " << vida << std::endl;
    std::cout << "Forca: " << forca << std::endl;
    std::cout << "Defesa: " << defesa << std::endl;
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "Tamanho do time: " << timeHerois.size() << " heroi(s)" << std::endl;
    
    pausar();
    mudarEstado(GameState::MENU_PRINCIPAL);
}

void GameManager::adicionarHeroiAoTime(std::unique_ptr<PersonagemJogavel> heroi) {
    timeHerois.push_back(std::move(heroi));
    std::cout << "Heroi adicionado ao time! Total: " << timeHerois.size() << std::endl;
}

void GameManager::removerHeroiDoTime(int indice) {
    if (indice >= 0 && indice < static_cast<int>(timeHerois.size())) {
        std::cout << "Removendo " << timeHerois[indice]->getNome() << " do time!" << std::endl;
        timeHerois.erase(timeHerois.begin() + indice);
    }
}

void GameManager::mostrarMenuGerenciarTime() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== GERENCIAR TIME ===" << std::endl;
    std::cout << "1. Mostrar Time" << std::endl;
    std::cout << "2. Ver Habilidades dos Herois" << std::endl;
    std::cout << "3. Remover Heroi" << std::endl;
    std::cout << "4. Voltar ao Menu Principal" << std::endl;
    std::cout << "\nEscolha uma opcao: ";
    
    int opcao;
    std::cin >> opcao;
    
    switch (opcao) {
        case 1:
            mudarEstado(GameState::MOSTRAR_TIME);
            break;
        case 2:
            // Mostrar habilidades dos heróis
            limparTela();
            mostrarTitulo();
            std::cout << "\n=== HABILIDADES DOS HERÓIS ===" << std::endl;
            for (size_t i = 0; i < timeHerois.size(); ++i) {
                const auto& heroi = timeHerois[i];
                std::cout << "\n--- " << heroi->getNome() << " (" << heroi->getClasse() << ") ---" << std::endl;
                heroi->mostrarHabilidadesDisponiveis();
            }
            pausar();
            break;
        case 3:
            if (timeHerois.size() > 1) {
                std::cout << "\nEscolha o heroi para remover (1-" << timeHerois.size() << "): ";
                int indice;
                std::cin >> indice;
                removerHeroiDoTime(indice - 1);
            } else {
                std::cout << "\nNao e possivel remover herois. Mantenha pelo menos um!" << std::endl;
            }
            pausar();
            break;
        case 4:
            mudarEstado(GameState::MENU_PRINCIPAL);
            break;
        default:
            std::cout << "Opcao invalida!" << std::endl;
            pausar();
            break;
    }
}

void GameManager::mostrarTime() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== SEU TIME DE HERÓIS ===" << std::endl;
    std::cout << "Total de herois: " << timeHerois.size() << std::endl;
    
    if (timeHerois.empty()) {
        std::cout << "Nenhum heroi no time ainda!" << std::endl;
    } else {
        for (size_t i = 0; i < timeHerois.size(); ++i) {
            const auto& heroi = timeHerois[i];
            std::cout << "\n--- HEROI " << (i + 1) << " ---" << std::endl;
            std::cout << "Nome: " << heroi->getNome() << " (" << heroi->getClasse() << ")" << std::endl;
            std::cout << "Vida: " << heroi->getVida() << "/" << heroi->getVidaMaxima() << std::endl;
            std::cout << "Mana: " << heroi->getMana() << "/" << heroi->getManaMaxima() << std::endl;
            std::cout << "Forca: " << heroi->getForca() << " | Defesa: " << heroi->getDefesa() << std::endl;
            std::cout << "Nivel: " << heroi->getNivel() << " | Exp: " << heroi->getExperiencia() << "/" << (heroi->getNivel() * 100) << std::endl;
        }
    }
    
    std::cout << "\n1. Voltar ao Menu de Gerenciamento" << std::endl;
    std::cout << "2. Voltar ao Menu Principal" << std::endl;
    std::cout << "Escolha (1-2): ";
    
    int opcao;
    std::cin >> opcao;
    
    switch (opcao) {
        case 1:
            mudarEstado(GameState::GERENCIAR_TIME);
            break;
        case 2:
            mudarEstado(GameState::MENU_PRINCIPAL);
            break;
        default:
            mudarEstado(GameState::MENU_PRINCIPAL);
            break;
    }
}

void GameManager::iniciarCombate() {
    if (!temHerois()) return;
    
    // Criar inimigos baseados no nível - demonstra POLIMORFISMO
    inimigos.clear();
    
    if (nivel == 1) {
        inimigos.push_back(std::make_unique<PersonagemInimigo>("Goblin", "Goblin", 20, 10, 50, 8, 3, 8, 20, 10));
        inimigos.push_back(std::make_unique<PersonagemInimigo>("Lobo", "Lobo", 30, 10, 70, 10, 4, 9, 25, 15));
    } else if (nivel == 2) {
        inimigos.push_back(std::make_unique<PersonagemInimigo>("Orc", "Orc", 20, 10, 80, 12, 6, 7, 30, 20));
        inimigos.push_back(std::make_unique<PersonagemInimigo>("Troll", "Troll", 30, 10, 100, 15, 8, 6, 35, 25));
    } else {
        inimigos.push_back(std::make_unique<PersonagemInimigo>("Dragao", "Dragao", 25, 15, 150, 20, 12, 10, 50, 50));
        inimigos.push_back(std::make_unique<PersonagemInimigo>("Demonio", "Demonio", 35, 15, 120, 18, 10, 11, 45, 40));
    }
    
    turno = 1;
    std::cout << "\n=== COMBATE INICIADO ===" << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Inimigos: " << inimigos.size() << std::endl;
    pausar();
    
    mudarEstado(GameState::EM_COMBATE);
}

void GameManager::processarTurno() {
    // Verificar se algum herói está vivo
    bool algumHeroiVivo = false;
    for (const auto& heroi : timeHerois) {
        if (heroi->estaVivo()) {
            algumHeroiVivo = true;
            break;
        }
    }
    
    if (!algumHeroiVivo) {
        mudarEstado(GameState::GAME_OVER);
        return;
    }
    
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== TURNO " << turno << " ===" << std::endl;
    std::cout << "Nivel: " << nivel << " | Ouro: " << ouro << std::endl;
    
    // Mostrar status de todos os heróis
    std::cout << "\n--- STATUS DO TIME ---" << std::endl;
    for (size_t i = 0; i < timeHerois.size(); ++i) {
        const auto& heroi = timeHerois[i];
        std::cout << "\n--- HEROI " << (i + 1) << " ---" << std::endl;
        std::cout << "Nome: " << heroi->getNome() << " (" << heroi->getClasse() << ")" << std::endl;
        std::cout << "Vida: " << heroi->getVida() << "/" << heroi->getVidaMaxima() << std::endl;
        std::cout << "Mana: " << heroi->getMana() << "/" << heroi->getManaMaxima() << std::endl;
        std::cout << "Forca: " << heroi->getForca() << " | Defesa: " << heroi->getDefesa() << std::endl;
        std::cout << "Nivel: " << heroi->getNivel() << " | Exp: " << heroi->getExperiencia() << "/" << (heroi->getNivel() * 100) << std::endl;
        if (!heroi->estaVivo()) {
            std::cout << "STATUS: INCONSCIENTE" << std::endl;
        }
    }
    
    std::cout << "\n--- INIMIGOS ---" << std::endl;
    for (size_t i = 0; i < inimigos.size(); ++i) {
        if (inimigos[i]->estaVivo()) {
            std::cout << (i + 1) << ". " << inimigos[i]->getNome() << " (" << inimigos[i]->getTipo() << ") ";
            std::cout << "HP: " << inimigos[i]->getVida() << "/" << inimigos[i]->getVidaMaxima() << std::endl;
        }
    }
    
    // Ações do time de heróis
    std::cout << "\n=== ACOES DO TIME ===" << std::endl;
    std::cout << "0. Pausar Jogo" << std::endl;
    
    // Processar ações de cada herói vivo
    for (size_t i = 0; i < timeHerois.size(); ++i) {
        auto& heroi = timeHerois[i];
        if (!heroi->estaVivo()) continue;
        
        std::cout << "\n--- TURNO DO " << heroi->getNome() << " (" << heroi->getClasse() << ") ---" << std::endl;
        std::cout << "1. Atacar" << std::endl;
        std::cout << "2. Usar Habilidade Basica (Cura - 20 mana)" << std::endl;
        std::cout << "3. Usar Habilidade Especial da Classe" << std::endl;
        std::cout << "4. Usar Pocao de Forca" << std::endl;
        std::cout << "5. Pular turno" << std::endl;
        std::cout << "Escolha (1-5): ";
        
        int acao;
        std::cin >> acao;
        
        // Verificar se quer pausar
        if (acao == 0) {
            mudarEstado(GameState::PAUSA);
            return;
        }
        
        switch (acao) {
            case 1: {
                // Escolher alvo
                std::cout << "Escolha o inimigo para atacar (1-" << inimigos.size() << "): ";
                int alvo;
                std::cin >> alvo;
                
                if (alvo >= 1 && alvo <= static_cast<int>(inimigos.size())) {
                    if (inimigos[alvo - 1]->estaVivo()) {
                        heroi->atacar(inimigos[alvo - 1].get());
                        std::cout << heroi->getNome() << " atacou o inimigo!" << std::endl;
                    } else {
                        std::cout << "Este inimigo ja esta morto!" << std::endl;
                    }
                } else {
                    std::cout << "Alvo invalido!" << std::endl;
                }
                break;
            }
            case 2:
                heroi->usarHabilidade();
                break;
            case 3: {
                // Usar habilidade especial da classe
                std::string classe = heroi->getClasse();
                if (classe == "Guerreiro") {
                    heroi->usarHabilidadeGuerreiro();
                } else if (classe == "Mago") {
                    // Para o mago, implementar ataque mágico real
                    heroi->usarHabilidadeMago();
                    // Aqui você implementaria a lógica para escolher o alvo
                    // e aplicar o dano mágico real
                } else if (classe == "Arqueiro") {
                    // Para o arqueiro, implementar ataque crítico real
                    heroi->usarHabilidadeArqueiro();
                    // Aqui você implementaria a lógica para escolher o alvo
                    // e aplicar o dano crítico real
                }
                break;
            }
            case 4: {
                // Usar poção de força - demonstra POLIMORFISMO
                auto efeito = std::make_unique<EfeitoForca>(5, 3); // +5 força por 3 turnos
                efeito->aplicar(heroi.get());
                heroi->adicionarEfeito(std::move(efeito));
                std::cout << heroi->getNome() << " usou uma pocao de forca!" << std::endl;
                break;
            }
            case 5:
                std::cout << heroi->getNome() << " pulou o turno." << std::endl;
                break;
            default:
                std::cout << "Acao invalida! Pulando turno." << std::endl;
                break;
        }
    }
    
    pausar();
    
    // Limpar tela antes das ações dos inimigos
    limparTela();
    mostrarTitulo();
    std::cout << "\n=== TURNO " << turno << " - ACAO DOS INIMIGOS ===" << std::endl;
    
    // Ação dos inimigos
    for (auto& inimigo : inimigos) {
        if (inimigo->estaVivo()) {
            // Escolher um herói aleatório para atacar
            std::vector<Personagem*> heroisVivos;
            for (auto& heroi : timeHerois) {
                if (heroi->estaVivo()) {
                    heroisVivos.push_back(heroi.get());
                }
            }
            
            if (!heroisVivos.empty()) {
                // Escolher herói aleatório
                int indiceAleatorio = rand() % heroisVivos.size();
                inimigo->escolherAcao(heroisVivos[indiceAleatorio]);
            }
        }
    }
    
    pausar();
    
    // Verificar fim do combate
    if (!algumHeroiVivo) {
        mudarEstado(GameState::GAME_OVER);
        return;
    }
    
    bool todosInimigosMortos = true;
    for (const auto& inimigo : inimigos) {
        if (inimigo->estaVivo()) {
            todosInimigosMortos = false;
            break;
        }
    }
    
    if (todosInimigosMortos) {
        finalizarCombate();
        return;
    }
    
    // Atualizar todos os personagens
    for (auto& heroi : timeHerois) {
        heroi->atualizar();
    }
    for (auto& inimigo : inimigos) {
        inimigo->atualizar();
    }
    
    turno++;
}

void GameManager::finalizarCombate() {
    std::cout << "\n=== VITORIA! ===" << std::endl;
    std::cout << "Todos os inimigos foram derrotados!" << std::endl;
    
    // Calcular recompensas
    int expTotal = 0;
    int ouroTotal = 0;
    for (const auto& inimigo : inimigos) {
        expTotal += inimigo->getRecompensaExperiencia();
        ouroTotal += inimigo->getRecompensaOuro();
    }
    
    // Distribuir experiência entre todos os heróis vivos
    int expPorHeroi = expTotal / std::max(1, static_cast<int>(timeHerois.size()));
    for (auto& heroi : timeHerois) {
        if (heroi->estaVivo()) {
            heroi->ganharExperiencia(expPorHeroi);
        }
    }
    ouro += ouroTotal;
    
    std::cout << "Recompensas:" << std::endl;
    std::cout << "- Experiencia: +" << expTotal << std::endl;
    std::cout << "- Ouro: +" << ouroTotal << " (Total: " << ouro << ")" << std::endl;
    
    nivel++;
    pausar();
    mudarEstado(GameState::MENU_PRINCIPAL);
}

void GameManager::mostrarMenuPausa() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== PAUSA ===" << std::endl;
    std::cout << "1. Continuar Jogo" << std::endl;
    std::cout << "2. Voltar ao Menu Principal" << std::endl;
    std::cout << "Escolha (1-2): ";
    
    int opcao;
    std::cin >> opcao;
    
    switch (opcao) {
        case 1:
            mudarEstado(GameState::EM_COMBATE);
            break;
        case 2:
            mudarEstado(GameState::MENU_PRINCIPAL);
            break;
        default:
            std::cout << "Opcao invalida!" << std::endl;
            pausar();
            break;
    }
}

void GameManager::mostrarGameOver() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== GAME OVER ===" << std::endl;
    std::cout << "Voce foi derrotado!" << std::endl;
    std::cout << "Nivel alcancado: " << nivel << std::endl;
    std::cout << "Ouro coletado: " << ouro << std::endl;
    
    std::cout << "\n1. Tentar Novamente" << std::endl;
    std::cout << "2. Voltar ao Menu Principal" << std::endl;
    std::cout << "3. Sair" << std::endl;
    std::cout << "Escolha (1-3): ";
    
    int opcao;
    std::cin >> opcao;
    
    switch (opcao) {
        case 1:
            // Resetar jogo
            nivel = 1;
            turno = 1;
            ouro = 0;
            // Restaurar todos os heróis
            for (auto& heroi : timeHerois) {
                heroi->setVida(heroi->getVidaMaxima());
                heroi->setMana(heroi->getManaMaxima());
            }
            mudarEstado(GameState::MENU_PRINCIPAL);
            break;
        case 2:
            mudarEstado(GameState::MENU_PRINCIPAL);
            break;
        case 3:
            jogoRodando = false;
            break;
        default:
            std::cout << "Opcao invalida!" << std::endl;
            pausar();
            break;
    }
}

void GameManager::mostrarVitoria() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== VITORIA! ===" << std::endl;
    std::cout << "Parabens! Voce completou o nivel " << nivel << "!" << std::endl;
    std::cout << "Ouro total: " << ouro << std::endl;
    
    pausar();
    mudarEstado(GameState::MENU_PRINCIPAL);
}

void GameManager::mostrarStatusJogo() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== STATUS DO JOGO ===" << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Turno: " << turno << std::endl;
    std::cout << "Ouro: " << ouro << std::endl;
    
    if (temHerois()) {
        std::cout << "\n--- SEU TIME DE HERÓIS ---" << std::endl;
        for (size_t i = 0; i < timeHerois.size(); ++i) {
            const auto& heroi = timeHerois[i];
            std::cout << "\n--- HEROI " << (i + 1) << " ---" << std::endl;
            std::cout << "Nome: " << heroi->getNome() << " (" << heroi->getClasse() << ")" << std::endl;
            std::cout << "Vida: " << heroi->getVida() << "/" << heroi->getVidaMaxima() << std::endl;
            std::cout << "Mana: " << heroi->getMana() << "/" << heroi->getManaMaxima() << std::endl;
            std::cout << "Forca: " << heroi->getForca() << " | Defesa: " << heroi->getDefesa() << std::endl;
            std::cout << "Nivel: " << heroi->getNivel() << " | Exp: " << heroi->getExperiencia() << "/" << (heroi->getNivel() * 100) << std::endl;
        }
    } else {
        std::cout << "\n--- NENHUM HERÓI NO TIME ---" << std::endl;
    }
    
    if (!inimigos.empty()) {
        std::cout << "\n--- INIMIGOS ---" << std::endl;
        for (const auto& inimigo : inimigos) {
            std::cout << inimigo->getNome() << " (" << inimigo->getTipo() << ") ";
            std::cout << "HP: " << inimigo->getVida() << "/" << inimigo->getVidaMaxima() << std::endl;
        }
    }
    
    pausar();
}

void GameManager::mostrarCreditos() {
    limparTela();
    mostrarTitulo();
    
    std::cout << "\n=== CREDITOS ===" << std::endl;
    std::cout << "DUNGEON KILLER - OOP Edition" << std::endl;
    std::cout << "\nDesenvolvido para demonstrar os 4 pilares da OOP:" << std::endl;
    std::cout << "1. ENCAPSULAMENTO - Atributos privados, metodos publicos" << std::endl;
    std::cout << "2. HERANCA - Classes base e derivadas" << std::endl;
    std::cout << "3. POLIMORFISMO - Metodos virtuais e efeitos" << std::endl;
    std::cout << "4. ABSTRACAO - Interfaces e classes abstratas" << std::endl;
    std::cout << "\nUtilizando a ASCII_ENGINE para renderizacao!" << std::endl;
    
    pausar();
}

void GameManager::limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void GameManager::pausar() {
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
