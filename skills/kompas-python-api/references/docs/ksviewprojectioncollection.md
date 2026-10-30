# Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) |  Scroll [ [ [ ](ksviewprojectioncollection_propers.html "К следующему разделу")](ksdocument3d.html "На уровень выше")](imouseenterleaveparameters_symbolscale.html "К предыдущему разделу")  
---|---  
  
Интерфейс массива проекций отображения модели в окне.

ksViewProjectionCollection | \- интерфейс Automation  
---|---  
IViewProjectionCollection | \- интерфейс COM  
  
[Типы предопределенных проекций отображения...](projectiontype.html)

Описание:

К предопределенным проекциям можно добавлять пользовательские, индексы которых могут изменяться.

Примечание:

Получить этот интерфейс можно методом [ksDocument3D::GetViewProjectionCollection](ksdocument3d_getviewprojectioncollection.html), при этом он будет автоматически заполнен проекциями, заданными в данном документе.

Подразделы:

[IViewProjectionCollection - свойства ](ksviewprojectioncollection_propers.html)

[IViewProjectionCollection - методы ](ksviewprojectioncollection_methods.html)

[Проекции отображения модели в окне (Интерфейсы ksViewProjection, IViewProjection) ](ksviewprojection.html)
