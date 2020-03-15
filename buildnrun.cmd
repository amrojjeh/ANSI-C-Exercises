@ECHO off
SETLOCAL ENABLEEXTENSIONS
PUSHD "%~dp1"
call build %1
IF EXIST "%~n1.exe" (
	SET PROGRAM="%~n1.exe"
	SHIFT
	CLS
	GOTO run
) ELSE (
	EXIT /B 1
)

:run
if "%1"=="" goto after_loop
set RESTVAR=%RESTVAR% %1
shift
goto run
:after_loop
%PROGRAM% %RESTVAR%

CALL clean
POPD
ENDLOCAL
