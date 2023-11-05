#include "actioncard.hpp"

// ActionCard Constructor
ActionCard::ActionCard() {
    setType(CardType::ACTION_CARD);
}
bool ActionCard::isPlayable() {
    return getDrawn();
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

