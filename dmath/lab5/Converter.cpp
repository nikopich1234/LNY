#include "Converter.h"
#include "List.h"

int get_priority(string operand){
    if (operand == string(1,'+') or operand == string(1,'-')){
        return 1;
    }
    if (operand == string(1,'*') or operand == string(1,'/')){
        return 2;
    }
    if (operand == string(1,'^')){
        return 3;
    }
    if (operand == string(1,'!')){
        return 4;
    }
    if(operand == string(1,'(')){
        return 0;
    }
    return -1;
}

string InfixToPostfix(string infix){
    string postfix;
    Node* stack = nullptr;
    for(int i = 0; i < infix.length(); i++){
        if(infix[i]=='('){
            push(stack,string(1,'('));
        }
        else if(infix[i] == ')'){
            while(stack != nullptr && show(stack) != string(1,'(')){
                postfix+=show(stack);
                pop(stack);
            }
            if(stack != nullptr){
                pop(stack);
            }
        }
        else if(get_priority(string(1,infix[i])) == -1){
            postfix+=infix[i];
        }
        else if(infix[i] == '!'){
            push(stack, string(1,'!'));
        }
        else{
            while(stack != nullptr && get_priority(show(stack)) >= get_priority(string(1,infix[i]))){
                postfix+=show(stack);
                pop(stack);
            }
            push(stack,string(1,infix[i]));
        }
    }
    while(stack != nullptr){
        postfix+=show(stack);
        pop(stack);
    }
    return postfix;
}

string InfixToPrefix(string infix){
    string prefix;
    Node* stack = nullptr;
    Node* temp_stack = nullptr;
    Node* invert_stack = nullptr;
    for(int i = 0; i < infix.length(); i++){
        push(invert_stack, string(1, infix[i]));
    }
    for(int i = 0; i < infix.length(); i++){
        if(show(invert_stack) == string(1,'(')){
            infix[i] = ')';
        }
        else if(show(invert_stack) == string(1, ')')){
            infix[i] = '(';
        }
        else{
            infix[i] = show(invert_stack)[0];
        }
        pop(invert_stack);
    }
    for(int i = 0; i < infix.length(); i++){
        if(infix[i] == '('){
            push(stack,string(1,'('));
        }
        else if(infix[i] == ')'){
            while(stack != nullptr && show(stack) != string(1,'(')){
                prefix += show(stack);
                pop(stack);
            }
            if(stack != nullptr){
                pop(stack);
            }
        }
        else if(get_priority(string(1,infix[i])) == -1){
            prefix+=infix[i];
        }
        else{
            while(stack != nullptr && get_priority(show(stack)) > get_priority(string(1,infix[i]))){
                prefix+=show(stack);
                pop(stack);
            }
            push(stack,string(1,infix[i]));
        }
    }
    while(stack != nullptr){
        prefix+=show(stack);
        pop(stack);
    }

    for(int i = 0; i < prefix.length(); i++){
        push(invert_stack, string(1,prefix[i]));
    }
    for(int i = 0; i < prefix.length(); i++){
        if(show(invert_stack) == string(1,'(')){
            prefix[i] = ')';
        }
        else if(show(invert_stack) == string(1,')')){
            prefix[i] = '(';
        }
        else{
            prefix[i] = show(invert_stack)[0];
        }
        pop(invert_stack);
    }
    return prefix;
}

string PostfixToInfix(string postfix){
    string infix;
    Node* stack = nullptr;
    for(int i = 0; i < postfix.length(); i++){
        if(get_priority(string(1, postfix[i])) == -1){
            push(stack,string(1,postfix[i]));
        }
        else if(postfix[i] == '!'){
            string operand = show(stack);
            pop(stack);

            infix = "(" + operand + "!)";
            push(stack,infix);
        }
        else{
            string right = show(stack);
            pop(stack);
            string left = show(stack);
            pop(stack);

            infix = "(" + left + postfix[i] + right + ")";
            push(stack,infix);
        }
    }
    infix = show(stack);
    return infix;
}

string PrefixToInfix(string prefix){
    string infix;
    Node* stack = nullptr;
    for(int i = prefix.length()-1; i >= 0; i--){
        if(get_priority(string(1,prefix[i])) == -1){
            push(stack, string(1,prefix[i]));
        }
        else if(prefix[i] == '!'){
            string operand = show(stack);
            pop(stack);
            infix = "(" + operand + "!)";
            push(stack, infix);
        }
        else{
            string left = show(stack);
            pop(stack);

            string right = show(stack);
            pop(stack);
            infix = "(" + left + prefix[i] + right + ")";
            push(stack,infix);
        }
    }
    infix = show(stack);
    return infix;
}