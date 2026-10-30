# GetMinMaxParameters - Получить параметры кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [Параметры трехмерных NURBS (Интерфейсы ksNurbs3dParam,INurbs3dParam) ](ksnurbs3dparam.html) > [INurbs3dParam - методы ](ksnurbs3dparam_methods.html) |  Scroll [ [ [ ](ksnurbs3dparam_getnurbspoints3dparams.html "К следующему разделу")](ksnurbs3dparam_methods.html "На уровень выше")](ksnurbs3dparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbs3dparam.html)

Синтаксис Automation:

BOOL GetMinMaxParameters (BOOL closed, double * tMin, double * tMax);

Синтаксис COM:

BOOL GetMinMaxParameters (BOOL closed, double * tMin, double * tMax);

Входные параметры:

Closed | \- TRUE - получение параметров для замкнутого представления, \- FALSE - получение параметров для разомкнутого представления.  
---|---  
  
Выходные параметры:

tMin | \- значение минимального параметра,  
---|---  
tMax | \- значение максимального параметра.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
