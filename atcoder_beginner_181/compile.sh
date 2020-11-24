
EXE=".exe"
CPP=".cpp"
g++ -std=c++17 -Wshadow -Wall -o "$1$EXE" "$1$CPP" -O2 -Wno-unused-result
