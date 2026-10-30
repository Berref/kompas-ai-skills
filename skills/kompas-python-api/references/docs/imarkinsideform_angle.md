# Angle - Угол

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) > [Y - Координата точки привязки марки по Y ](imark_y.html) > [Интерфейс IMarkInsideForm ](imarkinsideform.html) > [IMarkInsideForm - свойства ](imarkinsideform_props.html) |  Scroll [ [ [ ](imarkinsideform_form.html "К следующему разделу")](imarkinsideform_props.html "На уровень выше")](imarkinsideform_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarkinsideform.html)

Тип данных: double

Синтаксис Automation:

Angle = iObject.Angle | Получить свойство([* ](1.html))  
---|---  
iObject.Angle = Angle | Установить свойство ([* ](1.html))  
Angle = iObject.GetAngle() | Получить свойство ([**](2.html))  
iObject.SetAngle(Angle) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Angle(&Angle) | Получить свойство  
---|---  
iObject->put_Angle( Angle) | Установить свойство  
  
Примечание:

Значение параметра зависит от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
