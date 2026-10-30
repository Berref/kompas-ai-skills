# SetThinParam - Изменить параметры тонкой стенки элемента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеееный элемент вращения (Интерфейс ksBossRotatedDefinition, IBossRotatedDefinition) ](ksbossrotateddefinition.html) > [IBossRotatedDefinition - методы ](ksbossrotateddefinition_methods.html) |  Scroll [ [ [ ](ksbossrotateddefinition_thinparam.html "К следующему разделу")](ksbossrotateddefinition_methods.html "На уровень выше")](ksbossrotateddefinition_setsketch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossrotateddefinition.html)

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
