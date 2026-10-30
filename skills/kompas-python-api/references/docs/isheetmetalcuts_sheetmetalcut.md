# SheetMetalCut - Объект "вырез", заданный по индексу или ссылке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalCuts ](isheetmetalcuts.html) > [ISheetMetalCuts - свойства ](isheetmetalcuts_props.html) |  Scroll [ [ [ ](isheetmetalcuts_methods.html "К следующему разделу")](isheetmetalcuts_props.html "На уровень выше")](isheetmetalcuts_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalcuts.html)

Тип данных: указатель на интерфейс [ISheetMetalCut](isheetmetalcut.html)

Синтаксис Automation:

ISheetMetalCut = iObject.SheetMetalCut( index ) | Получить свойство ([* ](1.html))  
---|---  
ISheetMetalCut = iObject.GetSheetMetalCut( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SheetMetalCut( index, &SheetMetalCut ) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT index | \- индекс объекта.  
---|---  
  
Примечание:

В качестве индекса может использоваться:

•индекс объекта в коллекции,

•ссылка на объект (reference).

Подразделы:

(отсутствуют)
