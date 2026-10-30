# GetCurveParam - Получить параметры линии, окружности, эллипса, NURBS или NULL

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [ICurve3D - методы ](kscurve3d_methods.html) |  Scroll [ [ [ ](kscurve3d_getderivativet.html "К следующему разделу")](kscurve3d_methods.html "На уровень выше")](kscurve3d_calculatepolygon.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurve3d.html)

Синтаксис Automation:

LPDISPATCH GetCurveParam();

Синтаксис COM:

LPUNKNOWN GetCurveParam();

Возвращаемое значение:

| \- указатель на интерфейс параметра кривой.  
---|---  
  
Примечание:

В соответствии с типом объекта метод вернет указатель на интерфейс параметра:

\- отрезка | [ksILineSeg3dParam](kslineseg3dparam.html) или [ILineSeg3dParam,](kslineseg3dparam.html)  
---|---  
\- дуги окружности | [ksArc3dParam](ksarc3dparam.html) или [IArc3dParam,](ksarc3dparam.html)  
\- окружности | [ks ICircle3dParam ](kscircle3dparam.html)или [ICircle3dParam,](kscircle3dparam.html)  
\- эллипса | [ksEllipse3dParam](ksellipse3dparam.html) или [IEllipse3dParam,](ksellipse3dparam.html)  
\- NURBS | [kIsNurbs3dParam](ksnurbs3dparam.html) или [INurbs3dParam.](ksnurbs3dparam.html)  
  
Зная тип объекта, можно базовый интерфейс привести к конечному (IDispatch или IUnknown). Для определения типа объекта можно воспользоваться методами [IsLineSeg](kscurve3d_islineseg.html), [IsArc](kscurve3d_isarc.html), [IsCircle](kscurve3d_iscircle.html), [IsEllipse](kscurve3d_isellipse.html), [IsNurbs](kscurve3d_isnurbs.html).

Подразделы:

(отсутствуют)
