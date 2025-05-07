#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string getResponse(string input) {
    input = toLower(input); 

    if (input.find("hello") != string::npos || input.find("hi") != string::npos)
        return "Hello! How can I assist you today? Please type 'exit' to quit.";
    else if (input.find("price") != string::npos)
        return "Our product prices start from $49.99. Would you like to know more?";
    else if (input.find("refund") != string::npos)
        return "To request a refund, please visit the support section of our website or contact us at support@company.com.";
    else if (input.find("support") != string::npos)
        return "You can reach our support team at support@company.com or call our helpline at 123-456-7890.";
    else if (input.find("delivery") != string::npos || input.find("shipping") != string::npos)
        return "Standard delivery takes 3–5 business days. You can track your order on our website.";
    else if (input.find("call") != string::npos)
        return "Sure, one of our customer service agents will call you soon. Please share your phone number.";
    else if (input.find("exit") != string::npos)
        return "Goodbye! Have a great day!";
    else
        return "I'm sorry, I didn't understand that. Can you rephrase your query?";
}

int main() {
    cout << "🤖 Welcome to Customer Service Chatbot! Type 'exit' to quit.\n";

    string userInput;

    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        string response = getResponse(userInput);
        cout << "Bot: " << response << endl;

        if (toLower(userInput) == "exit") {
            break;
        }
    }

    return 0;
}
