EXE=".exe"
CPP=".cpp"
g++ -std=c++14 -Wshadow -Wall -o "$1$EXE" "$1$CPP" -g -g -fsanitize=address -fsanitize=undefined -Wextra -O2 -pedantic -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -DLOCAL
