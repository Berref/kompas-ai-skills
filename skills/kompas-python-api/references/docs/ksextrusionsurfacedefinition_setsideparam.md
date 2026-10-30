# SetSideParam - Изменить параметры выдавливания в одном направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность выдавливания (Интерфейсы ksExtrusionSurfaceDefinition и IExtrusionSurfaceDefinition) ](ksextrusionsurfacedefinition.html) > [ksExtrusionSurfaceDefinition - методы ](ksextrusionsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksextrusionsurfacedefinition_setsketch.html "К следующему разделу")](ksextrusionsurfacedefinition_methods.html "На уровень выше")](ksextrusionsurfacedefinition_setdepthobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksextrusionsurfacedefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetSideParam (VARIANT_BOOL forward,

short type,

double depth,

double draftValue,

BOOL draftOutward);

Синтаксис COM:

BOOL SetSideParam (BOOL forward,

short type,

double depth,

double draftValue,

BOOL draftOutward);

Входные параметры:

forward | \- направление выдавливания: TRUE - прямое направление, FALSE - обратное направление.  
---|---  
type | \- [тип выдавливания](end_type.html),  
depth | \- глубина выдавливания,  
draftValue | \- угол уклона,  
draftOutward | \- направление уклона: FALSE - уклон наружу, TRUE - уклон внутрь.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
