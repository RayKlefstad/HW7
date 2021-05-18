.SUFFIXES: .py .out
CXX = g++
CXXFLAGS = -std=c++11 -ggdb -Wall
LDFLAGS = -ggdb
BISONFLAGS = -d
O = parse.tab.o Expr.o SymTab.o SymUtils.o Stmt.o Symbol.o gen.o assign.o jumpIf.o Inst.o registers.o emit.o genStmt.o StmtLabels.o StmtUtils.o offsets.o
H = -7

parser: $O
	$(CXX) $(LDFLAGS) $O -o parser

all.h: List.h error.h Symbol.h SymTab.h Inst.h registers.h Expr.h Stmt.h machine.h parse.tab.h SymUtils.h TypeUtils.h GenUtils.h tokens.h StmtUtils.h offsets.h
	touch all.h

parse.tab.cpp: parse.y
	bison $(BISONFLAGS) parse.y; /bin/mv parse.tab.c parse.tab.cpp

scan.cpp: scan.l
	flex -t scan.l > scan.cpp

parse.tab.o: parse.tab.cpp scan.cpp main.cpp all.h
Expr.o: all.h
Stmt.o: all.h
SymTab.o: all.h
SymUtils.o: all.h
Symbol.o: all.h
assign.cpp:  all.h tokens.h
emit.cpp:  all.h tokens.h
gen.cpp:  all.h
jumpIf.cpp:   all.h tokens.h
Inst.cpp:  error.h Inst.h tokens.h registers.h
registers.cpp: error.h Inst.h registers.h

T = samples/arith.py samples/assign.py samples/cast.py samples/cast2.py samples/check_num.py samples/class1.py samples/class2.py samples/class2ERROR.py samples/class3ERROR.py samples/classERROR.py samples/class.py samples/decl.py samples/def.py samples/empty.py samples/for.py samples/if.py samples/ifsERROR.py samples/in.py samples/searchlist.py samples/string.py samples/test1.py samples/while.py

clean:
	/bin/rm -f $(T:.py=.out)

veryclean: clean
	/bin/rm -f parser scan.cpp parse.tab.cpp parse.output core.* $O test.out


.py.out:
	./parser $H < $< > $@

test: parser $(T:.py=.out)

