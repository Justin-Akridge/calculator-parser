#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H
#include <string>
#include "token.hpp"

class Token_stream {
public:
  bool full;
  Token buffer;
  Token_stream();
  Token get();
  void putback(Token t);
  void error(std::string);
};

#endif // TOKEN_STREAM_H
