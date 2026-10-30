# SetThinParam - Установить параметры тонкой стенки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Ребро жесткости (ksRibDefinition, IRibDefinition) ](ksribdefinition.html) > [ksRibDefinition - методы ](ksribdefinition_methods.html) |  Scroll [ [ [ ](ksribdefinition_thinparam.html "К следующему разделу")](ksribdefinition_methods.html "На уровень выше")](ksribdefinition_setsketch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksribdefinition.html)

Синтаксис Automation:

BOOL SetThinParam (short thinType,

double normalThickness,

double reverseThickness);

Синтаксис COM:

BOOL SetThinParam (BYTE thinType,

double normalThickness,

double reverseThickness);

Входные параметры:

thinType | \- направление построения стенки,  
---|---  
normalThickness | \- толщина стенки в прямом направлении,  
reverseThickness | \- толщина стенки в обратном направлении.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
[Типы направлений выдавливания..](direction_type.html)

Подразделы:

(отсутствуют)
