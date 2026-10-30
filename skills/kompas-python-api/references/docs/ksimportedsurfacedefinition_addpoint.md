# AddPoint - Добавить точку в определение новой кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Описание импортированной поверхности (Интерфейсы ksImportedSurfaceDefinition, IImportedSurfaceDefinition) ](ksimportedsurfacedefinition.html) > [IImportedSurfaceDefinition - методы ](ksimportedsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksimportedsurfacedefinition_begincurve.html "К следующему разделу")](ksimportedsurfacedefinition_methods.html "На уровень выше")](ksimportedsurfacedefinition_addcurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksimportedsurfacedefinition.html)

Синтаксис Automation:

BOOL AddPoint(double x, double y, double z);

Синтаксис COM:

BOOL AddPoint(double x, double y, double z);

Входные параметры:

x, y, z | \- координаты точки кривой.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Перед добавлением точек кривой нужно открыть описание кривой методом [ksImportedSurfaceDefinition::BeginCurve.](ksimportedsurfacedefinition_begincurve.html)

После добавления точек необходимо закрыть определение кривой методом [ksImportedSurfaceDefinition::EndCurve](ksimportedsurfacedefinition_endcurve.html).

Подразделы:

(отсутствуют)
