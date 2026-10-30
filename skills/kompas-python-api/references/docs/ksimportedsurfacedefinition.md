# Описание импортированной поверхности (Интерфейсы ksImportedSurfaceDefinition, IImportedSurfaceDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) |  Scroll [ [ [ ](ksimportedsurfacedefinition_methods.html "К следующему разделу")](int_additional.html "На уровень выше")](ksfacedefinition_loopcollection.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров импортированной поверхности.

ksImportedSurfaceDefinition | \- интерфейс Automation  
---|---  
IImportedSurfaceDefinition | \- интерфейс COM  
  
Примечание:

1\. Поверхность можно импортировать, задав массив упорядоченных массивов точек. Один упорядоченный массив точек IVertexCollection определяет одну кривую. Если первая и последняя точки кривой совпадают, это является признаком замкнутости кривой. Для нормального построения поверхности кривых должно быть, как минимум, две.

2\. Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

Подразделы:

[IImportedSurfaceDefinition - методы ](ksimportedsurfacedefinition_methods.html)
