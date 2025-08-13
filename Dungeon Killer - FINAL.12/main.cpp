#include <iostream>
#include "GameManager.hpp"

int main() {
    std::cout << "Iniciando Dungeon Killer - OOP Edition..." << std::endl;
    std::cout << "Demonstrando os 4 pilares da Orientacao a Objetos!" << std::endl;
    std::cout << "Utilizando a ASCII_ENGINE para renderizacao!" << std::endl;
    std::cout << std::endl;
    
    try {
        // Criar e executar o gerenciador do jogo
        GameManager gameManager;
        gameManager.executar();
        
    } catch (const std::exception& e) {
        std::cerr << "Erro durante a execucao do jogo: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Erro desconhecido durante a execucao do jogo!" << std::endl;
        return 1;
    }
    
    std::cout << "\nJogo finalizado com sucesso!" << std::endl;
    std::cout << "Demonstracao dos 4 pilares da OOP concluida!" << std::endl;
    return 0;
}
