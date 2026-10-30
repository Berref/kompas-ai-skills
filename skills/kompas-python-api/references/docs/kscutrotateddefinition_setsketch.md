# SetSketch - Изменить указатель на интерфейс эскиза элемента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент вращения(ИнтерфейсыksCutRotatedDefinition, ICutRotatedDefinition) ](kscutrotateddefinition.html) > [ICutRotatedDefinition - методы ](kscutrotateddefinition_methods.html) |  Scroll [ [ [ ](kscutrotateddefinition_setthinparam.html "К следующему разделу")](kscutrotateddefinition_methods.html "На уровень выше")](kscutrotateddefinition_setsideparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutrotateddefinition.html)

Синтаксис Automation:

BOOL SetSketch(LPDISPATCH sketch);

Синтаксис COM:

BOOL SetSketch(LPENTITY sketch);

Входной параметр:

sketch | \- указатель на интерфейс эскиза [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
