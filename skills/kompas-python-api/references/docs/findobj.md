# FindObj - Найти ближайший к заданной точке объект вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Навигация по графическому документу ](cm1745694.html) > [Функции навигации ](navigation_fncts.html) |  Scroll [ [ [ ](getobjgabaritrect.html "К следующему разделу")](navigation_fncts.html "На уровень выше")](deleteiterator.html "К предыдущему разделу")  
---|---  
  
[Пример...](findobj_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksFindObj](ksdocument2d_ksfindobj.html).

Синтаксис:

reference FindObj (double x,

double y,

double dist);

Входные параметры:

x, y | \- координаты точки,  
---|---  
dist | \- размер стороны квадрата-"ловушки" с центром в указанной точке.  
  
Возвращаемое значение:

указатель на найденный объект вида | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Зона поиска - квадрат с указанной стороной и центром.

2\. Если значение dist равно MAXDOUBLE, выполняется поиск ближайшего к указанной точке объекта без ограничения зоны поиска.

3\. Функцию FindObj можно использовать для поиска объектов внутри макроэлемента.

Для этого макроэлемент должен быть открыт на редактирование функцией [ksOpenMacro](ksopenmacro.html).

Пример:

ksOpenMacro(obj);

long obj_i=FindObj(x, y, AXIS_FIND_SENS);

if( ExistObj(obj_i) )

LightObj(obj_i, 1);

EndObj();

При этом, если для макроэлемента задана система координат (см. [SetMacroPlacement](setmacroplacement.html)), то координаты в FindObj должны передаваться в системе координат макроэлемента.

Пересчитать координаты в систему координат макроэлемента можно через функцию [ksPointIntoMtr](kspointintomtr.html). Для этого нужно функцией [ksMtr](ksmtr.html) создать матрицу преобразования координат.

Пример:

ksMtr(xp, yp, ang, 1,1); // xp, yp, ang, scaleX, scaleY, - параметры Placement макроэлемента.

ksPointIntoMtr (x, y, &xn, &yn);

EndMtr();

Подразделы:

(отсутствуют)
