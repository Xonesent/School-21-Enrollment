Реализация графа с помощью польской нотации со следующими настройками. Программа разработана на языке Си, в структурном стиле и работает из терминала, а также протестирована анализатором cppcheck и стилевым линтером clang-format

* Условия
Размер поля для вывода графиков - прямоугольник 25 на 80 точек.
Область определения - [0; 4 Пи]
Область значений - [-1; 1]
Ориентация координатной плоскости - ось ординат направлена вниз, ось абсцисс - направо.
Центр координат - середина левой границы (точка {0, 13}).
Рисовать оси не нужно.
Ничего кроме графика выводиться не должно.
Значения округляются по правилам математики.

* Графика
График должен быть выведен с помощью знаков "Звездочек" для линии графика и "." для всего остального пространства экрана. ==***

* Модули
Разбор строки выражения и получение списка лексем.
Перевод в польскую нотацию и вычисление по ней.
Отрисовка графика в терминале.
Библиотеки для организации динамических структур данных (стек, список и т.д.).

Для начала игры:
    make all
    // sin(x)...