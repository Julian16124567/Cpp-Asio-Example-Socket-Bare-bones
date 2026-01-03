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

    try
    {
      
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}