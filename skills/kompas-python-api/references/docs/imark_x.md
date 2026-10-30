# X - Координата точки привязки по Х

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) |  Scroll [ [ [ ](imark_y.html "К следующему разделу")](imark_props.html "На уровень выше")](imark_textunder.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imark.html)

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

Значение параметра зависит от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
