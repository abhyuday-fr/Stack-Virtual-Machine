#include "stack-vm.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <binary-filename>\n";
  }

  std::ifstream r(argv[1], std::ios::binary);
  i32 i;
  std::vector<i32> prog;

  while (r.read((char *)&i, sizeof(i))) {
    prog.push_back(i);
  }

  StackVM VM;
  VM.loadProgram(prog);
  VM.run();
  return 0;
}
