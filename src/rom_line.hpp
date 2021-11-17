#ifndef ROM_LINE_HPP
#define ROM_LINE_HPP

#include <vector>
#include "rom_command.hpp"

using namespace std;

    typedef struct {
        string fileName;
        uint64_t line;
        vector<romCommand *> cmdBefore;
        bool inA;
        bool inB;
        bool inC;
        bool inD;
        bool inE;
        bool inSR;
        bool inCTX;
        bool inSP;
        bool inPC;
        bool inGAS;
        bool inMAXMEM;
        bool inSTEP;
        bool bConstPresent;
        uint64_t CONST; // TODO: Check type (signed)
        bool mRD;
        bool mWR;
        bool hashRD;
        bool hashWR;
        bool hashE;
        bool JMP;
        bool JMPC;
        bool bOffsetPresent;
        int64_t offset; // TODO: Check type (signed)
        bool useCTX; // TODO: Shouldn't it be isCTX or isContext?
        bool isCode;
        bool isStack;
        bool isMem;
        //bool bIncPresent; // TODO: Is it a flag or an offset?
        //int64_t inc; // TODO: Check type (signed)
        bool inc;
        bool dec;
        bool bIndPresent; // TODO: Is it a flag or an offset?
        int64_t ind; // TODO: Check type (signed)
        bool inFREE;
        romCommand freeInTag;
        bool ecRecover;
        bool shl;
        bool shr;
        bool neg;
        bool assert;
        bool setA;
        bool setB;
        bool setC;
        bool setD;
        bool setE;
        bool setSR;
        bool setCTX;
        bool setSP;
        bool setPC;
        bool setGAS;
        bool setMAXMEM;
        bool sRD;
        bool sWR;
        bool arith;
        bool bin;
        bool comparator;
        bool opcodeRomMap;
        vector<romCommand *> cmdAfter;

    } tRomLine;

#endif