# Y - Координата номера узла по Y

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitNumber ](iunitnumber.html) > [IUnitNumber - свойства ](iunitnumber_props.html) |  Scroll [ [ [ ](iaxisjut.html "К следующему разделу")](iunitnumber_props.html "На уровень выше")](iunitnumber_x.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitnumber.html)

Тип данных: double

Синтаксис Automation:

Y = iObject.Y; | Получить свойство([* ](1.html))  
---|---  
iObject.Y = Y; | Установить свойство ([* ](1.html))  
Y = iObject.GetY(); | Получить свойство ([**](2.html))  
iObject.SetY(Y); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Y(&Y); | Получить свойство  
---|---  
iObject->put_Y(Y); | Установить свойство  
  
Примечание:

1\. Значение параметра зависит от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

2\. Свойство позволяет считывать и устанавливать координату номера узла по Y.

Подразделы:

(отсутствуют)
