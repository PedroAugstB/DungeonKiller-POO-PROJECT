#include "TextSprite.hpp"
#include <iostream>
#include <sstream>

std::ostream &operator<<(std::ostream &out, const TextSprite &ts)
{
    for (const auto &ln : ts.linhas)
        out << ln << std::endl;
    return out;
}

void TextSprite::setText(std::string text)
{
    linhas.clear();
    std::stringstream ss(text);
    std::string ln;
    largura = 0;
    while (std::getline(ss, ln)) {
        linhas.push_back(ln);
        if (ln.length() > largura) largura = static_cast<unsigned>(ln.length());
    }
    if (linhas.empty()) {
        linhas.push_back("");
    }
    alturaSprite = static_cast<unsigned>(linhas.size());
}

std::string TextSprite::getLinha(unsigned l) const
{
    if (l < linhas.size())
        return linhas[l];
    else 
        return "";
}

void TextSprite::putAt(const SpriteBase &sprt, unsigned l, unsigned c)
{
    if (l >= linhas.size())
        return;

    // Apenas sobrepomos a linha específica l com o sprite fornecido
    std::string linha = sprt.getLinha(0);
    std::string &alvo = linhas[l];

    if (c >= alvo.length())
        return;

    std::string nova = alvo.substr(0, c);
    // garantir que não extrapole
    size_t restante = (alvo.length() > c) ? (alvo.length() - c) : 0;
    if (linha.length() > restante) linha = linha.substr(0, restante);
    nova += linha;
    if (c + linha.length() < alvo.length())
        nova += alvo.substr(c + linha.length());

    alvo = nova;
}