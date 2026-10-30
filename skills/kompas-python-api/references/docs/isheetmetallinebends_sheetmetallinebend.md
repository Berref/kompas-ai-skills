# SheetMetalLineBend - Операция "сгиб по линии", заданная по индексу или ссылке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBends ](isheetmetallinebends.html) > [ISheetMetalLineBends - свойства ](isheetmetallinebends_props.html) |  Scroll [ [ [ ](isheetmetallinebends_methods.html "К следующему разделу")](isheetmetallinebends_props.html "На уровень выше")](isheetmetallinebends_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebends.html)

Тип данных: указатель на интерфейс [ISheetMetalLineBend](isheetmetallinebend.html)

Синтаксис Automation:

ISheetMetalLineBend = iObject.SheetMetalLineBend( index ) | Получить свойство ([* ](1.html))  
---|---  
ISheetMetalLineBend = iObject.GetSheetMetalLineBend( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SheetMetalLineBend( index, &SheetMetalLineBend ) | Получить свойство  
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
