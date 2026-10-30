# ksGetShelfPoint - Получить координаты начала и конца выносной полки и ножки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kshatchbyparam.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksgetobjectstyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetShelfPoint](ksgetshelfpoint.html).

Синтаксис Automation:

BOOL ksGetShelfPoint( long p, long index, double *x, double *y, long paramType );

Входные параметры:

p | \- указатель на объект (размер или линию-выноску),  
---|---  
index | \- индекс точки. Значения индекса: Для линии с ножкой: 1 __ 2 / 0 / Для линии без ножки (с выносной полкой на продолжении выносной линии): 0 __ 1 Точка 0 примыкает к выносной линии.  
paramType | \- тип параметров, задает систему координат: ALLPARAM - в системе координат владельца; SHEET_ALLPARAM - в системе координат листа; VIEW_ALLPARAM - в системе координат вида.  
  
Выходные параметры:

x, y | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
