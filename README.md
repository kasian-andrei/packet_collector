# packet_collector
Packet collector on C++.

Server accumulates packets received from client's UDP socket and send them to database every 30 seconds.
Table export_group has main information about set of packets.
Table export_data has information about every packet.
