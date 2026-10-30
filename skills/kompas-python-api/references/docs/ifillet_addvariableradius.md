# AddVariableRadius - Добавить настройку переменного радиуса для ребра в точке, заданной смещением

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFillet ](ifillet.html) > [IFillet - методы ](ifillet_methods.html) |  Scroll [ [ [ ](ifillet_variableradiusclear.html "К следующему разделу")](ifillet_methods.html "На уровень выше")](ifillet_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillet.html)

Синтаксис Automation:

BOOL AddVariableRadius( IModelObject * PointObject, double Radius, double Position, BOOL PositionType );

Синтаксис COM:

HRESULT AddVariableRadius( IModelObject * PointObject, double Radius, double Position, BOOL PositionType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

PointObject | \- фиксирующий объект,  
---|---  
Radius | \- радиус скругления,  
Position | \- положение на кривой,  
PositionType | \- способ определения положения на кривой: TRUE - задано величиной, FALSE - в процентах от длины кривой.  
  
Подразделы:

(отсутствуют)
