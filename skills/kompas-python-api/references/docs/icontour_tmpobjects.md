# TmpObjects - Временные объекты из сегментов в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContour ](icontour.html) > [IContour - свойства ](icontour_props.html) |  Scroll [ [ [ ](icontour_methods.html "К следующему разделу")](icontour_props.html "На уровень выше")](icontour_segment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontour.html)

Тип данных: VARIANT

Значения свойства:

Массив SafeArray типа VT_ARRAY | VT_DISPATCH. |   
---|---  
  
Синтаксис Automation:

TmpObjects = iObject.TmpObjects; | Получить свойство([* ](1.html))  
---|---  
TmpObjects = iObject.GetTmpObjects(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TmpObjects( &TmpObjects ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получить массив SAFEARRAY временных объектов, входящих в контур.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
