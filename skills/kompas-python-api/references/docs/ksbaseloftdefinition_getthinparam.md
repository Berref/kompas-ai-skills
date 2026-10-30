# GetThinParam - Получить параметры тонкой стенки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Основание — элемент по сечениям (Интерфейсы ksBaseLoftDefinition, IBaseLoftDefinition) ](ksbaseloftdefinition.html) > [IBaseLoftDefinition - методы ](ksbaseloftdefinition_methods.html) |  Scroll [ [ [ ](ksbaseloftdefinition_setloftparam.html "К следующему разделу")](ksbaseloftdefinition_methods.html "На уровень выше")](ksbaseloftdefinition_getloftparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbaseloftdefinition.html)

Синтаксис Automation:

BOOL GetThinParam (BOOL *thin,

short *thinType,

double *normalThickness,

double *reverseThickness);

Синтаксис COM:

BOOL GetThinParam (BOOL *thin,

short *thinType,

double *normalThickness,

double *reverseThickness);

Выходные параметры:

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
