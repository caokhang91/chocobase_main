@echo off
setlocal

echo [🔧] Building backend...
cd backend
gradlew.bat build > nul

echo [🚀] Starting Vert.x backend...
start "Vert.x Backend" cmd /c "gradlew.bat run > ..\backend.log 2>&1"
cd ..

timeout /t 2 > nul

echo [🎮] Starting SDL2 frontend...
cd frontend
make
chocobase_client.exe

echo [🧹] Done. You may need to manually close the Vert.x terminal if it stays open.
pause
