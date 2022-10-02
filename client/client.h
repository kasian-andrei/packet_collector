#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Network.hpp>

class Client {
private:
    sf::UdpSocket socket;
    sf::Packet packet;
public:
    explicit Client (uint16_t  srcPort = 49152, const std::string & data = "");
    void send_packet(const sf::IpAddress & destIP, uint16_t destPort);
};

#endif


