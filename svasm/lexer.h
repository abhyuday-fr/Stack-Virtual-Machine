#ifndef _LEXER_H_
#define _LEXER_H_

#include <cstdint>
#include <string>
#include <vector>

typedef uint8_t byte;
typedef std::vector<std::string> strings;

enum State : byte { // lexer is a finite state machine
  START,
  READCHAR,
  READBLOCK,
  SKIP,
  DUMP,
  COMMENT,
  END
};

class Lexer {
  bool my_isspace(char c);
  bool isspecial(char c);
  bool isgroup(char c);
  char end_char, beg_char;

public:
  strings lex(std::string s);
};

#endif
