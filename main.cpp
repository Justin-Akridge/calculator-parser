#include <iostream>
#include "token.hpp"
#include "token-stream.hpp"

int main() {
  Token_stream ts;
  Token t;
  double val = 0;
  while (std::cin) {
    t = ts.get();
    if (t.kind == 'q') break;
    if (t.kind == ';')
      std::cout << "= " << val << '\n';
    else
      ts.putback(t);
    val = t.expression(ts);
  }
}
