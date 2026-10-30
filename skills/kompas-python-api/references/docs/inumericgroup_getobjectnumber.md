# GetObjectNumber - Строковый номер объекта в группе

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Автонумерация и сортировка объектов ](bb3107129.html) > [Интерфейс INumericGroup ](inumericgroup.html) > [INumericGroup - методы ](inumericgroup_methods.html) |  Scroll [ [ [ ](iautosortobjectsparameters.html "К следующему разделу")](inumericgroup_methods.html "На уровень выше")](inumericgroup_getnextname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inumericgroup.html)

Синтаксис Automation:

BSTR GetObjectNumber( LPDISPATCH Object, BOOL FullName );

Синтаксис COM:

HRESULT GetObjectNumber( IKompasAPIObject * Object, BOOL FullName, BSTR * Result );

Возвращаемое значение:

| \- Строковый номер объекта в группе.  
---|---  
  
Входные параметры:

Object | \- указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html),  
---|---  
FullName | \- TRUE - вернуть полное имя, FALSE - только номер.  
  
Подразделы:

(отсутствуют)
