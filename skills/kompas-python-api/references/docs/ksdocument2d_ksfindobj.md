# ksFindObj - Найти ближайший к заданной точке объект вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksgetcursorposition.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksdrawkompasgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [FindObj](findobj.html).

Синтаксис Automation:

long ksFindObj (double x, double y, double limit);

Входные параметры:

x, y | \- координаты точки,  
---|---  
limit | \- размер стороны квадрата-"ловушки" с центром в указанной точке.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Зона поиска - квадрат с указанной стороной и центром.

2\. Если значение limit равно MAXDOUBLE, выполняется поиск ближайшего к указанной точке объекта без ограничения зоны поиска.

3\. Метод ksFindObj можно использовать для поиска объектов внутри макроэлемента.

4\. Для этого макроэлемент должен быть открыт на редактирование функцией [ksDocument2D::ksOpenMacro](ksdocument2d_ksopenmacro.html).

Пример:

doc2D.ksOpenMacro(obj);

long obj_i=doc2D.ksFindObj(xn, xn, AXIS_FIND_SENS);

if( doc2D.ksExistObj(obj_i) )

doc2D.ksLightObj(obj_i, 1);

doc2D.ksEndObj();

При этом, если для макроэлемента задана система координат (см. [ksDocument2D::ksPlacement](ksdocument2d_ksplacement.html)), то координаты в ksFindObj должны передаваться в этой системе координат.

Пересчитать координаты в систему координат макроэлемента можно через функцию [ksDocument2D::ksPointIntoMtr](ksdocument2d_kspointintomtr.html). Для этого нужно функцией [ksDocument2D::ksMtr](ksdocument2d_ksmtr.html) создать матрицу преобразования координат.

Пример:

doc2D.ksMtr(xp, yp, ang, 1, 1);

doc2D.ksPointIntoMtr(x, y, &xn, &yn);

doc2D.ksEndMtr();

Подразделы:

(отсутствуют)
