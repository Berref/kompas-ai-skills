# ChooseParts - Получить указатель на интерфейс для работы с областью применения для компонентов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Сечение плоскостью (Интерфейсы ksCutByPlaneDefinition, ICutByPlaneDefinition) ](kscutbyplanedefinition.html) > [ICutByPlaneDefinition - методы ](kscutbyplanedefinition_methods.html) |  Scroll [ [ [ ](kscutbyplanedefinition_getplane.html "К следующему разделу")](kscutbyplanedefinition_methods.html "На уровень выше")](kscutbyplanedefinition_choosebodies.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutbyplanedefinition.html)

Синтаксис Automation:

LPDISPATCH ChooseParts();

Синтаксис COM:

LPCHOOSEBODIES ChooseParts();

Возвращаемое значение:

| \- указатель на интерфейс для работы с областью применения для компонентов [ksChooseParts](kschooseparts.html) или [IChooseParts](kschooseparts.html).  
---|---  
  
Примечание.

Интерфейс можно получить только для операции в сборке.

Подразделы:

(отсутствуют)
