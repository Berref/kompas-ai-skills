# GetDimensionVariable - Получить переменную, связанную с размером

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Контейнер ](bc2273864.html) > [Интерфейс ISymbols3DContainer ](isymbols3dcontainer.html) > [ISymbols3DContainer - методы ](isymbols3dcontainer_methods.html) |  Scroll [ [ [ ](bc2274179.html "К следующему разделу")](isymbols3dcontainer_methods.html "На уровень выше")](isymbols3dcontainer_creategenerativedimensions.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isymbols3dcontainer.html)

Синтаксис Automation:

LPDISPATCH GetDimensionVariable( LPDISPATCH Dimension );

Синтаксис COM:

HRESULT GetDimensionVariable( IModelObject * Dimension, IVariable7 * Result );

Возвращаемое значение:

указатель на интерфейс переменной [IVariable7](ivariable7.html).

Входные параметры:

Dimensions | \- указатель на размер, для которого надо получить переменную.  
---|---  
  
Подразделы:

(отсутствуют)
