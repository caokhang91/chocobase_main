#!/bin/bash

echo "🔧 Building backend..."
cd backend
./gradlew build > /dev/null

echo "🚀 Starting Vert.x backend..."
nohup ./gradlew run > ../backend.log 2>&1 &
BACKEND_PID=$!
cd ..

sleep 1

echo "🎮 Starting SDL2 frontend..."
cd frontend
make
./chocobase_client

echo "🧹 Shutting down backend (PID $BACKEND_PID)..."
kill $BACKEND_PID
