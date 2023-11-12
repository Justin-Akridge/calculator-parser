#include <iostream>
#include "token.hpp"
#include "token-stream.hpp"

void Token::error(std::string s) {
  std::cerr << s << '\n';
}

Token::Token()
  :kind(), value(0) {};

Token::Token(char ch)
  :kind(ch), value(0) {};

Token::Token(char ch, double value)
  :kind(ch), value(value) {};

double Token::primary(Token_stream &ts) {
  Token t = ts.get();
  switch (t.kind) {
    case '(':
      {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != ')') error("Expected ')'");
        return d;
      }
    case '8':
      return t.value;
    default:
      error("primary expected");
  }
}

double Token::term(Token_stream &ts) {
  double left = primary(ts);
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
      case '*':
        left *= primary(ts);
        t = ts.get();
        break;
      case '/':
        {
          double d = primary(ts);
          if (d == 0)
            error("Divide by zero");
          left /= d; 
          t = ts.get();
          break;
        }
      default:
        ts.putback(t);
        return left;
    }
  }
}

double Token::expression(Token_stream &ts) {
  double left = term(ts);
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
      case '+':
        left += term(ts);
        t = ts.get();
        break;
      case '-':
        left -= term(ts);
        t = ts.get();
        break;
      default:
        ts.putback(t);
        return left;
    }
  }
}

