# IsEllipse - Определить, является ли кривая эллипсом

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [ICurve3D - методы ](kscurve3d_methods.html) |  Scroll [ [ [ ](kscurve3d_isellipsearc.html "К следующему разделу")](kscurve3d_methods.html "На уровень выше")](kscurve3d_isdegenerate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurve3d.html)

Синтаксис Automation:

BOOL IsEllipse();

Синтаксис COM:

BOOL IsEllipse();

Возвращаемое значение:

TRUE | \- кривая является эллипсом,  
---|---  
FALSE | \- кривая не является эллипсом.  
  
Примечание:

Данный метод удобно использовать для приведения базового интерфейса (IUnknown в COM и IDispatch в Automation) к конечному интерфейсу трехмерных объектов. Зная тип объекта, можно привести его к соответствующему интерфейсу. Метод [GetCurveParam](kscurve3d_getcurveparam.html) вернет указатель на интерфейс параметра эллипса [ksEllipse3dParam](ksellipse3dparam.html) или [IEllipse3dParam](ksellipse3dparam.html).

Подразделы:

(отсутствуют)
