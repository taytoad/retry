# retry
A simple command repeater

## Building

### Requirements

- C++17
- CMake

### CLI

```
    git clone https://github.com/taytoad/retry && cd retry
    mkdir build && cd build
    
    (Most build systems work. Set with -G "build system")
    cmake -S ../ -B ./
    
```

### GUI
```
    Clone the repo with the command line or download directly from github and extract.
    Follow instructions on the GUI.
```

## Usage

retry "[Command]" -options

#### Example:

retry checkUpdate -r 2 -t 200

#### Parameters
* -r|-R: number of retries if it fails
* -t|-T: time between the command to run it again\n
* -h|-H: help menu

