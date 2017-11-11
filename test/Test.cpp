#include <boost/crc.hpp>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/endian/arithmetic.hpp>

#include "../network/Packet.h"

using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {
    Packet packet = PacketWriter()
            .AddCommand(COLOR)
            .AddByte(255)
            .AddByte(255)
            .AddByte(255)
            .CreatePacket();

    std::vector<char> data = packet.GetData();
    uint32_t length = packet.GetSize();

    boost::crc_32_type crc32;
    crc32.process_bytes(data.data(), length);
    unsigned long crc = crc32.checksum();

    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query("localhost", "1236");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);

    std::vector<boost::asio::mutable_buffer> bufs;
    boost::system::error_code error;
    bufs.push_back(boost::asio::buffer(&length, sizeof(length)));
    bufs.push_back(boost::asio::buffer(data.data(), length));
    bufs.push_back(boost::asio::buffer(&crc, sizeof(crc)));

    boost::asio::write(socket, bufs, error);
    if (error) {
        std::cerr << error.message() << std::endl;
    }

    socket.close();

    return 0;
}