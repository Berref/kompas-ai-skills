# SetThinParam - Изменить параметры тонкой стенки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеенный элемент по сечениям (Интерфейсы ksBossLoftDefinition, IBossLoftDefinition) ](ksbossloftdefinition.html) > [IBossLoftDefinition - методы ](ksbossloftdefinition_methods.html) |  Scroll [ [ [ ](ksbossloftdefinition_sketches.html "К следующему разделу")](ksbossloftdefinition_methods.html "На уровень выше")](ksbossloftdefinition_setloftparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossloftdefinition.html)

Синтаксис Automation:

BOOL SetThinParam (BOOL thin,

short thinType,

double normalThickness,

double reverseThickness);

Синтаксис COM:

BOOL SetThinParam (BOOL thin,

short thinType,

double normalThickness,

double reverseThickness);

Входные параметры:

thin | \- признак тонкостенной операции,  
---|---  
thinType | \- направление построения тонкой стенки,  
normalThickness | \- толщина стенки в прямом направлении,  
reverseThickness | \- толщина стенки в обратном направлении.  
  
[Типы направлений...](direction_type.html)

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
