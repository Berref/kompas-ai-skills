# SetThinParam - Установить параметры тонкой стенки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный кинематический элемент (Интерфейс ksCutEvolutionDefinition, ICutEvolutionDefinition) ](kscutevolutiondefinition.html) > [ICutEvolutionDefinition - методы ](kscutevolutiondefinition_methods.html) |  Scroll [ [ [ ](kscutevolutiondefinition_thinparam.html "К следующему разделу")](kscutevolutiondefinition_methods.html "На уровень выше")](kscutevolutiondefinition_setsketch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutevolutiondefinition.html)

Синтаксис Automation:

BOOL SetThinParam (BOOL thin,

short thinType,

double normalThickness,

double reverseThickness);

Синтаксис COM:

BOOL SetThinParam (BOOL thin,

BYTE thinType,

double normalThickness,

double reverseThickness);

Входные параметры:

thin | \- признак тонкостенной операции,  
---|---  
thinType | \- направление построения стенки,  
normalThickness | \- толщина стенки в прямом направлении,  
reverseThickness | \- толщина стенки в обратном направлении.  
  
[Типы направлений...](direction_type.html)

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
