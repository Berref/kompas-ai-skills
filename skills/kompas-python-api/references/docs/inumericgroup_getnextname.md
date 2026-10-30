# GetNextName - Получить имя следующего объекта в группе

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Автонумерация и сортировка объектов ](bb3107129.html) > [Интерфейс INumericGroup ](inumericgroup.html) > [INumericGroup - методы ](inumericgroup_methods.html) |  Scroll [ [ [ ](inumericgroup_getobjectnumber.html "К следующему разделу")](inumericgroup_methods.html "На уровень выше")](inumericgroup_isenableadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inumericgroup.html)

Синтаксис Automation:

BSTR GetNextName( LPDISPATCH Object );

Синтаксис COM:

HRESULT GetNextName( IKompasAPIObject * Object, BSTR * Result );

Возвращаемое значение:

| \- Имя следующего объекта в группе.  
---|---  
  
Входные параметры:

Object | \- указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html),  
---|---  
  
Примечание:

Метод используется для предварительного получения имени объекта перед добавлением в группу нумерации.

Подразделы:

(отсутствуют)
