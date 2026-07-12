#ifndef STACK_VM_H
#define STACK_VM_H

#include <cstdint>
#include <vector>

// let's do this >:)

typedef int32_t i32;

struct StackVM {
  i32 pc = 100; // Program Counter
  i32 sp = 0;   // Stack Pointer
  std::vector<i32> memory;
  i32 typ = 0;
  i32 dat = 0;
  i32 running = 1;

public:
  StackVM();
  void run();
  void loadProgram(std::vector<i32> prog);

private:
  i32 getType(i32 instruction);
  i32 getData(i32 instruction);
  void fetch();
  void decode();
  void execute();
  void doPrimitive();
};

#endif
