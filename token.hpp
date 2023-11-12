#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "token-stream.hpp"

class Token {
public:
  char kind;
  double value;
  Token();
  Token(char);
  Token(char, double);
  double primary(Token_stream ts);
  double term(Token_stream);
  double expression(Token_stream);
  void error(std::string);
};

#endif //TOKEN_H 