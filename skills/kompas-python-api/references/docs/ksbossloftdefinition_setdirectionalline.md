# SetDirectionalLine - Установить направляющую линию. Эскиз в котором лежит кривая

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеенный элемент по сечениям (Интерфейсы ksBossLoftDefinition, IBossLoftDefinition) ](ksbossloftdefinition.html) > [IBossLoftDefinition - методы ](ksbossloftdefinition_methods.html) |  Scroll [ [ [ ](ksbossloftdefinition_setloftparam.html "К следующему разделу")](ksbossloftdefinition_methods.html "На уровень выше")](ksbossloftdefinition_getthinparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossloftdefinition.html)

Синтаксис Automation:

BOOL SetDirectionalLine (LPDISPATCH sketch);

Синтаксис COM:

BOOL SetDirectionalLine (LPENTITY sketch);

Входные параметры:

sketch | \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если задана направляющая, то признак замкнутости траектории устанавливается автоматически, исходя из замкнутости направляющей.

Подразделы:

(отсутствуют)
