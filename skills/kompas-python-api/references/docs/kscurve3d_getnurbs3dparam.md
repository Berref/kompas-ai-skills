# GetNurbs3dParam - Получить NURBS-представление кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [ICurve3D - методы ](kscurve3d_methods.html) |  Scroll [ [ [ ](kscurve3d_getparammin.html "К следующему разделу")](kscurve3d_methods.html "На уровень выше")](kscurve3d_getnormal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurve3d.html)

Синтаксис Automation:

LPDISPATCH GetNurbs3dParam();

Синтаксис COM:

LPNURBS3DPARAM GetNurbs3dParam();

Возвращаемое значение:

| \- указатель на интерфейс [ksNurbs3dParam/](ksnurbs3dparam.html)INurbs3dParam.  
---|---  
  
Примечание:

Метод позволяет получить параметры кривой в NURBS-представлении. Для получения параметров кривой в NURBS-представлении создается математическая NURBS-кривая, аналогичная заданной. Если заданная кривая является NURBS-кривой, то возвращаются ее параметры без создания NURBS-представления.

Подразделы:

(отсутствуют)
