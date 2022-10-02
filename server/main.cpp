#include "server.h"

void wait(Server & srv);

int main() {
    Server srv(Server::PORT);
    std::thread th(wait, std::ref(srv));
    th.detach();

    while(true) {
        srv.receive_packets();
    }

    return 0;
}

void wait(Server & srv) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::cout << "30 seconds!" << std::endl;
        srv.send_packets("tcp://127.0.0.1:3306", "admin", "1111");
    }
}