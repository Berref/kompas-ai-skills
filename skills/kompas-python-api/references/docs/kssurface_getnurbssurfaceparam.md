# GetNurbsSurfaceParam - Получить NURBS-представление поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_getparamumin.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_getnormal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

LPDISPATCH GetNurbsSurfaceParam();

Синтаксис COM:

LPNURBS3DPARAM GetNurbsSurfaceParam();

Возвращаемое значение:

| \- указатель на интерфейс [ksNurbsSurfaceParam](ksnurbssurfaceparam.html) или [INurbsSurfaceParam](ksnurbssurfaceparam.html).  
---|---  
  
Примечание:

Метод позволяет получить параметры поверхности в NURBS-представлении. Для получения параметров поверхности в NURBS-представлении создается математическая Nurbs-поверхность, аналогичная заданной. Если заданная кривая является NURBS-поверхности, то возвращаются ее параметры без создания NURBS-представления.

Подразделы:

(отсутствуют)
