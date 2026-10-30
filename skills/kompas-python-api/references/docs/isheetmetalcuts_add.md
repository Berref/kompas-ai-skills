# Add - Создать объект "вырез"

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalCuts ](isheetmetalcuts.html) > [ISheetMetalCuts - методы ](isheetmetalcuts_methods.html) |  Scroll [ [ [ ](isheetmetalholes.html "К следующему разделу")](isheetmetalcuts_methods.html "На уровень выше")](isheetmetalcuts_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalcuts.html)

Синтаксис Automation:

LPDISPATH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalCut** Result);

Возвращаемое значение:

Указатель на интерфейс отверстия [ISheetMetalCut](isheetmetalcut.html) | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый объект "вырез".

2\. После получения нового объекта нужно задать его параметры и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
