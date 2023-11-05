// Name: Rosa Rivera Soto
// Date: 11/5/2023


#include "ActionCard.hpp"
ActionCard::ActionCard() {
    setType(CardType::ACTION_CARD);
    setDrawn(false);
    setIntruction("");
}
bool ActionCard::isPlayable() {
    if (!getDrawn()) {
        return false;
    }
        else {
            std::string currentIntruction = getIntruction();
            std::regex valid("^DRAW [0-9 CARD\\(S\\) |PLAY [0-9] CARD\\(S\\) |REVERSE HAND|SWAP HAND WITH OPPENENT$");
            return std::regex_match(currentIntruction, valid);
        }
}
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card:" << std::endl;
    if (getImageData() !=nullptr) {
            for (int i = 0; i <80; i++) {
                std::cout << getImageData()[i] << " ";
            }
            std::cout <<std::endl;
    }
    else {
        std::cout << "No image data" << std::endl;  
         }
}
   