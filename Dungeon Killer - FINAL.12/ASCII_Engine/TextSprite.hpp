#ifndef TEXTSPRITE_HPP
#define TEXTSPRITE_HPP

#include <string>
#include <vector>
#include "SpriteBase.hpp"

//MUDAR PARA SPRITETEXT - inclusive whoami
class TextSprite : public SpriteBase
{
    //temporarios
    friend std::ostream &operator<<(std::ostream &, const TextSprite &);
public:
    TextSprite(std::string text):SpriteBase(0,1) {setText(text);} 
    ~TextSprite(){}
    
    void setText(std::string text);
    
    //SpriteBase
    virtual void putAt(const SpriteBase &, unsigned = 0, unsigned = 0);
    virtual std::string whoami() const {return "TextSprite";}
    
    //RenderBase
    virtual void init() {};
    virtual void update() {};
private:
    std::vector<std::string> linhas;
    
    //SpriteBase
    virtual std::string getLinha(unsigned) const;
};

#endif // TEXTSPRITE_HPP
