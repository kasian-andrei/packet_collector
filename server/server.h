#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Network.hpp>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class Server {
public:
    static const uint16_t PORT;
    static const sf::IpAddress IP;
private:
    struct AllData {
        std::string ip;
        uint16_t port;
        std::string srcIP;
        uint16_t srcPort;
        std::string data;
    };

    sf::UdpSocket socket;
    std::vector<AllData> buffer;
public:
    explicit Server(uint16_t port = PORT);
    void receive_packets();
    void send_packets(const std::string & server, const std::string & username, const std::string & password);
};

#endif

