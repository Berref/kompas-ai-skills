# Add - Создать сгиб (добавить сгиб в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBends ](isheetmetalbends.html) > [ISheetMetalBends - методы ](isheetmetalbends_methods.html) |  Scroll [ [ [ ](isheetmetalbodies.html "К следующему разделу")](isheetmetalbends_methods.html "На уровень выше")](isheetmetalbends_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbends.html)

Синтаксис Automation:

LPDISPATH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalBend** Result);

Возвращаемое значение:

Указатель на интерфейс сгиба [ISheetMetalBend](isheetmetalbend.html) | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс сгиба.

2\. После получения нового интерфейса нужно задать параметры листового тела и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
