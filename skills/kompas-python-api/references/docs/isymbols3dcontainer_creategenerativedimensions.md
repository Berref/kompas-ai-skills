# CreateGenerativeDimensions - Отобразить размеры эскизов и операций

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Контейнер ](bc2273864.html) > [Интерфейс ISymbols3DContainer ](isymbols3dcontainer.html) > [ISymbols3DContainer - методы ](isymbols3dcontainer_methods.html) |  Scroll [ [ [ ](isymbols3dcontainer_getdimensionvariable.html "К следующему разделу")](isymbols3dcontainer_methods.html "На уровень выше")](isymbols3dcontainer_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isymbols3dcontainer.html)

Синтаксис Automation:

BOOL CreateGenerativeDimensions( VARIANT Objects, BOOL CreateZeroDimensions );

Синтаксис COM:

HRESULT CreateGenerativeDimensions( VARIANT Objects, BOOL CreateZeroDimensions, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект или массив объектов ( VT_DISPATCH или VT_ARRAY | VT_DISPATCH), для которых нужно отобразить размеры,  
---|---  
CreateZeroDimensions | \- создавать размеры с нулевым значением.  
  
Подразделы:

(отсутствуют)
