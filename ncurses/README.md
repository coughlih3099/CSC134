# NCurses wrapper

## If in codespace
- `sudo apt-get update && sudo apt-get upgrade -y`
- `sudo apt-get install doxygen -y`

## How to build
- Clone the repo
- Move into the ncurses directory
- copypastable command: `mkdir build && cd build && cmake .. && make && make docs`
- ./FinalProject

### View docs
open the index.html in your browser, it's located in build/docs/html/

# How to use
This project is just a wrapper around ncurses that does some of the memory
management for you so that you don't have to worry about it.
The main use is through the wrapper api.

## API
NCursesSession and Window are the two classes I actually have anything meaningful done in.
