#include "client.h"

int main() {
    std::string data;
    std::cout << ">";
    std::getline(std::cin, data);
    while (data != "q") {
        Client client(49100, data);
        client.send_packet("127.0.0.1", 50500);
        std::cout << "--data was sent--" << std::endl << std::endl;
        std::cout << ">";
        std::getline(std::cin, data);
    }

    return 0;
}