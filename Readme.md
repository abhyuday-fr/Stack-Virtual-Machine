# Stack-based-VM

This is a stack based cpu simulator made in CPP. It is very basic for now but expect more user friendly, robust, fast version soon.

## Usage Instructions

* In svasm directory, execute `make` and a *svasm* exectuable will be made.
* run `./svasm test.svasm` and a *out.bin* binary file will be made.
* move the *out.bin* file to the stack-vm directory and run `make` in that directory.
* run `./stack-vm out.bin` and you will notice that the output will be the operations done for the instructions in [test file](svasm/test.svasm)


Go ahead and do changes in the [test file](svasm/test.svasm), follow the above instructions and enjoy this Finite State Machine ^_^
