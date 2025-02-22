# calculator-pikovskiy-gv
For Rogonov&lt;3
Был использован огромный мозг. Visual studio и пачка чипсеков.
Интересные умные вещи были найдены на разных сайтах
На википедии нашел гайд как делать обратную польскую запись ссылка: https://ru.wikipedia.org/wiki/Обратная_польская_запись
На сайте нашел информацию по алгоритму: https://habr.com/ru/articles/555380/
Сильно косячил, но надеюсь добил
Отличительной особенностью обратной польской нотации является то, что все аргументы (или операнды) расположены перед знаком операции. В общем виде запись выглядит следующим образом:

Запись набора операций состоит из последовательности операндов и знаков операций. Операнды в выражении при письменной записи разделяются пробелами.
Выражение читается слева направо. Когда в выражении встречается знак операции, выполняется соответствующая операция над двумя последними встретившимися перед ним операндами в порядке их записи. Результат операции заменяет в выражении последовательность её операндов и её знак, после чего выражение вычисляется дальше по тому же правилу.
Результатом вычисления выражения становится результат последней вычисленной операции.
Например, рассмотрим вычисление выражения 7 2 3 * − (эквивалентное выражение в инфиксной нотации: 7 − 2 * 3).

Первый по порядку знак операции — «*», поэтому первой выполняется операция умножения над операндами 2 и 3 (они стоят последними перед знаком). Выражение при этом преобразуется к виду 7 6 − (результат умножения — 6, — заменяет тройку «2 3 *»).
Второй знак операции — «−». Выполняется операция вычитания над операндами 7 и 6.
Вычисление закончено. Результат последней операции равен 1, это и есть результат вычисления выражения.
Очевидное расширение обратной польской записи на унарные, тернарные и операции с любым другим количеством операндов: при использовании знаков таких операций в вычислении выражения операция применяется к соответствующему числу последних встретившихся операндов.

Особенности обратной польской записи следующие:

Порядок выполнения операций однозначно задаётся порядком следования знаков операций в выражении, поэтому отпадает необходимость использования скобок и введения приоритетов и ассоциативности операций.
В отличие от инфиксной записи, невозможно использовать одни и те же знаки для записи унарных и бинарных операций. Так, в инфиксной записи выражение 5 * (−3 + 8) использует знак «минус» как символ унарной операции (изменение знака числа), а выражение (10 − 15) * 3 применяет этот же знак для обозначения бинарной операции (вычитание). Конкретная операция определяется тем, в какой позиции находится знак. Обратная польская запись не позволяет этого: запись 5 3 − 8 + * (условный аналог первого выражения) будет интерпретирована как ошибочная, поскольку невозможно определить, что «минус» после 5 и 3 обозначает не вычитание; в результате будет сделана попытка вычислить сначала 5 − 3, затем 2 + 8, после чего выяснится, что для операции умножения не хватает операндов. Чтобы всё же записать это выражение, придётся либо переформулировать его (например, записав вместо выражения − 3 выражение 0 − 3), либо ввести для операции изменения знака отдельное обозначение, например, «±»: 5 3 ± 8 + *.
Так же, как и в инфиксной нотации, в ОПН одно и то же вычисление может быть записано в нескольких разных вариантах. Например, выражение (10 − 15) * 3 в ОПН можно записать как 10 15 − 3 *, а можно — как 3 10 15 − *
Из-за отсутствия скобок обратная польская запись короче инфиксной. За счёт этого при вычислениях на калькуляторах повышается скорость работы оператора (уменьшается количество нажимаемых клавиш), а в программируемых устройствах сокращается объём тех частей программы, которые описывают вычисления. Последнее может быть немаловажно для портативных и встроенных вычислительных устройств, имеющих жёсткие ограничения на объём памяти.
Автоматизация вычисления выражений в обратной польской нотации основана на использовании стека. Алгоритм вычисления для стековой машины элементарен:

Обработка входного символа
Если на вход подан операнд, он помещается на вершину стека.
Если на вход подан знак операции, то соответствующая операция выполняется над требуемым количеством значений, извлечённых из стека, взятых в порядке добавления. Результат выполненной операции кладётся на вершину стека.
Если входной набор символов обработан не полностью, перейти к шагу 1.
После полной обработки входного набора символов результат вычисления выражения лежит на вершине стека.
Реализация стековой машины, как программная, так и аппаратная, чрезвычайно проста и может быть очень эффективной. Обратная польская запись совершенно унифицирована — она принципиально одинаково записывает унарные, бинарные, тернарные и любые другие операции, а также обращения к функциям, что позволяет не усложнять конструкцию вычислительных устройств при расширении набора поддерживаемых операций. Это и послужило причиной использования обратной польской записи в некоторых научных и программируемых микрокалькуляторах.

