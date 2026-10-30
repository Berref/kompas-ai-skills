# SetSideParam - Изменить параметры вращения в одном направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность вращения (Интерфейсы ksRotatedSurfaceDefinition и IRotatedSurfaceDefinition) ](ksrotatedsurfacedefinition.html) > [ksRotatedSurfaceDefinition - методы ](ksrotatedsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksrotatedsurfacedefinition_setsketch.html "К следующему разделу")](ksrotatedsurfacedefinition_methods.html "На уровень выше")](ksrotatedsurfacedefinition_rotatedparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrotatedsurfacedefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetSideParam (short forward,

double angle);

Синтаксис COM:

BOOL SetSideParam (BOOL forward,

double angle);

Входные параметры:

forward | \- направление вращения: TRUE - прямое направление, FALSE - обратное направление,  
---|---  
angle | \- угол вращения.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
