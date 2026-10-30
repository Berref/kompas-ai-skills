# Add - Создать объект "отверстие"

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalHoles ](isheetmetalholes.html) > [ISheetMetalHoles - методы ](isheetmetalholes_methods.html) |  Scroll [ [ [ ](isheetmetallinebends.html "К следующему разделу")](isheetmetalholes_methods.html "На уровень выше")](isheetmetalholes_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalholes.html)

Синтаксис Automation:

LPDISPATH Add();

Синтаксис СОМ:

HRESULT Add( ISheetMetalHole** Result);

Возвращаемое значение:

Указатель на интерфейс отверстия [ISheetMetalHole](isheetmetalhole.html) | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый объект "отверстие".

2\. После получения нового объекта нужно задать его параметры и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
