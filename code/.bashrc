alias c='g++ -Wall -Wconversion -Wfatal-errors -g -std=c++17 -fsanitize=undefined,address'
e() { c "$1" -o "./.build/${1%.*}" && ./.build/"${1%.*}"; }
