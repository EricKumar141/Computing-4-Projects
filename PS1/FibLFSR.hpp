#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
using namespace std;

class FibLFSR {
public:
FibLFSR(string seed);
~FibLFSR(){//destructor
    delete bits;
}
int step();
int generate(int k);
friend std::ostream& operator<< (std::ostream &out, const FibLFSR &FibLFSR);
private:
int *bits;
};
