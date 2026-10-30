# SetSideParam - Изменить параметры выдавливания в одном направлении

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент выдавливания (Интерфейсы ksCutExtrusionDefinition, ICutExtrusionDefinition) ](kscutextrusiondefinition.html) > [ICutExtrusionDefinition - методы ](kscutextrusiondefinition_methods.html) |  Scroll [ [ [ ](kscutextrusiondefinition_setsketch.html "К следующему разделу")](kscutextrusiondefinition_methods.html "На уровень выше")](kscutextrusiondefinition_setdepthobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutextrusiondefinition.html)

Синтаксис Automation:

BOOL SetSideParam (BOOL forward,

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
type | \- тип выдавливания,  
depth | \- глубина выдавливания,  
draftValue | \- угол уклона,  
draftOutward | \- направление уклона: FALSE - уклон наружу, TRUE - уклон внутрь.  
  
[Типы выдавливания...](end_type.html)

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
