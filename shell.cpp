#include "parser.h"
#include "scanner.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
    string input, part, query = "";
    Parser *parser;
    stringstream stream;
    while (true) {
        while (input.back() != '.' || input == "")
        {
            if (input == "" ){
              cout << "?- ";
            }else{
              cout << "|  ";
            }

            getline(cin, input);
            stream << input;
            while ( stream >> part) query += part ;
            //清理掉stream的內容
            stream.str("");
            stream.clear();
        }
        //結束
        if ( query == "halt.") break;

        parser = new Parser(Scanner(query));
        try {
          parser->buildExpression();
          cout << parser->result() << endl;
        }catch( string &errorMsg) {
          cout << errorMsg << endl;
        }
        query = "";
        input = "";
    }
}
