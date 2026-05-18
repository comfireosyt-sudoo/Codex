@echo off
setlocal enabledelayedexpansion

echo ======================================
echo   Arcade Hub Build Script

echo ======================================

where make >nul 2>nul
if %errorlevel% neq 0 (
  echo [ERROR] GNU Make not found in PATH.
  goto :fail
)

where arm-none-eabi-g++ >nul 2>nul
if %errorlevel% equ 0 (
  set CXX=arm-none-eabi-g++
  echo [INFO] Using ARM toolchain: !CXX!
) else (
  where g++ >nul 2>nul
  if %errorlevel% neq 0 (
    echo [ERROR] No compatible C++ compiler found.
    goto :fail
  )
  set CXX=g++
  echo [WARN] ARM toolchain not found, using desktop fallback compiler.
)

make clean
if %errorlevel% neq 0 goto :fail

make CXX=!CXX!
if %errorlevel% neq 0 goto :fail

echo [SUCCESS] Build complete.
echo [SUCCESS] Output: output\ArcadeHub.nwa
pause
exit /b 0

:fail
echo [FAIL] Build failed.
pause
exit /b 1
