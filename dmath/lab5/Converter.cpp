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
        if(infix[i] == ' '){
            continue;
        }
        if(infix[i] == '('){
            push(stack,string(1,'('));
        }
        else if(infix[i] == ')'){
            while(stack != nullptr && show(stack) != string(1,'(')){
                postfix += show(stack) + " ";
                pop(stack);
            }
            if(stack != nullptr){
                pop(stack);
            }
        }
        else if(get_priority(string(1,infix[i])) == -1){
            while(i < infix.length() and get_priority(string(1,infix[i])) == -1 and infix[i] != ' ' and infix[i] != ')'){
                postfix += infix[i];
                i++;
            }
            i--;
            postfix += " ";
        }
        else if(infix[i] == '!'){
            push(stack, string(1,'!'));
        }
        else{
            while(stack != nullptr && get_priority(show(stack)) >= get_priority(string(1,infix[i]))){
                postfix += show(stack) + " ";
                pop(stack);
            }
            push(stack,string(1,infix[i]));
        }
    }
    while(stack != nullptr){
        postfix += show(stack) + " ";
        pop(stack);
    }
    if(postfix.length() > 0){
        postfix.pop_back();
    }
    return postfix;
}

string InfixToPrefix(string infix){
    string prefix;
    Node* stack = nullptr;
    for(int i = infix.length()-1; i >= 0; i--){
        if(infix[i] == ' '){
            continue;
        }
        if(infix[i] == ')'){
            push(stack,string(1,'('));
        }
        else if(infix[i] == '('){
            while(stack != nullptr && show(stack) != string(1,'(')){
                prefix = show(stack) + " " + prefix;
                pop(stack);
            }
            if(stack != nullptr){
                pop(stack);
            }
        }
        else if(get_priority(string(1,infix[i])) == -1){
            string number;
            while(i >= 0 and get_priority(string(1,infix[i])) == -1 and infix[i] != ' ' and infix[i] != ')'){
                number = infix[i] + number;
                i--;
            }
            i++;
            prefix = number + " " + prefix;
        }
        else{
            while(stack != nullptr && get_priority(show(stack)) > get_priority(string(1,infix[i]))){
                prefix = show(stack) + " " + prefix;
                pop(stack);
            }
            push(stack,string(1,infix[i]));
        }
    }
    while(stack != nullptr){
        prefix = show(stack) + " " + prefix;
        pop(stack);
    }
    if(prefix.length() > 0){
        prefix.pop_back();
    }
    return prefix;
}

string PostfixToInfix(string postfix){
    string infix;
    Node* stack = nullptr;
    for(int i = 0; i < postfix.length(); i++){
        if(postfix[i] == ' '){
            continue;
        }
        if(get_priority(string(1, postfix[i])) == -1){
            string number;
            while(i < postfix.length() and postfix[i] != ' ' and get_priority(string(1,postfix[i])) == -1){
                number += postfix[i];
                i++;
            }
            i--;
            push(stack, number);
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
        if(prefix[i] == ' '){
            continue;
        }
        if(get_priority(string(1,prefix[i])) == -1){
            string number;
            while(i >= 0 and prefix[i] != ' ' and get_priority(string(1,prefix[i])) == -1){
                number = prefix[i] + number;
                i--;
            }
            i++;
            push(stack, number);
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

double PostfixEvaluate(string postfix){
    Node* stack = nullptr;
    for(int i = 0; i < postfix.length(); i++){
        if(postfix[i] == ' '){
            continue;
        }
        if(get_priority(string(1,postfix[i])) == -1){
            string number;
            while(i < postfix.length() and postfix[i] != ' ' and get_priority(string(1,postfix[i])) == -1){
                number += postfix[i];
                i++;
            }
            i--;
            push(stack, number);
        }
        else if(postfix[i] == '!'){
            double operand = stod(show(stack));
            pop(stack);

            double result = 1;
            for(int j = 2; j <= operand; j++){
                result *= j;
            }
            push(stack, to_string(result));
        }
        else{
            double right = stod(show(stack));
            pop(stack);
            double left = stod(show(stack));
            pop(stack);

            double result = 0;
            if(postfix[i] == '+'){
                result = left + right;
            }
            else if(postfix[i] == '-'){
                result = left - right;
            }
            else if(postfix[i] == '*'){
                result = left * right;
            }
            else if(postfix[i] == '/'){
                if(right == 0){
                    throw runtime_error("Division by zero");
                }
                result = left / right;
            }
            else if(postfix[i] == '^'){
                result = pow(left, right);
            }
            push(stack, to_string(result));
        }
    }
    double answer = stod(show(stack));
    pop(stack);
    return answer;
}

double PrefixEvaluate(string prefix){
    Node* stack = nullptr;
    for(int i = prefix.length()-1; i >= 0; i--){
        if(prefix[i] == ' '){
            continue;
        }
        if(get_priority(string(1,prefix[i])) == -1){
            string number;
            while(i >= 0 and prefix[i] != ' ' and get_priority(string(1,prefix[i])) == -1){
                number = prefix[i] + number;
                i--;
            }
            i++;
            push(stack, number);
        }
        else if(prefix[i] == '!'){
            double operand = stod(show(stack));
            pop(stack);

            double result = 1;
            for(int j = 2; j <= operand; j++){
                result *= j;
            }
            push(stack, to_string(result));
        }
        else{
            double left = stod(show(stack));
            pop(stack);
            double right = stod(show(stack));
            pop(stack);

            double result = 0;
            if(prefix[i] == '+'){
                result = left + right;
            }
            else if(prefix[i] == '-'){
                result = left - right;
            }
            else if(prefix[i] == '*'){
                result = left * right;
            }
            else if(prefix[i] == '/'){
                if(right == 0){
                    throw runtime_error("Division by zero");
                }
                result = left / right;
            }
            else if(prefix[i] == '^'){
                result = pow(left, right);
            }
            push(stack, to_string(result));
        }
    }
    double answer = stod(show(stack));
    pop(stack);
    return answer;
}