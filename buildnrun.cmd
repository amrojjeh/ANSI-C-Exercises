@ECHO off
SETLOCAL ENABLEEXTENSIONS
PUSHD "%~dp1"
call build %1
IF EXIST "%~n1.exe" "%~n1.exe"
CALL clean
POPD
ENDLOCAL
