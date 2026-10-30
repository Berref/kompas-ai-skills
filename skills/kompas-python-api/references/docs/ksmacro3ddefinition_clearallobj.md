# ClearAllObj - Удалить все вспомогательные объекты, сохраненные в макро

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition_destroy.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

BOOL ClearAllObj();

Синтаксис COM:

BOOL ClearAllObj();

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечания:

Объект - это вспомогательная информация, и визуально никак не отображается. Например, если создать болт как макро относительно какого-нибудь объекта (например отверстие - цилиндрическая поверхность), и запомнить это отверстие в макро болта, то при следующем редактирование можно получить сохранённый указатель на отверстие.

Подразделы:

(отсутствуют)
