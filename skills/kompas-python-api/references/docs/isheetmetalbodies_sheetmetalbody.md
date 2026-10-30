# SheetMetalBody - Листовое тело, заданное по индексу или ссылке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBodies ](isheetmetalbodies.html) > [ISheetMetalBodies - свойства ](isheetmetalbodies_props.html) |  Scroll [ [ [ ](isheetmetalbodies_methods.html "К следующему разделу")](isheetmetalbodies_props.html "На уровень выше")](isheetmetalbodies_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbodies.html)

Тип данных: указатель на интерфейс [ISheetMetalBody](isheetmetalbody.html)

Синтаксис Automation:

SheetMetalBody = iObject.SheetMetalBody( index ) | Получить свойство ([* ](1.html))  
---|---  
SheetMetalBody = iObject.GetSheetMetalBody( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SheetMetalBody( index, &SheetMetalBody ) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT index | \- индекс операции выдавливания.  
---|---  
  
Примечание:

В качестве индекса может использоваться:

•индекс объекта в коллекции,

•ссылка на объект (reference).

Подразделы:

(отсутствуют)
