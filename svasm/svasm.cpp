#include "lexer.h"
#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

typedef uint32_t i32;

std::vector<i32> compileToInstructions(strings s);
bool isInteger(std::string s);
i32 mapToNumber(std::string s);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <svasm-filename>\n";
    exit(1);
  }

  std::ifstream infile;
  infile.open(argv[1]);
  if (!infile.is_open()) {
    std::cerr << "Error: Unable to open file " << argv[1] << "\n";
    exit(1);
  }
  std::string line, contents;
  while (getline(infile, line)) {
    contents += line + "\n";
  }
  infile.close();

  // parse the file
  Lexer lexer;
  strings lexeme = lexer.lex(contents);

  // compile to binary
  std::vector<i32> instructions = compileToInstructions(lexeme);

  // wrtie to binary file
  std::ofstream ofile;
  ofile.open("out.bin", std::ios::binary);
  for (i32 i = 0; i < instructions.size(); i++) {
    ofile.write(reinterpret_cast<char *>(&instructions[i]), sizeof(i32));
  }
  ofile.close();

  return 0;
}

std::vector<i32> compileToInstructions(strings s) {
  std::vector<i32> instructions;
  for (i32 i = 0; i < s.size(); i++) {
    if (isInteger(s[i]))
      instructions.push_back(std::stoi(s[i]));
    else {
      i32 instruction = mapToNumber(s[i]);
      if (instruction != -1)
        instructions.push_back(instruction);
      else
        std::cerr << "Error: Invalid instruction [" << instruction << "]\n";
    }
  }
  instructions.push_back(0x40000000); // always halt at the end
  return instructions;
}

bool isInteger(std::string s) {
  for (i32 i = 0; i < s.length(); i++) {
    if (!isdigit(s[i]))
      return false;
  }
  return true;
}

i32 mapToNumber(std::string s) {
  if (s == "+")
    return 0x40000001;
  else if (s == "-")
    return 0x40000002;
  else if (s == "*")
    return 0x40000003;
  else if (s == "/")
    return 0x40000004;

  return -1; // invalid instruction
}
