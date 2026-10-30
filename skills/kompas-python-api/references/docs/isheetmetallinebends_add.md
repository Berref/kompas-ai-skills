# Add - Создать объект "сгиб по линии" (добавить сгиб в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBends ](isheetmetallinebends.html) > [ISheetMetalLineBends - методы ](isheetmetallinebends_methods.html) |  Scroll [ [ [ ](isheetmetalbody.html "К следующему разделу")](isheetmetallinebends_methods.html "На уровень выше")](isheetmetallinebends_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebends.html)

Синтаксис Automation:

LPDISPATH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalBend** Result);

Возвращаемое значение:

Указатель на линии [ISheetMetalLineBend](isheetmetallinebend.html) | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс сгиба по линии.

2\. После получения нового интерфейса нужно задать параметры листового тела и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
