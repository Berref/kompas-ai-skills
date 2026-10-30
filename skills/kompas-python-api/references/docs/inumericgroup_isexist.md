# IsExist - Входит ли объект в группу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Автонумерация и сортировка объектов ](bb3107129.html) > [Интерфейс INumericGroup ](inumericgroup.html) > [INumericGroup - методы ](inumericgroup_methods.html) |  Scroll [ [ [ ](inumericgroup_isenableadd.html "К следующему разделу")](inumericgroup_methods.html "На уровень выше")](inumericgroup_dettach.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inumericgroup.html)

Синтаксис Automation:

BOOL IsExist( LPDISPATCH Object );

Синтаксис COM:

HRESULT IsExist( IKompasAPIObject * Object, BOOL * Result );

Возвращаемое значение:

TRUE | \- объект уже есть в группе,  
---|---  
FALSE | \- объекта нет в группе.  
  
Входные параметры:

Object | \- указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html),  
---|---  
  
Подразделы:

(отсутствуют)
