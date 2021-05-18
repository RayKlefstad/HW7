#include "all.h"
#include <stack>
#include <map>
using namespace std;
static stack<map<string, Oper>> labels;

void enterLabelScope()
{
    labels.push(map<string, Oper>());
}

void exitLabelScope()
{
    if (labels.empty())
        compiler_error("exitLabelScope() on empty stack");
    labels.pop();
}

Oper findLabel(string name)
{
    auto& m = labels.top();
    return m[name];
}

Oper defineLabelWithValue(string name, Oper label)
{
    auto& m = labels.top();
    m[name] = label;
    return label;
}

Oper defineLabel(string name)
{
    return defineLabelWithValue(name, newLabel());
}

// returns old value, sets new value
Oper redefineLabel(string name)
{
    Oper oldValue = findLabel(name);
    defineLabelWithValue(name, newLabel());
    return oldValue;
}
