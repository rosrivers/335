#include "ActionCard.hpp"
ActionCard::ActionCard() {
    setType(CardType::Action);
}
bool ActionCard::isPlayable() {
    if (getDrawn()) {
        std::string instruction = getInstruction();
        if (std::regex_match(instruction, std::regex("DRAW [1-9][0-9]* CARD(S)?")) ||
            std::regex_match(instruction, std::regex("PLAY [1-9][0-9]* CARD(S)?")) ||
            instruction == "REVERSE HAND" ||
            instruction == "SWAP HAND WITH OPPONENT") {
            return true;
        }
    }
    return false;
}
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card:" << std::endl;
    if (getDrawn()) {
        const int* imageData = getImageData();
        if (imageData) {
            for (int i = 0; imageData[i] != 0; i++) {
                std::cout << imageData[i] << " ";
            }
        } else {
            std::cout << "No image data";
        }
    } else {
        std::cout << "Card not drawn yet";
    }
    std::cout << std::endl;
}
