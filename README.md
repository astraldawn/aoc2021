# AOC 2021

In C++

## Setup

1. Install g++
2. Get vscode code runner extension, in settings, check run in terminal + save files on run
3. Run code with `ctrl + alt + n`

## IDE

vscode sttings for c++17

```
"code-runner.executorMap": {
    "cpp": "cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
}
```