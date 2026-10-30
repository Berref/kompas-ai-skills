# SetCopyParamAlongDir - Установить параметры копирования

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по концентрической сетке (Интерфейсы ksCircularPartArrayDefinition, ICircularPartArrayDefinition) ](kscircularpartarraydefinition.html) > [ksCircularPartArrayDefinition - методы ](kscircularpartarraydefinition_methods.html) |  Scroll [ [ [ ](kscurvepartarraydefinition.html "К следующему разделу")](kscircularpartarraydefinition_methods.html "На уровень выше")](kscircularpartarraydefinition_setaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscircularpartarraydefinition.html)

Синтаксис Automation:

BOOL SetCopyParamAlongDir (long count,

double step,

BOOL factor,

BOOL dir);

Синтаксис COM:

BOOL SetCopyParamAlongDir (long count,

double step,

BOOL factor,

BOOL dir)

Входные параметры:

count | \- количество копий,  
---|---  
step | \- шаг,  
factor | \- признак полного шага,  
dir | \- направление.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
