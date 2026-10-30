# Интерфейс IShellSurface

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) |  Scroll [ [ [ ](ishellsurface_propers.html "К следующему разделу")](bc2279073.html "На уровень выше")](irotated1_operationresult.html "К предыдущему разделу")  
---|---  
  
Интерфейс операции Поверхность (поверхность выдавливания, вращения, по сечениям, кинематическая).

Иерархия:

IDispatch

[IShellSurface](ishellsurface.html)

Интерфейс является дополнительным для поверхностей:

•выдавливания [IExtrusion](iextrusion.html),

•вращения [IRotated](irotated.html),

•по сечениям [ILoft](iloft.html),

•кинематических [IEvolution](ievolution.html).

Интерфейс можно получить посредством вызова метода [IUnknown::QueryInterface](recomendation.html) (const GUID far& iid, void** pif).

КОМПАС версия v18

Подразделы:

[IShellSurface - свойства ](ishellsurface_propers.html)
