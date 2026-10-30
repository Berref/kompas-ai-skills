# Add - Создать листовое тело

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBodies ](isheetmetalbodies.html) > [ISheetMetalBodies - методы ](isheetmetalbodies_methods.html) |  Scroll [ [ [ ](isheetmetalcuts.html "К следующему разделу")](isheetmetalbodies_methods.html "На уровень выше")](isheetmetalbodies_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbodies.html)

Синтаксис Automation:

LPDISPATH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalBody** Result);

Возвращаемое значение:

Указатель на интерфейс листового тела [ISheetMetalBody](isheetmetalbody.html) | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс базового листового тела.

2\. После получения нового интерфейса нужно задать параметры листового тела и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
