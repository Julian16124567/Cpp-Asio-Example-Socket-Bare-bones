#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <exception>
using boost::asio::ip::tcp;
using std::string;

int main()
{
    static string ip = "127.0.0.1";
    static string port = "6060";

    boost::asio::io_context io;
    tcp::socket socket(io);
    tcp::resolver resolver(io);
    string message = "Message from Server";
    char buffer[1024];

    try
    {
        std::cout << "Waiting for Client..." << std::endl;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), std::stoi(port)));
        acceptor.accept(socket);
        std::cout << "Connection established..." << std::endl;

        size_t len = socket.read_some(boost::asio::buffer(buffer));
        string output(buffer, len);
        std::cout << "Client sent an message: " << output << std::endl;

        boost::asio::write(socket, boost::asio::buffer(message));
        std::cout << "Message sent to Client..." << std::endl;

        socket.close();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Connection not established or closed" << std::endl;

    return 0;
}