# AddCurve - Добавить кривую по массиву точек

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Описание импортированной поверхности (Интерфейсы ksImportedSurfaceDefinition, IImportedSurfaceDefinition) ](ksimportedsurfacedefinition.html) > [IImportedSurfaceDefinition - методы ](ksimportedsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksimportedsurfacedefinition_addpoint.html "К следующему разделу")](ksimportedsurfacedefinition_methods.html "На уровень выше")](ksimportedsurfacedefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Пример...](addcurve_example.html)

[Интерфейс...](ksimportedsurfacedefinition.html)

Синтаксис Automation:

BOOL AddCurve (VARIANT arr);

Синтаксис COM:

BOOL AddCurve (VARIANT arr);

Входные параметры:

arr | \- массив координат точек кривой.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Тип переменной arr - VT_ARRAY | VT_R8. Одномерный SAFEARRAY массив double значений.

2\. Каждая точка представлена тремя координатами x, y, z. Следовательно число точек в массиве должно быть кратно.

Подразделы:

(отсутствуют)
