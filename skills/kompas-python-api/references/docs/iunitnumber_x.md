# X - Координата номера узла по Х

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitNumber ](iunitnumber.html) > [IUnitNumber - свойства ](iunitnumber_props.html) |  Scroll [ [ [ ](iunitnumber_y.html "К следующему разделу")](iunitnumber_props.html "На уровень выше")](iunitnumber_textup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitnumber.html)

Тип данных: double

Синтаксис Automation:

X = iObject.X; | Получить свойство([* ](1.html))  
---|---  
iObject.X = X; | Установить свойство ([* ](1.html))  
X = iObject.GetX(); | Получить свойство ([**](2.html))  
iObject.SetX( X ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_X(&X); | Получить свойство  
---|---  
iObject->put_X( X ); | Установить свойство  
  
Примечание:

1\. Значение параметра зависит от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

2\. Свойство позволяет считывать и устанавливать координату номера узла по X.

Подразделы:

(отсутствуют)
