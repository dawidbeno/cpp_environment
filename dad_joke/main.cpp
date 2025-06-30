#include <iostream>
#include <cpr/cpr.h>           // The cpr library for HTTP requests
#include <nlohmann/json.hpp>   // The nlohmann library for JSON parsing

int main() {
    // The API requires a specific "Accept" header to send us JSON
    cpr::Header headers = {{"Accept", "application/json"}};
    
    // Make a GET request to the dad joke API
    cpr::Response r = cpr::Get(cpr::Url{"https://icanhazdadjoke.com/"}, headers);

    // Check if the request was successful (HTTP status code 200 OK)
    if (r.status_code == 200) {
        // Parse the response text as JSON
        // The 'nlohmann::json' object works like a standard C++ map or dictionary
        nlohmann::json joke_json = nlohmann::json::parse(r.text);
        
        // Extract the value associated with the "joke" key
        std::string joke = joke_json["joke"];
        
        // Print the joke!
        std::cout << "\nHere is your dad joke:\n\n" << joke << "\n\n";
    } else {
        // If the request failed, print an error
        std::cerr << "Error: Could not fetch joke. Status code: " << r.status_code << std::endl;
    }

    return 0;
}