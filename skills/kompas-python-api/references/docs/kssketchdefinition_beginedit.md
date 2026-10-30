# BeginEdit - Войти в режим редактирования эскиза (ksDocument2D)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Эскиз (Интерфейсы ksSketchDefinition, ISketchDefinition) ](kssketchdefinition.html) > [ISketchDefinition - методы ](kssketchdefinition_methods.html) |  Scroll [ [ [ ](kssketchdefinition_endedit.html "К следующему разделу")](kssketchdefinition_methods.html "На уровень выше")](kssketchdefinition_addprojectionof.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssketchdefinition.html)

Синтаксис Automation:

LPDISPATCH BeginEdit();

Возвращаемое значение:

| \- указатель на интерфейс эскиза [ksDocument2D](ksdocument2d.html).  
---|---  
  
Синтаксис COM:

BOOL BeginEdit();

Возвращаемое значение:

TRUE | \- в случае успешного завершения (режим редактирования включен).  
---|---  
  
Примечание:

После редактирования необходимо вызвать функцию [EndEdit](kssketchdefinition_endedit.html).

Подразделы:

(отсутствуют)
