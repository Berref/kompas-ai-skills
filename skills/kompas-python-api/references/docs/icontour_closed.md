# Closed - Замкнутость

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContour ](icontour.html) > [IContour - свойства ](icontour_props.html) |  Scroll [ [ [ ](icontour_count.html "К следующему разделу")](icontour_props.html "На уровень выше")](icontour_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontour.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- контур замкнут,  
---|---  
FALSE | \- контур разомкнут.  
  
Синтаксис Automation:

Closed = iObject.Closed; | Получить свойство([* ](1.html))  
---|---  
iObject.Closed = Closed; | Установить свойство ([* ](1.html))  
Closed = iObject.GetClosed(); | Получить свойство ([**](2.html))  
iObject.SetClosed(Closed); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Closed( &Closed ) | Получить свойство  
---|---  
iObject->put_Closed( Closed ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет устанавливать и получать замкнутость мультилинии.

2\. Если мультилиния замкнута, то контур тоже замкнут.

Подразделы:

(отсутствуют)
