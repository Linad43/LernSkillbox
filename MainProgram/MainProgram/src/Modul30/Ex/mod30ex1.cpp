#include "header_modul30.h"
#include "cpr/cpr.h"

cpr::Response getResponse() {
    return cpr::Get(cpr::Url("http://httpbin.org/get"));
}

cpr::Response postResponse() {
    return cpr::Post(cpr::Url("http://httpbin.org/post"));
}

cpr::Response putResponse() {
    return cpr::Put(cpr::Url("http://httpbin.org/put"));
}

cpr::Response deleteResponse() {
    return cpr::Delete(cpr::Url("http://httpbin.org/delete"));
}

cpr::Response patchResponse() {
    return cpr::Patch(cpr::Url("http://httpbin.org/patch"));
}


void mod30ex1() {
    std::cout << "1. Реализовать пользовательские запросы.\n";

    // cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"),
    //     cpr::Header({{"user-agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 YaBrowser/25.12.0.0 Safari/537.36"},
    //     {"Accept", "text/html"}}));
    // std::cout << r.text << std::endl;
    // std::string name, city;
    // std::cin>>name>>city;
    // cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),
    //     cpr::Payload({{"name", name.c_str()},{"city", city.c_str()}}));
    // std::cout << r.text << std::endl;

    std::string input;

    while (true) {
        std::cout<<"Input command: ";
        std::cin >> input;
        cpr::Response response;
        if (input == "get") {
            response = getResponse();
        }
        else if (input == "post") {
            response = postResponse();
        }
        else if (input == "put") {
            response = putResponse();
        }
        else if (input == "delete") {
            response = deleteResponse();
        }
        else if (input == "patch") {
            response = patchResponse();
        }
        else if (input == "exit") {
            break;
        }
        else {
            continue;
        }
        std::cout << response.text << std::endl;
    }
}
