#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <exception>
using boost::asio::ip::tcp;
using std::string;

int main()
{
    string ip = "127.0.0.1";
    string port = "8080";
    char buffer[1024];

    boost::asio::io_context io;
    tcp::socket socket(io);
    tcp::resolver resolver(io);
    string message = "Connection Established";

    try
    {
        auto endpoint = resolver.resolve(ip, port);
        std::cout << "Connected to " << ip << ":" << port << std::endl;
        boost::asio::write(socket, boost::asio::buffer(buffer));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Connection not established or closed" << std::endl;

    return 0;
}
