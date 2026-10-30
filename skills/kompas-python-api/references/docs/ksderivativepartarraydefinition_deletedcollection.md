# DeletedCollection - Получить массив индексов удаленных копий

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по образцу (Интерфейсы ksDerivativePartArrayDefinition, IDerivativePartArrayDefinition) ](ksderivativepartarraydefinition.html) > [ksDerivativePartArrayDefinition - методы ](ksderivativepartarraydefinition_methods.html) |  Scroll [ [ [ ](ksderivativepartarraydefinition_getderiv.html "К следующему разделу")](ksderivativepartarraydefinition_methods.html "На уровень выше")](ksderivativepartarraydefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksderivativepartarraydefinition.html)

Синтаксис Automation:

LPDISPATCH DeletedCollection();

Синтаксис COM:

LPDELETEDCOPYCOLLECTION DeletedCollection();

Возвращаемое значение:

указатель на интерфейс [ksDeletedCopyCollection](ksdeletedcopycollection.html) или [IDeletedCopyCollection](ksdeletedcopycollection.html) | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Интерфейс применяется для массивов компонентов и операций копирования, для получения информации о удаленных копиях, а также управления составом удаленных копий. Информация о удаленной копии выдается в виде индексов копии в узоре копирования. В общем случае это два индекса по ортогональным осям в плоскости узора. Для копий по кривой используется один индекс (первый). Значения индексов начинаются с 1.

Подразделы:

(отсутствуют)
