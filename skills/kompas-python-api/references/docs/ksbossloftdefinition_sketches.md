# Sketches - Получить указатель на интерфейс массива эскизов элемента по сечениям

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеенный элемент по сечениям (Интерфейсы ksBossLoftDefinition, IBossLoftDefinition) ](ksbossloftdefinition.html) > [IBossLoftDefinition - методы ](ksbossloftdefinition_methods.html) |  Scroll [ [ [ ](ksbossloftdefinition_thinparam.html "К следующему разделу")](ksbossloftdefinition_methods.html "На уровень выше")](ksbossloftdefinition_setthinparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossloftdefinition.html)

Синтаксис Automation:

LPDISPATCH Sketches();

Синтаксис COM:

LPENTITYCOLLECTION Sketches();

Возвращаемое значение:

| \- указатель на интерфейс массива эскизов [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Примечание:

В массиве включен контроль, не позволяющий добавить в него нулевой указатель на эскиз.

Эскизы из данного массива используются для построения элемента по сечениям.

Подразделы:

(отсутствуют)
