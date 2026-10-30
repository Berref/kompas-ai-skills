# GetCopyParamAlongAxis - Получить параметры копирования вдоль оси

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по параллелограммной сетке( Интерфейсы ksMeshCopyDefinition и ICopyMeshDefinition) ](ksmeshcopydefinition.html) > [ICopyMeshDefinition - методы ](ksmeshcopydefinition_methods.html) |  Scroll [ [ [ ](ksmeshcopydefinition_operationarray.html "К следующему разделу")](ksmeshcopydefinition_methods.html "На уровень выше")](ksmeshcopydefinition_getaxis2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshcopydefinition.html)

Синтаксис Automation:

BOOL GetCopyParamAlongAxis (BOOL firstAxis,

double * angle,

long * count,

double * step,

BOOL * factor);

Синтаксис COM:

BOOL GetCopyParamAlongAxis (BOOL firstAxis,

double * angle,

long * count,

double * step,

BOOL * factor);

Выходные параметры:

firstAxis | \- ось: TRUE - первая, FALSE - вторая,  
---|---  
angle | \- угол наклона оси,  
count | \- количество копий,  
step | \- шаг вдоль оси,  
factor | \- признак полного шага.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
