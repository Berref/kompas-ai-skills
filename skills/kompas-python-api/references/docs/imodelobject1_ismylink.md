# IsMyLink - Является ли примитив опорным для объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [3D-объект ](bc2229904.html) > [Интерфейс IModelObject1 ](imodelobject1.html) > [IModelObject1 - методы ](imodelobject1_methods.html) |  Scroll [ [ [ ](imodelobject1_reset.html "К следующему разделу")](imodelobject1_methods.html "На уровень выше")](imodelobject1_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobject1.html)

Синтаксис Automation:

BOOL IsMyLink( ksRelationTypeEnum RelType,

LPDISPATCH Primitive );

Синтаксис COM:

HRESULT IsMyLink( ksRelationTypeEnum RelType,

IModelObject * Primitive,

BOOL * Result );

Возвращаемое значение:

TRUE | \- примитив является опорным.  
---|---  
  
Входные параметры:

RelType | \- тип родственных отношений,  
---|---  
Primitive | \- проверяемый примитив.  
  
Метод позволяет проверить, является ли примитив опорным для объекта 3D (например, ребро кинематической операции опорным для операции скругления).

Подразделы:

(отсутствуют)
