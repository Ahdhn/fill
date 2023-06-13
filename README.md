# Fill: Giving Colors to Vertices! [![Windows](https://github.com/Ahdhn/fill/actions/workflows/Windows.yml/badge.svg)](https://github.com/Ahdhn/fill/actions/workflows/Windows.yml) [![Ubuntu](https://github.com/Ahdhn/fill/actions/workflows/Ubuntu.yml/badge.svg)](https://github.com/Ahdhn/fill/actions/workflows/Ubuntu.yml)

## Requirements 
For Ubuntu
```
sudo apt-get update
sudo apt-get install -y xorg-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

## Build 
```
mkdir build
cd build 
cmake ..
```
Depending on the system, this will generate either a `.sln` project on Windows or a `make` file for a Linux system. 


## Run
```
fill.exe path\to\mesh path\to\permuation\file 
```


## Example 

```
fill.exe ..\..\input\gargoyle.obj ..\..\input\gargoyle_permutation.txt
```

<p align="center">
    <img src="./input\gargoyle.PNG" width="60%"><br>
</p>