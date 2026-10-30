# UserSetPlacement - Перейти в режим указания пользователем нового положения эскиза на той же плоскости (или плоской грани), где он был расположен ранее

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Эскиз (Интерфейсы ksSketchDefinition, ISketchDefinition) ](kssketchdefinition.html) > [ISketchDefinition - методы ](kssketchdefinition_methods.html) |  Scroll [ [ [ ](kscutrotateddefinition.html "К следующему разделу")](kssketchdefinition_methods.html "На уровень выше")](kssketchdefinition_setplane.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssketchdefinition.html)

Синтаксис Automation:

BOOL UserSetPlacement (BSTR prompt);

Синтаксис COM:

BOOL UserSetPlacement (LPOLESTR prompt);

Входной параметр:

prompt | \- текст строки-подсказки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

После вызова этой функции запускается такой же режим, как после вызова в КОМПАС-3D команды Разместить эскиз.

Подразделы:

(отсутствуют)
