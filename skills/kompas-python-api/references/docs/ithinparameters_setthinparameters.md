# SetThinParameters - Установить параметры тонкой стенки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IThinParameters ](ithinparameters.html) > [IThinParameters - методы ](ithinparameters_methods.html) |  Scroll [ [ [ ](ihole3d.html "К следующему разделу")](ithinparameters_methods.html "На уровень выше")](ithinparameters_getthinparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ithinparameters.html)

Синтаксис Automation:

BOOL SetThinParameters( BOOL * Thin,

Direction_Type * ThinType,

double * ThicknessNormal,

double * ThicknessReverse

Синтаксис COM:

HRESULT SetThinParameters( BOOL * Thin,

Direction_Type * ThinType,

double * ThicknessNormal,

double * ThicknessReverse

Выходные параметры:

Thin | \- признак формирования тонкой стенки,  
---|---  
ThinType | \- направление формирования тонкой стенки,  
ThicknessNormal | \- толщина стенки в направлении наружу,  
ThicknessReverse | \- толщина стенки в направлении внутрь.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить параметры тонкой стенки.

Подразделы:

(отсутствуют)
