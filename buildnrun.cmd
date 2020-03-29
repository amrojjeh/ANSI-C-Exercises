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
IF %errorlevel% NEQ 0 (
	ECHO Program exited badly errorlevel=%errorlevel%
) ELSE (
	ECHO Program exited successfully
)

CALL clean
POPD
ENDLOCAL
