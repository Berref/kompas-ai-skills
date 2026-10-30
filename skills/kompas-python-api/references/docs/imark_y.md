# Y - Координата точки привязки марки по Y

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) |  Scroll [ [ [ ](imarkonleader.html "К следующему разделу")](imark_props.html "На уровень выше")](imark_x.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imark.html)

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

Значение параметра зависит от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

[Интерфейс IMarkOnLeader ](imarkonleader.html)

[Интерфейс IMarkInsideForm ](imarkinsideform.html)

[Интерфейс IMarkOnLine ](imarkonline.html)
