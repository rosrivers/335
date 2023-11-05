#include "pointcard.hpp"
#include "card.hpp"

// PointCard Constructor
PointCard::PointCard() {
    setType(CardType::POINT_CARD); 
}
bool PointCard::isPlayable() {
    return getDrawn();
}
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
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

