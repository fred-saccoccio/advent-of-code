C:\Tools\win_flex_bison-2.5.25\win_flex.exe --wincompat lexer_wire_machine.l
C:\Tools\win_flex_bison-2.5.25\win_bison.exe grammar_wire_machine.y
g++ -o calc Scanner1.cpp Parser1.cpp

