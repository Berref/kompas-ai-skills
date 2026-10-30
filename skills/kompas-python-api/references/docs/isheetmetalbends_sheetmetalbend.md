# SheetMetalBend - Сгиб, заданный по индексу или ссылке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBends ](isheetmetalbends.html) > [ISheetMetalBends - свойства ](isheetmetalbends_props.html) |  Scroll [ [ [ ](isheetmetalbends_methods.html "К следующему разделу")](isheetmetalbends_props.html "На уровень выше")](isheetmetalbends_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbends.html)

Тип данных – указатель на интерфейс [ISheetMetalBend](isheetmetalbend.html).

Синтаксис Automation:

SheetMetalBend = iObject.SheetMetalBend( index ) | Получить свойство ([* ](1.html))  
---|---  
SheetMetalBend = iObject.GetSheetMetalBend( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SheetMetalBend( index, &SheetMetalBend ) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT index | \- индекс операции.  
---|---  
  
Примечание:

В качестве индекса может использоваться:

•индекс объекта в коллекции,

•ссылка на объект (reference).

Подразделы:

(отсутствуют)
