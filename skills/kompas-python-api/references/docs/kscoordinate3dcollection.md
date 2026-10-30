# Интерфейс коллекции трехмерных координат (Интерфейсы ksCoordinate3dCollection, ICoordinate3dCollection)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) |  Scroll [ [ [ ](kscoordinate3dcollection_methods.html "К следующему разделу")](ksdocument3d.html "На уровень выше")](cb1753415.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции трехмерных координат.

ksCoordinate3dCollection | \- интерфейс Automation  
---|---  
ICoordinate3dCollection | \- интерфейс COM  
  
Примечания.

1\. Коллекция содержит список трехмерных координат точек. Используется при получении результатов расчета пересечений кривой с деталью, телом или поверхностью.

2\. Получить интерфейс коллекции можно с помощью метода [ksDocument3D::GetInterface](ksdocument3d_getinterface.html) с параметром o3dType = o3d_coordinate3dCollection.

Подразделы:

[ICoordinate3dCollection - методы ](kscoordinate3dcollection_methods.html)
