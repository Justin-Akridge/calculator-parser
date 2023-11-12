#include <iostream>
#include "token-stream.hpp"
#include "token.h"
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
