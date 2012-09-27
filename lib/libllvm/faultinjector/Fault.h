#include "llvm/Pass.h"
#include <llvm/Instructions.h>
#include "llvm/Support/CommandLine.h"
#include <llvm/Module.h>

using namespace llvm;

class FaultType{
public:
    virtual bool isApplicable(Instruction *I) = 0;
    virtual void apply(Instruction *I) = 0;
    virtual char *getName() = 0;
    virtual int getProbability() = 0;

    void addToModule(Module &M);

    GlobalVariable *fault_count;
};

#define FAULT_MEMBERS \
    bool isApplicable(Instruction *I); \
    void apply(Instruction *I); \
    static cl::opt<int> prob;\
    char *getName();\
    int getProbability(){\
        return prob;\
    }

class SwapFault : public FaultType {
    public: FAULT_MEMBERS
};


