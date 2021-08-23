# SDLC Activity Based Learning

Visit [Pages for Report -optional](using github.io option)




 | Build | Coverage	 | Static Check | 
 |-----------|-----------|-----------|
 | [![C/C++ CI - Build Status](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/c-cpp.yml) | [![CI-Coverage](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/gcov.yml/badge.svg)](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/gcov.yml) | [![Code Quality - Static Code - Cppcheck](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/cppcheck.yml) |

 | Dynamic Analysis | Git Inspector	 | Unit Testing |
 | -----------|-----------|-----------|
 |  [![CodeQuality Dynamic Code Analysis Valgrind](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/CodeQuality_Dynamic.yml/badge.svg)](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/CodeQuality_Dynamic.yml) | [![Contribution Check - Git Inspector](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/gitinspector.yml/badge.svg)](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/gitinspector.yml) | [![Unit Testing - Unity](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/unity.yml/badge.svg)](https://github.com/AnkitDhiman2/SDLC_28_Project/actions/workflows/unity.yml) |



## Folder Structure

| Folder             | Description                                   |
| ------------------ | --------------------------------------------- |
| `1_Requirements`   | Documents detailing requirements and research |
| `2_Design`         | Documents specifying design details           |
| `3_Implementation` | All code and documentation                    |
| `4_Test_plan`      | Documents with test plans and procedures      |

## Contributors List and Summary

| SF No.   | Name        | Features                 | Issuess Raised | Issues Resolved | No Test Cases | Test Case Pass |
| -------- | ----------- | ------------------------ | -------------- | --------------- | ------------- | -------------- |
| `99005633` | Ankit Kumar | fileEncryptionDecryption.h, FileEncryptionDecryption.c, credentialFuntions.c, sha256.c | Nil            | Nil             | 20            | 20             |
| `99005699` | Anurag Thakur | TextPad password maneger | Nil            | Nil             | 20            | 20             |
| `99005665` | Harish Chappidi | TextPad password maneger | Nil            | Nil             | 20            | 20             |
| `99005640` | Spoorti Naik | Masterfunction.c | Nil            | Nil             | 20            | 20             |
| `99005689` | Purva Baniya | Test Plans, passwordUsernameFormatChecker.c, testTextPadFunctions.c | Nil            | Nil             | 20            | 20             |
| `99005685` | Sumanth Kubasad | Test Plans, Main Readme file, testTextPadFunctions.c, credentialFuntions.c, sha256.c | Nil            | Nil             | 20            | 20             |
| `` | HritujWadyalkar | TextPad password maneger | Nil            | Nil             | 20            | 20             |
| `` | Raj Kumar Edara | , sha256.c | Nil            | Nil             | 20            | 20             |
| `99005653` | Sanjay Chaluvadi | Main Readme file, sha256.c | Nil            | Nil             | 20            | 20             |
| `99005691` | Sumit Bhimte | Github Workflows, common.h, credentialFunctions.h, masterAccountFunctions.h, passwordUsernameFormatChecker.h, sha256.h | Nil            | Nil             | 20            | 20             |

## Challenges Faced and How Was It Overcome

1. It was my first experince with procedural language after a long time -> Learnig material helped a lot
2. Whenever I needed to use GDB I had to create gdb file by mannualy typing the compile command -> solved by creating a debug command in makefile.
3. Its was difficult to manage the overall project -> solved by finishing and testing one part at a time
4. Including files -> later resolved

## How to Run

### - On Linux

1. Type folowing commands in terminal :-

   - sudo apt update

   - sudo apt install build-essentials

2. Open the terminal in Implementation folder.
3. Run the following command :-

   - make
   - make run

### - On Windows

1. Follow [this](https://code.visualstudio.com/docs/languages/cpp) tutorial to install gcc compiler to your windows machine.

2. Open the project Implementation directory inside command prompt.
3. Run the following commands inside command prompt
   - make windows
   - make run_windows

## Learning Resources

1. [markdownCheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
2. [markdownBasics](https://guides.github.com/features/mastering-markdown/)
3. [git inspector](https://github.com/ejwa/gitinspector.git)
4. [github workflow](https://docs.github.com/en/actions/learn-github-action)
