# Tree Depth Project

Библиотека для вычисления [глубины дерева(tree depth)](https://ru.wikipedia.org/wiki/Глубина_дерева_(теория_графов)). 

Алгоритм основан на решении [sallow](https://github.com/marcinwrochna/sallow) c соревнования [PACE 2020](https://pacechallenge.org/2020/td/).

## Building

У проекта лишь одна внешняя зависимость [Microsoft's GSL](https://github.com/microsoft/GSL). 

Необходимы CMake ≥ 3.13 и g++ ≥ 7 или clang ≥ 4 (поддержка C++17).

Сами функции находятся в файле [tree_depth.hpp](https://github.com/src-elimination-tree-project/tree-depth-project/blob/main/tree_depth.hpp), который нужно подключить.

Также нужно все пролинковать на подобии [CMakeLists.txt](https://github.com/src-elimination-tree-project/tree-depth-project/blob/main/CMakeLists.txt).

## Functionality

Доступны два варинта поиска глубины дерева: 
* с лимитом по времени для работы (если алгоритм не смог найти адекватного решения в указанное время, он будет работь пока не найдет какое-нибудь)
* либо вариант, когда алгоритм будет работать до тех пор пока есть улучшения и алгоритм не застопориться

В [test-sallow.cpp](https://github.com/src-elimination-tree-project/tree-depth-project/blob/main/test-sallow.cpp) можно попробовать работу библиотеки.
