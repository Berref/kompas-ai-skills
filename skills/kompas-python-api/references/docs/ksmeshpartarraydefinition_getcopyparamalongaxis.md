# GetCopyParamAlongAxis - Получить параметры копирования вдоль оси

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по параллельной сетке (Интерфейсы ksMeshPartArrayDefinition, IMeshPartArrayDefinition) ](ksmeshpartarraydefinition.html) > [ksMeshPartArrayDefinition - методы ](ksmeshpartarraydefinition_methods.html) |  Scroll [ [ [ ](ksmeshpartarraydefinition_partarray.html "К следующему разделу")](ksmeshpartarraydefinition_methods.html "На уровень выше")](ksmeshpartarraydefinition_getaxis2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshpartarraydefinition.html)

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
