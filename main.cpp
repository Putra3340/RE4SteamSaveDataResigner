#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

std::vector<char> buffer(16);
std::streampos hexOffset;

int readandwrite() {
    std::ifstream inputFile("ORIGINAL_STEAM_SAVEDATA\\savegame00.sav", std::ios::binary);

    if (!inputFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return 1;
    }

    inputFile.seekg(hexOffset);

    if (!inputFile) {
        std::cerr << "Error seeking to the offset." << std::endl;
        return 1;
    }

    inputFile.read(buffer.data(), buffer.size());

    if (!inputFile) {
        std::cerr << "Error reading from the file." << std::endl;
        return 1;
    }

    inputFile.close();

    std::cout << "Signing Key Read: ";
    for (char byte : buffer) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<unsigned char>(byte)) << " ";
    }
    std::cout << std::endl;

    std::ofstream outputFile("OUTPUT_SAVEDATA\\savegame00.sav", std::ios::binary | std::ios::in | std::ios::out);

    if (!outputFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    outputFile.seekp(hexOffset);

    if (!outputFile) {
        std::cerr << "Error seeking to the offset." << std::endl;
        return 1;
    }

    outputFile.write(buffer.data(), buffer.size());

    if (!outputFile) {
        std::cerr << "Error writing to the file." << std::endl;
        return 1;
    }

    outputFile.close();

    std::cout << "Signed Key written successfully." << std::endl;

    return 0;
}

int main() {
    int mode = 0;
    std::ifstream src("EXTERNAL_SAVEDATA\\savegame00.sav", std::ios::binary);
    std::ofstream dst("OUTPUT_SAVEDATA\\savegame00.sav", std::ios::binary);
    dst << src.rdbuf();
    src.close();
    dst.close();

    
    std::cout << "Method 1 is Recommended" << std::endl;
    SelectMode:
    std::cout << "Select Method (1/2)" << std::endl;
    std::cin >> mode;
    
    if (mode == 1) {
        hexOffset = 0x00001E40;
        readandwrite();
        hexOffset = 0x00001E50;
        readandwrite();
    }
    else if (mode == 2) {
        hexOffset = 0x00001E50;
        readandwrite();
        hexOffset = 0x00001E60;
        readandwrite();
    }
    else {
        std::cerr << "Method Not Found!!" << std::endl;
        goto SelectMode;
    }

    hexOffset = 0x000FFA90;
    readandwrite();

    return 0;
}
