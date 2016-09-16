//Gradiant descent learning

#include "AIwork.h"
#include <stdio.h>
#define AND 10
#define OR  20
#define XOR 30

int main(int argc, const char * argv[]) {
    
    AIwork andgate(AND);
    AIwork orgate(OR);
    AIwork xorgate(XOR);
    
    andgate.do_work();
    orgate.do_work();
    xorgate.do_work();
    
    return 0;
}
