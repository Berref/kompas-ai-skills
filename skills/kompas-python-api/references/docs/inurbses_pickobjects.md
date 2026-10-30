# PickObjects - Собрать объекты по лучу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbses ](inurbses.html) > [INurbses - методы ](inurbses_methods.html) |  Scroll [ [ [ ](ipoints.html "К следующему разделу")](inurbses_methods.html "На уровень выше")](inurbses_convert.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbses.html)

Синтаксис Automation:

LPDISPATCH ConvertEx( LPDISPATCH Curve, ksNurbsByPointsAproximationTypeEnum AproximationType, double Step );

Синтаксис COM:

HRESULT ConvertEx( [in]IDrawingObject * Curve, ksNurbsByPointsAproximationTypeEnum AproximationType, double Step, INurbs ** Result);

Входные параметры:

Curve | \- указатель на кривую,  
---|---  
AproximationType | \- способ аппроксимации,  
Step | \- шаг аппроксимации.  
  
Возвращаемое значение:

| \- Указатель на интерфейс кривой в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
