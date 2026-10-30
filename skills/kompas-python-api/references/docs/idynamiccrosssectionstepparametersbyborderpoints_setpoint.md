# SetPoint - Установить координату точки

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Динамическое сечение ](cu1734180.html) > [Интерфейс IDynamicCrossSectionStepParametersByBorderPoints ](idynamiccrosssectionstepparametersbyborderpoints.html) > [IDynamicCrossSectionStepParametersByBorderPoints - методы ](idynamiccrosssectionstepparametersbyborderpoints_methods.html) |  Scroll [ [ [ ](isolation.html "К следующему разделу")](idynamiccrosssectionstepparametersbyborderpoints_methods.html "На уровень выше")](idynamiccrosssectionstepparametersbyborderpoints_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idynamiccrosssectionstepparametersbyborderpoints.html)

Синтаксис Automation:

BOOL SetPoint( BOOL First, double X, double Y, double Z );

Синтаксис COM:

HRESULT SetPoint( BOOL First, double X, double Y, double Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

First | \- TRUE - первая вершина, FALSE - вторая вершина.  
---|---  
X,Y, Z | \- координаты вершины.  
  
Подразделы:

(отсутствуют)
