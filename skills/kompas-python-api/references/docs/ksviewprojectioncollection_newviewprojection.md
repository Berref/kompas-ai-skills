# NewViewProjection - Добавить новую проекцию

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [IViewProjectionCollection - методы ](ksviewprojectioncollection_methods.html) |  Scroll [ [ [ ](ksviewprojectioncollection_next.html "К следующему разделу")](ksviewprojectioncollection_methods.html "На уровень выше")](ksviewprojectioncollection_last.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojectioncollection.html)

Синтаксис Automation:

LPDISPATCH NewViewProjection();

Синтаксис COM:

LPVIEWPROJECTION NewViewProjection();

Возвращаемое значение:

| \- указатель на интерфейс [ksViewProjection](ksviewprojection.html) или [IViewProjection](ksviewprojection.html).  
---|---  
  
Примечание:

Проекции присваивается индекс vp_None. Созданная проекция в массив не добавляется, для добавления в массив нужно использовать метод [Add](ksviewprojectioncollection_add.html).

Подразделы:

(отсутствуют)
