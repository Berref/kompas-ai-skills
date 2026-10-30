# BranchPoints - Массив SAFEARRAY координат точек ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) > [Y - Координата точки привязки марки по Y ](imark_y.html) > [Интерфейс IMarkOnLeader ](imarkonleader.html) > [IMarkOnLeader - свойства ](imarkonleader_props.html) |  Scroll [ [ [ ](imarkonleader_branchpointscount.html "К следующему разделу")](imarkonleader_props.html "На уровень выше")](imarkonleader_branchcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarkonleader.html)

Тип данных: VARIANT типа VT_ARRAY | VT_R8

Синтаксис Automation:

BranchPoints = iObject.BranchPoints(index) | Получить свойство([* ](1.html))  
---|---  
iObject.BranchPoints(index) = BranchPoints | Установить свойство ([* ](1.html))  
BranchPoints = iObject.GetBranchPoints(index) | Получить свойство ([**](2.html))  
iObject.SetBranchPoints(index, BranchPoints) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BranchPoints(index, &BranchPoints) | Получить свойство  
---|---  
iObject->put_BranchPoints(index, BranchPoints) | Установить свойство  
  
Примечание.

1\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, x1, y1, ...xi, yi.

2\. Значения координат зависят от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
