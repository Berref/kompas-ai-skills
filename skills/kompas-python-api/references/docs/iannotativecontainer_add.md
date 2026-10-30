# Add - Добавить объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IAnnotativeContainer ](iannotativecontainer.html) > [IAnnotativeContainer - методы ](iannotativecontainer_methods.html) |  Scroll [ [ [ ](iannotativecontainer_addobjects.html "К следующему разделу")](iannotativecontainer_methods.html "На уровень выше")](iannotativecontainer_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iannotativecontainer.html)

Синтаксис Automation:

LPDISPATCH Add( long type );

Синтаксис COM:

HRESULT Add( DrawingObjectTypeEnum type,

IAnnotativeObject ** Result );

Входные параметры:

type | \- тип добавляемого объекта из перечисления [DrawingObjectTypeEnum](objtypes.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс аннотационного объекта [IAnnotativeObject](iannotativeobject.html).  
---|---  
  
Примечание:

Метод позволяет добавить объект в контейнер.

Подразделы:

(отсутствуют)
