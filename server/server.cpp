#include "server.h"

const uint16_t Server::PORT = 50500;
const sf::IpAddress Server::IP = "127.0.0.1";


Server::Server(const uint16_t port) {
    socket.bind(port);
}

void Server::receive_packets() {
    sf::IpAddress receivedIP;
    uint16_t receivedPort;
    sf::Packet receivedPacket;

    socket.receive(receivedPacket, receivedIP, receivedPort);

    AllData pack;
    pack.ip = IP.toString();
    pack.port = PORT;
    pack.srcIP = receivedIP.toString();
    pack.srcPort = receivedPort;
    receivedPacket >> pack.data;

    buffer.push_back(pack);
}


void Server::send_packets(const std::string & server, const std::string & username, const std::string & password) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect(server, username, password);

        con->setSchema("task");
        pstmt = con->prepareStatement("INSERT INTO export_group(total_packets, total_bytes) VALUES(?,?)");

        int sum = 0;
        for (AllData & pack : buffer) {
            sum += sizeof(pack.data);
        }

        pstmt->setInt(1, buffer.size());
        pstmt->setInt(2, sum);
        pstmt->execute();
        delete pstmt;
        std::cout << "was inserted 1 row in export_group" << std::endl;

        for (AllData & pack : buffer) {
            stmt = con->createStatement();
            res = stmt->executeQuery("SELECT MAX(id) FROM export_group");
            pstmt = con->prepareStatement("INSERT INTO export_data(group_id, data_length, source_address, destination_address, source_port, destination_port) VALUES(?,?,?,?,?,?)");
            res->next();
            pstmt->setInt(1, res->getInt(1));
            pstmt->setInt(2, pack.data.size());
            pstmt->setString(3, pack.srcIP);
            pstmt->setString(4, pack.ip);
            pstmt->setInt(5, pack.srcPort);
            pstmt->setInt(6, pack.port);
            pstmt->execute();
            //delete stmt;
            delete pstmt;
            delete res;
        }
        std::cout << "was inserted " << buffer.size() << " rows in export_data" << std::endl;

        buffer.clear();
        delete con;
    } catch (sql::SQLException &e) {
        std::cout << "error: " << e.what() << std::endl;
        std::cout << "error code: " << e.getErrorCode() << std::endl;
    }
}



