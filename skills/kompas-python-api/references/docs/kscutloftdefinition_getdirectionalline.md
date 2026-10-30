# GetDirectionalLine - Получить направляющую линию. Эскиз в котором лежит кривая

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент по сечениям (Интерфейсы ksCutLoftDefinition, ICutLoftDefinition) ](kscutloftdefinition.html) > [ICutLoftDefinition - методы ](kscutloftdefinition_methods.html) |  Scroll [ [ [ ](kscutloftdefinition_getloftparam.html "К следующему разделу")](kscutloftdefinition_methods.html "На уровень выше")](kscutloftdefinition_chooseparts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutloftdefinition.html)

Синтаксис Automation:

LPDISPATCH GetDirectionalLine();

Синтаксис COM:

LPENTITY GetDirectionalLine();

Возвращаемое значение:

| \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Примечание:

Если задана направляющая, то признак замкнутости траектории устанавливается автоматически, исходя из замкнутости направляющей.

Подразделы:

(отсутствуют)
