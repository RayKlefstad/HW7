extern Expr RETURN_REGISTER_EXPR;
extern Expr TOS_REGISTER_EXPR;
extern Oper RETURN_REGISTER_OPER;

void beginFunc(string name);
void endFunc();

void funcReturn(Expr expr);

void beginLoop(Expr init, Expr cond, Expr advance, Stmt body);
void endLoop(Expr init, Expr cond, Expr advance, Stmt body);

void breakLoop();
void continueLoop();

void beginIf(Expr cond, Stmt trueStmt);
Stmt beginElif(Stmt ifStmt);
void endIf();
