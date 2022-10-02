#include "client.h"

Client::Client(const uint16_t srcPort, const std::string & data) {
    socket.bind(srcPort);
    packet << data;
}

void Client::send_packet(const sf::IpAddress & destIP, const uint16_t  destPort) {
    socket.send(packet, destIP, destPort);
}