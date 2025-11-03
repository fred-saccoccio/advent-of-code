cls

Write-Host Building lexical analyzer...
C:\Tools\win_flex_bison-2.5.25\win_flex.exe --wincompat lexer_wire_machine.l
Write-Host Building lexical analyzer: FINISHED
Write-Host ##############################################################################################

Write-Host Building syntaxic analyzer...
C:\Tools\win_flex_bison-2.5.25\win_bison.exe grammar_wire_machine.y
Write-Host Building syntaxic analyzer: FINISHED
Write-Host ##############################################################################################

Write-Host Building final exe...
g++ -g -Wall -o wiremachine Scanner.cpp Parser.cpp WireMachine.cpp
Write-Host Building final exe: FINISHED

