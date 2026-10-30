# FeatureCollection - Получить массив объектов, входящих в макроэлемент

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition_getcountobj.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_destroy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

LPDISPATCH FeatureCollection();

Синтаксис COM:

LPFEATURECOLLECTION FeatureCollection();

Возвращаемое значение:

| \- указатель на интерфейс [ksFeatureCollection](ksfeaturecollection.html) или [IFeatureCollection](ksfeaturecollection.html)  
---|---  
  
Примечание:

1\. Через данную коллекцию можно добавлять только уже созданные объекты. Добавление новых (несозданных) объектов осуществляется при помощи метода [ksMacro3DDefinition::Add](ksmacro3ddefinition_add.html).

2\. Метод [ksFeatureCollection::Refresh](ksfeaturecollection_refresh.html) наполняет содержимое коллекции объектами, входящими в макроэлемент. Все изменения, сделанные в коллекции, после вызова этого метода будут потеряны.

3\. При добавлении объектов в коллекцию добавляемый объект должен принадлежать тому же компоненту, что и сам макроэлемент; он не должен принадлежать другому макроэлементу.

Подразделы:

(отсутствуют)
