//LogCon.cpp

#include "LogCon.h"
#include <iostream>
#include <string>

bool NOT(bool a){
    if(a){
        return false;
    }
    else{
        return true;
    }
}

bool AND(bool a, bool b){
    if(a){
        if(b){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool OR(bool a, bool b){
    if(a){
        return true;
    }
    else{
        if(b){
            return true;
        } else{
            return false;
        }
    }
}

bool IMP(bool a, bool b){
    if(a == 1 && b == 0){
        return false;
    }
    else{
        return true;
    }
}

bool EQU(bool a, bool b){
    if(a){
        if(b){
            return true;
        }
        return false;
    }
    else{
        if(b){
            return false;
        }
        return true;
    }
}

bool XOR(bool a, bool b){
    if(a){
        if(b){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        if(b){
            return true;
        }
        else{
            return false;
        }
    }
}

bool F15(bool a, bool b, bool c){
    return IMP(AND(IMP(a,b),NOT(OR(c,a))), OR(NOT(a), NOT(b)));
}
