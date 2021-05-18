using namespace std;
#include <iostream>

const char * token_image(int tok);


#include "List.h"

extern int HW;

typedef struct SymbolBlock * Symbol;

typedef ListPair<Symbol> SymbolPair;
typedef SymbolPair * SymbolList;

typedef struct TypeBlock * Type;

typedef ListPair<Type> TypePair;
typedef TypePair * TypeList;

typedef ListPair<string> stringPair;
typedef stringPair * stringList;

typedef struct OperBlock * Oper;


#include "error.h"

#include "Symbol.h"
#include "SymTab.h"

#include "Inst.h"
#include "registers.h"
#include "offsets.h"

#include "Expr.h"
#include "Stmt.h"
#include "StmtLabels.h"

#include "SymUtils.h"
#include "TypeUtils.h"
#include "GenUtils.h"
#include "StmtUtils.h"

void do_homework(StmtList L);

#define STR_NAME "__str__"
#define CONSTRUCTOR_NAME "__init__"
#define RETURN_NAME "__RETURN__"
